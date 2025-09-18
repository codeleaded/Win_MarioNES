#ifndef WORLD_H
#define WORLD_H

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"
#include "/home/codeleaded/System/Static/Container/DataStream.h"


#define BLOCK_NONE							0
#define BLOCK_GRAS							1
#define BLOCK_BRICK							2
#define BLOCK_CLOSE_QUEST_FF				3
#define BLOCK_CLOSE_QUEST_SS				4
#define BLOCK_COIN							5
#define BLOCK_PODEST						6
#define BLOCK_SOLID							7
#define BLOCK_TUBE							8
#define BLOCK_SILVERTUBE					9
#define BLOCK_FIRE_FLOWER					10
#define BLOCK_SUPER_STAR					11
#define BLOCK_BUSH							12
#define BLOCK_CASTLE						13
#define BLOCK_CLOUD							14
#define BLOCK_FENCE							15
#define BLOCK_FLAG							16
#define BLOCK_GRASFAKE						17
#define BLOCK_TREE							18
#define BLOCK_SNOWTREE						19
#define BLOCK_BACKTREE						20
#define BLOCK_BOUNDS						255

typedef unsigned char Block;
typedef unsigned char AnimationType;

#define ANIMATIONTYPE_NONE 					0
#define ANIMATIONTYPE_SPRITE 				1
#define ANIMATIONTYPE_ATLAS   				2
#define ANIMATIONTYPE_SPRITES   			3
#define ANIMATIONTYPE_ANIMATIONATLAS   		4
#define ANIMATIONTYPE_ANIMATION   			5

#define ANIMATIONBG_FG 						0
#define ANIMATIONBG_BG 						1

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


typedef struct World World;

typedef struct Animation {
	AnimationType type;
	char bg;
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

Animation Animation_New(AnimationType type,char bg){
	Animation a;
	memset(&a,0,sizeof(a));
	a.type = type;
	a.bg = bg;
	return a;
}
Animation Animation_Make_Sprite(char* Path,char bg){
	Animation a;
	a.type = ANIMATIONTYPE_SPRITE;
	a.bg = bg;
	a.sprite_img = Sprite_Load(Path);
	return a;
}
Animation Animation_Make_Atlas(char* Path,char bg,unsigned short cx,unsigned short cy,SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Animation a;
	a.type = ANIMATIONTYPE_ATLAS;
	a.bg = bg;
	a.atlas_img = Sprite_Load(Path);
	a.atlas_cx = cx;
	a.atlas_cy = cy;
	a.atlas_get = atlas_get;
	return a;
}
Animation Animation_Make_Sprites(char** Paths,char bg,SubSprite (*sprites_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Animation a;
	a.type = ANIMATIONTYPE_SPRITES;
	a.bg = bg;
	a.sprites_img = Vector_New(sizeof(Sprite));
	a.sprites_get = sprites_get;

	for(int i = 0;Paths[i];i++){
		Vector_Push(&a.sprites_img,(Sprite[]){ Sprite_Load(Paths[i]) });
	}

	return a;
}
Animation Animation_Make_AnimationAtlas(char* Path,char bg,unsigned short cx,unsigned short cy,FDuration aatlas_duration){
	Animation a;
	a.type = ANIMATIONTYPE_ANIMATIONATLAS;
	a.bg = bg;
	a.aatlas_img = Sprite_Load(Path);
	a.aatlas_cx = cx;
	a.aatlas_cy = cy;
	a.aatlas_start = Time_Nano();
	a.aatlas_duration = aatlas_duration;
	return a;
}
Animation Animation_Make_Animation(char** Paths,char bg,FDuration animation_duration){
	Animation a;
	a.type = ANIMATIONTYPE_ANIMATION;
	a.bg = bg;
	a.animation_img = Vector_New(sizeof(Sprite));
	a.animation_start = Time_Nano();
	a.animation_duration = animation_duration;

	for(int i = 0;Paths[i];i++){
		Vector_Push(&a.animation_img,(Sprite[]){ Sprite_Load(Paths[i]) });
	}

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
	a->type = ANIMATIONTYPE_NONE;
}


typedef struct World{
	Vector animations;//Vector<Animation>
	Block* data;
	unsigned short width;
	unsigned short height;
} World;

World World_New(unsigned short width,unsigned short height){
	World w;
	w.animations = Vector_New(sizeof(Animation));
	w.data = (Block*)malloc(sizeof(Block) * width * height);
	w.width = width;
	w.height = height;
	return w;
}
void World_Load(World* w,char* Path,Block (*MapperFunc)(char)){
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
World World_Make(char* Path,Block (*MapperFunc)(char c),Animation* a){
	World w;
	w.animations = Vector_New(sizeof(Animation));
	w.data = NULL;
	w.width = 0;
	w.height = 0;

	World_Load(&w,Path,MapperFunc);

	for(int i = 0;a[i].type != ANIMATIONTYPE_NONE;i++){
		Vector_Push(&w.animations,a + i);
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
char World_isBg(World* w,Block b){
	if(b!=BLOCK_NONE){
		if(b<w->animations.size){
			Animation* a = (Animation*)Vector_Get(&w->animations,b);
			return a->bg;
		}
	}
	return 0;
}
SubSprite World_Img(World* w,Block b,unsigned int x,unsigned int y){
	if(b!=BLOCK_NONE){
		if(b<w->animations.size){
			Animation* a = (Animation*)Vector_Get(&w->animations,b);
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
	}
	return SubSprite_Null();
}
SubSprite World_Get_Img(World* w,unsigned int x,unsigned int y){
	const Block b = World_Get(w,x,y);
	return World_Img(w,b,x,y);
}
void World_Resize(World* w,unsigned int width,unsigned int height){
	for(int i = 0;i<w->animations.size;i++){
		Animation* a = (Animation*)Vector_Get(&w->animations,i);
		Animation_Resize(a,width,height);
	}
}
void World_RenderFg(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });
	const Vec2 sd = TransformedView_WorldScreenLength(tv,(Vec2){ 1.0f,1.0f });
	
	for(int y = tl.y;y<br.y;y++){
		for(int x = tl.x;x<br.x;x++){
			const Block b = World_Get(w,x,y);

			if(b!=BLOCK_NONE && World_isBg(w,b)){
				const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ x,y });
				SubSprite ss = World_Get_Img(w,x,y);
				if(ss.sp)
					RenderSubSpriteAlpha(ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}
}
void World_RenderBg(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });
	const Vec2 sd = TransformedView_WorldScreenLength(tv,(Vec2){ 1.0f,1.0f });

	World_Resize(w,(unsigned int)F32_Ceil(sd.x),(unsigned int)F32_Ceil(sd.y));
	
	for(int y = tl.y;y<br.y;y++){
		for(int x = tl.x;x<br.x;x++){
			const Block b = World_Get(w,x,y);
			
			if(b!=BLOCK_NONE && !World_isBg(w,b)){
				const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ x,y });
				SubSprite ss = World_Get_Img(w,x,y);
				if(ss.sp)
					RenderSubSpriteAlpha(ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}
}
void World_Free(World* w){
	for(int i = 0;i<w->animations.size;i++){
		Animation* s = (Animation*)Vector_Get(&w->animations,i);
		Animation_Free(s);
	}
	Vector_Free(&w->animations);
	
	if(w->data) free(w->data);
	w->data = NULL;
}

#endif