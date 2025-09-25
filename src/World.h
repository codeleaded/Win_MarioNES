#ifndef WORLD_H
#define WORLD_H

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"
#include "/home/codeleaded/System/Static/Library/Integer.h"
#include "/home/codeleaded/System/Static/Container/DataStream.h"


#define BLOCK_NONE							0U
#define BLOCK_BOUNDS						255U

#define ENTITY_NONE							0U

typedef unsigned char Block;
typedef unsigned char AnimationType;
typedef unsigned char AnimationBg;
typedef unsigned short SpawnType;

#define ANIMATIONTYPE_NONE 					0
#define ANIMATIONTYPE_SPRITE 				1
#define ANIMATIONTYPE_ATLAS   				2
#define ANIMATIONTYPE_SPRITES   			3
#define ANIMATIONTYPE_ANIMATIONATLAS   		4
#define ANIMATIONTYPE_ANIMATION   			5

#define ANIMATIONBG_NONE 					0
#define ANIMATIONBG_BG 						1
#define ANIMATIONBG_FG 						2
#define ANIMATIONBG_ALL 					3
#define ANIMATIONBG_DG 						4

#define WORLD_NEIGHBOUR_NONE 				0
#define WORLD_NEIGHBOUR_TOP_LEFT 			1
#define WORLD_NEIGHBOUR_TOP_MID 			2
#define WORLD_NEIGHBOUR_TOP_RIGHT 			3
#define WORLD_NEIGHBOUR_MID_LEFT 			4
#define WORLD_NEIGHBOUR_MID_RIGHT 			5
#define WORLD_NEIGHBOUR_BOTTOM_LEFT 		6
#define WORLD_NEIGHBOUR_BOTTOM_MID 			7
#define WORLD_NEIGHBOUR_BOTTOM_RIGHT 		8

unsigned char World_Neighbour_Mask(unsigned char* bits){
	unsigned char mask = 0U;
	for(int i = 0;bits[i] != WORLD_NEIGHBOUR_NONE && bits[i] < 9;i++){
		mask |= 1 << (bits[i] - 1);
	}
	return mask;
}


typedef struct TargetRect {
	Rect r;
	Vec2* t;
} TargetRect;

int TargetRect_Compare(const void* e1,const void* e2) {
	TargetRect* r1 = (TargetRect*)e1;
	TargetRect* r2 = (TargetRect*)e2;
    float d1 = Vec2_Mag(Vec2_Sub(r1->r.p,*r1->t));
    float d2 = Vec2_Mag(Vec2_Sub(r2->r.p,*r2->t));
    return d1 == d2 ? 0 : (d1 < d2 ? -1 : 1);
}



typedef struct World World;

typedef struct Animation {
	AnimationType type;
	char bg;
	SpawnType spawner;
	union {
		struct{
			Sprite sprite_img;
		};
		struct{
			unsigned short atlas_cx;
			unsigned short atlas_cy;
			Sprite atlas_img;
			SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int);
		};
		struct{
			Vector sprites_img;
			SubSprite (*sprites_get)(struct Animation*,World*,unsigned int,unsigned int);
		};
		struct{
			unsigned short aatlas_cx;
			unsigned short aatlas_cy;
			Sprite aatlas_img;
			Timepoint aatlas_start;
			FDuration aatlas_duration;
		};
		struct{
			Vector animation_img;
			Timepoint animation_start;
			FDuration animation_duration;
		};
	};
} Animation;

Animation Animation_New(AnimationType type,char bg,SpawnType spawner){
	Animation a;
	memset(&a,0,sizeof(a));
	a.type = type;
	a.bg = bg;
	a.spawner = spawner;
	return a;
}
Animation Animation_Make_Sprite(char* Path,char bg,SpawnType spawner){
	Animation a;
	a.type = ANIMATIONTYPE_SPRITE;
	a.bg = bg;
	a.spawner = spawner;
	a.sprite_img = Sprite_Load(Path);
	return a;
}
Animation Animation_Make_Atlas(char* Path,char bg,SpawnType spawner,unsigned short cx,unsigned short cy,SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Animation a;
	a.type = ANIMATIONTYPE_ATLAS;
	a.bg = bg;
	a.spawner = spawner;
	a.atlas_img = Sprite_Load(Path);
	a.atlas_cx = cx;
	a.atlas_cy = cy;
	a.atlas_get = atlas_get;
	return a;
}
Animation Animation_Make_Sprites(char** Paths,char bg,SpawnType spawner,SubSprite (*sprites_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Animation a;
	a.type = ANIMATIONTYPE_SPRITES;
	a.bg = bg;
	a.spawner = spawner;
	a.sprites_img = Vector_New(sizeof(Sprite));
	a.sprites_get = sprites_get;

	for(int i = 0;Paths[i];i++){
		Vector_Push(&a.sprites_img,(Sprite[]){ Sprite_Load(Paths[i]) });
	}

	return a;
}
Animation Animation_Make_AnimationAtlas(char* Path,char bg,SpawnType spawner,unsigned short cx,unsigned short cy,FDuration aatlas_duration){
	Animation a;
	a.type = ANIMATIONTYPE_ANIMATIONATLAS;
	a.bg = bg;
	a.spawner = spawner;
	a.aatlas_img = Sprite_Load(Path);
	a.aatlas_cx = cx;
	a.aatlas_cy = cy;
	a.aatlas_start = Time_Nano();
	a.aatlas_duration = aatlas_duration;
	return a;
}
Animation Animation_Make_Animation(char** Paths,char bg,SpawnType spawner,FDuration animation_duration){
	Animation a;
	a.type = ANIMATIONTYPE_ANIMATION;
	a.bg = bg;
	a.spawner = spawner;
	a.animation_img = Vector_New(sizeof(Sprite));
	a.animation_start = Time_Nano();
	a.animation_duration = animation_duration;

	for(int i = 0;Paths[i];i++){
		Vector_Push(&a.animation_img,(Sprite[]){ Sprite_Load(Paths[i]) });
	}

	return a;
}

Animation Animation_Make_SpritePath(char* path,char* file,char bg,SpawnType spawner){
	CStr fullpath = CStr_Concat(path,file);
	Animation a = Animation_Make_Sprite(fullpath,bg,spawner);
	CStr_Free(&fullpath);
	return a;
}
Animation Animation_Make_AtlasPath(char* path,char* file,char bg,SpawnType spawner,unsigned short cx,unsigned short cy,SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int)){
	CStr fullpath = CStr_Concat(path,file);
	Animation a = Animation_Make_Atlas(fullpath,bg,spawner,cx,cy,atlas_get);
	CStr_Free(&fullpath);
	return a;
}
Animation Animation_Make_SpritesPath(char* path,char** files,char bg,SpawnType spawner,SubSprite (*sprites_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Vector fullpaths = Vector_New(sizeof(CStr));
	for(int i = 0;files[i];i++)
		Vector_Push(&fullpaths,(CStr[]){ CStr_Concat(path,files[i]) });
	Vector_Push(&fullpaths,(CStr){ NULL });
	
	Animation a = Animation_Make_Sprites((CStr*)fullpaths.Memory,bg,spawner,sprites_get);
	
	for(int i = 0;i<fullpaths.size - 1;i++)
		CStr_Free((CStr*)Vector_Get(&fullpaths,i));
	Vector_Free(&fullpaths);
	
	return a;
}
Animation Animation_Make_AnimationAtlasPath(char* path,char* file,char bg,SpawnType spawner,unsigned short cx,unsigned short cy,FDuration aatlas_duration){
	CStr fullpath = CStr_Concat(path,file);
	Animation a = Animation_Make_AnimationAtlas(fullpath,bg,spawner,cx,cy,aatlas_duration);
	CStr_Free(&fullpath);
	return a;
}
Animation Animation_Make_AnimationPath(char* path,char** files,char bg,SpawnType spawner,FDuration animation_duration){
	Vector fullpaths = Vector_New(sizeof(CStr));
	for(int i = 0;files[i];i++)
		Vector_Push(&fullpaths,(CStr[]){ CStr_Concat(path,files[i]) });
	Vector_Push(&fullpaths,(CStr){ NULL });
	
	Animation a = Animation_Make_Animation((CStr*)fullpaths.Memory,bg,spawner,animation_duration);
	
	for(int i = 0;i<fullpaths.size - 1;i++)
		CStr_Free((CStr*)Vector_Get(&fullpaths,i));
	Vector_Free(&fullpaths);
	return a;
}

Animation Animation_Null(){
	Animation a;
	memset(&a,0,sizeof(a));
	return a;
}
void Animation_Resize(Animation* a,unsigned int width,unsigned int height){
	switch(a->type){
		case ANIMATIONTYPE_NONE:
			break;
		case ANIMATIONTYPE_SPRITE:{
			if(a->sprite_img.w != width || a->sprite_img.h != height){
				Sprite_Reload(&a->sprite_img,width,height);
			}
			break;
		}
		case ANIMATIONTYPE_ATLAS:{
			const unsigned int w = a->atlas_img.w / a->atlas_cx;
			const unsigned int h = a->atlas_img.h / a->atlas_cy;
			if(w != width || w != height){
				Sprite_Reload(&a->atlas_img,width * a->atlas_cx,height * a->atlas_cy);
			}
			break;
		}
		case ANIMATIONTYPE_SPRITES:{
			for(int i = 0;i<a->sprites_img.size;i++){
				Sprite* s = (Sprite*)Vector_Get(&a->sprites_img,i);

				if(s->w != width || s->h != height){
					Sprite_Reload(s,width,height);
				}
			}
			break;
		}
		case ANIMATIONTYPE_ANIMATIONATLAS:{
			const unsigned int w = a->aatlas_img.w / a->aatlas_cx;
			const unsigned int h = a->aatlas_img.h / a->aatlas_cy;
			if(w != width || w != height){
				Sprite_Reload(&a->aatlas_img,width * a->aatlas_cx,height * a->aatlas_cy);
			}
			break;
		}
		case ANIMATIONTYPE_ANIMATION:{
			for(int i = 0;i<a->animation_img.size;i++){
				Sprite* s = (Sprite*)Vector_Get(&a->animation_img,i);

				if(s->w != width || s->h != height){
					Sprite_Reload(s,width,height);
				}
			}
			break;
		}
		default:
			break;
	}
}
void Animation_Free(Animation* a){
	switch(a->type){
		case ANIMATIONTYPE_NONE:
			break;
		case ANIMATIONTYPE_SPRITE:{
			Sprite_Free(&a->sprite_img);
			break;
		}
		case ANIMATIONTYPE_ATLAS:{
			Sprite_Free(&a->atlas_img);
			a->atlas_get = NULL;
			break;
		}
		case ANIMATIONTYPE_SPRITES:{
			for(int i = 0;i<a->sprites_img.size;i++){
				Sprite* s = (Sprite*)Vector_Get(&a->sprites_img,i);
				Sprite_Free(s);
			}
			Vector_Free(&a->sprites_img);
			a->sprites_get = NULL;
			break;
		}
		case ANIMATIONTYPE_ANIMATIONATLAS:{
			Sprite_Free(&a->aatlas_img);
			break;
		}
		case ANIMATIONTYPE_ANIMATION:{
			for(int i = 0;i<a->animation_img.size;i++){
				Sprite* s = (Sprite*)Vector_Get(&a->animation_img,i);
				Sprite_Free(s);
			}
			Vector_Free(&a->animation_img);
			break;
		}
		default:
			break;
	}
	a->bg = -1;
	a->spawner = 0U;
	a->type = ANIMATIONTYPE_NONE;
}


typedef struct EntityAtlas {
	Sprite atlas;
	unsigned int cx;
	unsigned int cy;
	void (*Update)(void*,float);
	SubSprite (*GetRender)(void*,struct EntityAtlas*);
	void (*Free)(void*);
} EntityAtlas;

EntityAtlas EntityAtlas_New(
	char* path,
	char* file,
	unsigned int cx,
	unsigned int cy,
	void (*Update)(void*,float),
	SubSprite (*GetRender)(void*,EntityAtlas*),
	void (*Free)(void*)
){
	EntityAtlas ea;
	
	CStr fullpath = CStr_Concat(path,file);
	ea.atlas = Sprite_Load(fullpath);
	CStr_Free(&fullpath);

	ea.cx = cx;
	ea.cy = cy;
	ea.Update = Update;
	ea.GetRender = GetRender;
	ea.Free = Free;
	return ea;
}
EntityAtlas EntityAtlas_Null(){
	EntityAtlas ea;
	ea.atlas = Sprite_None();
	ea.cx = 0U;
	ea.cy = 0U;
	ea.Update = NULL;
	ea.GetRender = NULL;
	ea.Free = NULL;
	return ea;
}
void EntityAtlas_Resize(EntityAtlas* ea,int width,int height){
	unsigned int dx = ea->cx * width;
	unsigned int dy = ea->cy * height;
	Sprite_Reload(&ea->atlas,dx,dy);
}
void EntityAtlas_Free(EntityAtlas* ea){
	Sprite_Free(&ea->atlas);
	ea->Update = NULL;
	ea->GetRender = NULL;
	ea->Free = NULL;
}


// abstract => inherite id and override methods
typedef struct Entity {
	unsigned int id;
	unsigned int padd;
	Rect r;
	Vec2 v;
	Vec2 a;
	void (*WorldCollision)(struct Entity*,World*);
	char (*IsPickUp)(struct Entity*,World*,unsigned int,unsigned int);
	char (*IsCollision)(struct Entity*,World*,unsigned int,unsigned int,Side);
	void (*Collision)(struct Entity*,World*,unsigned int,unsigned int,Side);
	void (*EntityCollision)(struct Entity*,World*,struct Entity*,unsigned int,unsigned int,Side);
} Entity;

void Entity_Free(Entity* e){
	e->WorldCollision = NULL;
	e->IsPickUp = NULL;
	e->IsCollision = NULL;
	e->Collision = NULL;
	e->EntityCollision = NULL;
}


typedef struct World{
	Vector animations;//Vector<Animation>
	Vector entityatlas;//Vector<EntityAtlas>
	PVector entities;//Vector<Entity>
	AnimationBg mode;
	Vec2 spawn;
	Block* data;
	unsigned short width;
	unsigned short height;
} World;

World World_New(unsigned short width,unsigned short height){
	World w;
	w.animations = Vector_New(sizeof(Animation));
	w.entityatlas = Vector_New(sizeof(EntityAtlas));
	w.entities = PVector_New();
	w.mode = ANIMATIONBG_ALL;
	if(width * height > 0U) w.data = (Block*)malloc(sizeof(Block) * width * height);
	else 					w.data = NULL;
	w.width = width;
	w.height = height;
	return w;
}
void World_Load(World* w,char* Path,Block spawner,Block (*MapperFunc)(char)){
	FilesSize size;
	char* data = Files_ReadB(Path,&size);

	int width = CStr_Find(data,'\n');
	int height = CStr_CountOf(data,'\n');

	if(w->data) free(w->data);
	w->data = (Block*)malloc(sizeof(Block) * width * height);
	w->width = width;
	w->height = height;

	for(int i = 0;i<size;i++){
		int y = i / (width + 1);
		int x = i - y * (width + 1);
		int j = y * width + x;

		w->data[j] = MapperFunc(data[i]);
	}

	w->spawn = (Vec2){ 0.0f,0.0f };
	for(int y = 0;y<w->height;y++){
		for(int x = 0;x<w->width;x++){
			Block b = w->data[y * w->width + x];
			
			if(spawner == b){
				w->spawn.x = x;
				w->spawn.y = y;
			}
		}
	}
}
void World_Save(World* w,char* Path,char (*MapperFunc)(Block)){
	// + 1 for newline char
	FilesSize size = (sizeof(char) * w->width + 1) * w->height;
	char* data = (char*)malloc(size);

	for(unsigned int y = 0;y<w->height;y++){
		for(unsigned int x = 0;x<w->width;x++){
			int dst = y * (w->width + 1) + x;
			int src = y * w->width + x;
			data[dst] = MapperFunc(w->data[src]);
		}
		data[(y + 1) * (w->width + 1) - 1] = '\n';
	}

	Files_Write(Path,data,size);
	free(data);
}
void World_Start(World* w,void* (*Spawn)(Vec2,SpawnType,unsigned int*)){
	for(int i = 0;i<w->entities.size;i++){
		Entity* e = (Entity*)PVector_Get(&w->entities,i);
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
		if(ea) ea->Free(e);
	}
	PVector_Clear(&w->entities);

	if(Spawn){
		for(int y = 0;y<w->height;y++){
			for(int x = 0;x<w->width;x++){
				Block b = w->data[y * w->width + x];
				Animation* a = (Animation*)Vector_Get(&w->animations,b - 1);

				if(a && a->spawner > 0U){
					unsigned int size = 0U;
					void* e = Spawn((Vec2){ x,y },a->spawner,&size);
					if(e){
						PVector_Push(&w->entities,e,size);
						free(e);
						//w->data[y * w->width + x] = BLOCK_NONE;
					}
				}
			}
		}
	}
}
World World_Make(char* Path,Block spawner,Block (*MapperFunc)(char c),Animation* a,EntityAtlas* ea){
	World w = World_New(0U,0U);

	World_Load(&w,Path,spawner,MapperFunc);

	for(int i = 0;a[i].type != ANIMATIONTYPE_NONE;i++){
		Vector_Push(&w.animations,a + i);
	}
	for(int i = 0;ea[i].atlas.img;i++){
		Vector_Push(&w.entityatlas,ea + i);
	}
	return w;
}
Block World_Get(World* w,unsigned int x,unsigned int y){
	if(x<w->width && y<w->height) return w->data[y * w->width + x];
	return BLOCK_BOUNDS;
}
unsigned char World_GetNeigbours(World* w,Block b,unsigned int x,unsigned int y){
	unsigned char nbs = 0U;
	int shift = 0;
	for(int i = 0;i<9;i++){
		if(i == 4) continue;
		const int px = i % 3;
		const int py = i / 3;
		Block got = World_Get(w,x - 1 + px,y - 1 + py);
		nbs |= (got == b || got == BLOCK_BOUNDS) << (shift++);
	}
	return nbs;
}
void World_Set(World* w,unsigned int x,unsigned int y,Block b){
	if(x<w->width && y<w->height)
		w->data[y * w->width + x] = b;
}
void* World_Spawn(World* w,SpawnType st,Vec2 p,void* (*Spawn)(Vec2,SpawnType,unsigned int*)){
	unsigned int size = 0U;
	void* e = Spawn(p,st,&size);
	if(e){
		PVector_Push(&w->entities,e,size);
		free(e);
		void* ret = PVector_Get(&w->entities,w->entities.size - 1);	
		return ret;
	}
	return NULL;
}
void World_Remove(World* w,Entity* e){
	for(int i = 0;i<w->entities.size;i++){
		Entity* te = (Entity*)PVector_Get(&w->entities,i);
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
		if(te == e){
			if(ea->Free) ea->Free(e);
			PVector_Remove(&w->entities,i);
			return;
		}
	}
}
void World_Resize(World* w,unsigned int width,unsigned int height){
	if(w->data){
		const unsigned int size = sizeof(Block) * width * height;
		Block* data = (Block*)malloc(size);
		memset(data,0,size);
	
		const unsigned int cpywidth = I64_Min(w->width,width);
		const unsigned int cpyheight = I64_Min(w->height,height);
		for(int y = 0;y<cpyheight;y++){
			memcpy(data + y * width,w->data + y * w->width,sizeof(Block) * cpywidth);
		}

		w->width = width;
		w->height = height;
		free(w->data);
		w->data = data;
	}
}
char World_isBlock(World* w,Block b){
	return b!=BLOCK_NONE && b - 1<w->animations.size;
}
char World_isVisible(World* w,Block b,AnimationBg state){
	if(World_isBlock(w,b)){
		Animation* a = (Animation*)Vector_Get(&w->animations,b - 1);
		
		return (
			(state == ANIMATIONBG_FG && (
				w->mode != ANIMATIONBG_DG &&
				a->bg == ANIMATIONBG_FG
			)) ||
			(state == ANIMATIONBG_BG && (
				(a->bg == ANIMATIONBG_BG) ||
				(w->mode == ANIMATIONBG_DG)
			))
		);
	}
	return 0;
}
SubSprite World_Img(World* w,Block b,unsigned int x,unsigned int y){
	if(World_isBlock(w,b)){
		Animation* a = (Animation*)Vector_Get(&w->animations,b - 1);
		switch(a->type){
			case ANIMATIONTYPE_NONE: 	return SubSprite_Null();
			case ANIMATIONTYPE_SPRITE:	return SubSprite_New(&a->sprite_img,0.0f,0.0f,a->sprite_img.w,a->sprite_img.h);
			case ANIMATIONTYPE_ATLAS:	return a->atlas_get(a,w,x,y);
			case ANIMATIONTYPE_SPRITES:	return a->sprites_get(a,w,x,y);
			case ANIMATIONTYPE_ANIMATIONATLAS:{
				const double t = Time_Nano() / (double)TIME_NANOTOSEC;
				const double p = (double)t / a->aatlas_duration;
				const int img = (int)((p - F64_Floor(p)) * a->aatlas_cx);
				const unsigned int dx = a->aatlas_img.w / a->aatlas_cx;
				const unsigned int dy = a->aatlas_img.h / a->aatlas_cy;
				return SubSprite_New(&a->aatlas_img,img * dx,0.0f,dx,dy);
			}
			case ANIMATIONTYPE_ANIMATION:{
				const double t = Time_Nano() / (double)TIME_NANOTOSEC;
				const double p = (double)t / a->animation_duration;
				const int img = (int)((p - F64_Floor(p)) * a->animation_img.size);
				Sprite* s = (Sprite*)Vector_Get(&a->animation_img,img);
				return SubSprite_New(s,0.0f,0.0f,s->w,s->h);
			}
			default:					return SubSprite_Null();
		}
	}
	return SubSprite_Null();
}
SubSprite World_Get_Img(World* w,unsigned int x,unsigned int y){
	const Block b = World_Get(w,x,y);
	return World_Img(w,b,x,y);
}
void World_Reload(World* w,unsigned int width,unsigned int height){
	for(int i = 0;i<w->animations.size;i++){
		Animation* a = (Animation*)Vector_Get(&w->animations,i);
		Animation_Resize(a,width,height);
	}
	for(int i = 0;i<w->entityatlas.size;i++){
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,i);
		EntityAtlas_Resize(ea,width,height);
	}
}
void World_Update(World* w,TransformedView* tv,float t){
	if(w->mode!=ANIMATIONBG_DG){
		for(int i = 0;i<w->entities.size;i++){
			Entity* e = (Entity*)PVector_Get(&w->entities,i);
			EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
			
			if(ea && TransformedView_inViewRect(tv,e->r))
				ea->Update(e,t);
		}
	}
}

void World_Collision(World* w,Entity* src){
	if(w->mode!=ANIMATIONBG_DG){
		Vector rects = Vector_New(sizeof(TargetRect));
		
		float searchX = F32_Max(2.0f,2.0f * src->r.d.x);
		float searchY = F32_Max(2.0f,2.0f * src->r.d.y);

		for(float x = -searchX;x<searchX;x+=1.0f) {
			for(float y = -searchY;y<searchY;y+=1.0f) {
				int sx = (int)(src->r.p.x + x);
				int sy = (int)(src->r.p.y + y);

    	        if(sy>=0 && sy<w->height && sx>=0 && sx<w->width) {
    	            Block b = World_Get(w,sx,sy);
    	            Rect br = { (Vec2){ sx,sy },(Vec2){ 1.0f,1.0f } };

					if(Overlap_Rect_Rect(src->r,br)){
						if(b!=BLOCK_NONE){
							Vector_Push(&rects,(TargetRect[]){ br,&src->r.p });
						}
					}
				}
			}
		}

		qsort(rects.Memory,rects.size,rects.ELEMENT_SIZE,TargetRect_Compare);

		for(int i = 0;i<rects.size;i++) {
    	    TargetRect* r = (TargetRect*)Vector_Get(&rects,i);

			Side s = Side_Rect_Rect(src->r,r->r);
			if((src->IsPickUp && !src->IsPickUp(src,w,r->r.p.x,r->r.p.y)) && (src->IsCollision && src->IsCollision(src,w,r->r.p.x,r->r.p.y,s))){
				Resolve_Rect_Rect_Side(&src->r,r->r,s);
				if(src->Collision) src->Collision(src,w,r->r.p.x,r->r.p.y,s);
			}
		}

		Vector_Free(&rects);

		if(src->WorldCollision) src->WorldCollision(src,w);
	}
}
void World_EntityCollision(World* w,Entity* src){
	if(w->mode!=ANIMATIONBG_DG){
		for(int i = 0;i<w->entities.size;i++) {
    	    Entity* e = (Entity*)PVector_Get(&w->entities,i);
			if(src == e) continue;
			
			if(Overlap_Rect_Rect(src->r,e->r)){
				Side s = Side_Rect_Rect(src->r,e->r);
				
				if(src->EntityCollision)
					src->EntityCollision(src,w,e,e->r.p.x,e->r.p.y,s);
			}
		}
	}
}

void World_Collisions(World* w,TransformedView* tv){
	for(int i = 0;i<w->entities.size;i++){
		Entity* e = (Entity*)PVector_Get(&w->entities,i);
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
		
		if(ea && TransformedView_inViewRect(tv,e->r)){
			World_EntityCollision(w,e);
			
			if(e == (Entity*)PVector_Get(&w->entities,i))
				World_Collision(w,e);
		}
	}
}
void World_RenderEntities(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	for(int i = 0;i<w->entities.size;i++){
		Entity* e = (Entity*)PVector_Get(&w->entities,i);
		
		if(!TransformedView_inViewRect(tv,e->r))
			continue;
		
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
		if(ea){
			const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ e->r.p.x,e->r.p.y });
			SubSprite ss = ea->GetRender(e,ea);
			if(ss.sp)
				Sprite_RenderSubAlpha(out,width,height,ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
		}
	}
}
void World_RenderFg(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });
	const Vec2 sd = TransformedView_WorldScreenLength(tv,(Vec2){ 1.0f,1.0f });
	
	for(int y = tl.y;y<br.y;y++){
		for(int x = tl.x;x<br.x;x++){
			const Block b = World_Get(w,x,y);

			if(b!=BLOCK_NONE && World_isVisible(w,b,ANIMATIONBG_FG)){
				const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ x,y });
				SubSprite ss = World_Get_Img(w,x,y);
				if(ss.sp)
					Sprite_RenderSubAlpha(out,width,height,ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}
}
void World_RenderBg(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });
	const Vec2 sd = TransformedView_WorldScreenLength(tv,(Vec2){ 1.0f,1.0f });

	World_Reload(w,(unsigned int)F32_Ceil(sd.x),(unsigned int)F32_Ceil(sd.y));
	
	for(int y = tl.y;y<br.y;y++){
		for(int x = tl.x;x<br.x;x++){
			const Block b = World_Get(w,x,y);
			
			if(b!=BLOCK_NONE && World_isVisible(w,b,ANIMATIONBG_BG)){
				const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ x,y });
				SubSprite ss = World_Get_Img(w,x,y);
				if(ss.sp)
					RenderSubSpriteAlpha(ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}
}
void World_Free(World* w){
	for(int i = 0;i<w->entities.size;i++){
		Entity* e = (Entity*)PVector_Get(&w->entities,i);
		EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,e->id - 1);
		if(ea) ea->Free(e);
	}
	PVector_Free(&w->entities);
	
	for(int i = 0;i<w->animations.size;i++){
		Animation* s = (Animation*)Vector_Get(&w->animations,i);
		Animation_Free(s);
	}
	Vector_Free(&w->animations);
	
	if(w->data) free(w->data);
	w->data = NULL;
}

#endif