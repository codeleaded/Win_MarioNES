#ifndef WORLD_H
#define WORLD_H

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"


#define BLOCK_NONE							0
#define BLOCK_DIRT							1
#define BLOCK_GRAS							2
#define BLOCK_BRICK							3
#define BLOCK_CLOSE_QUEST_RP				4
#define BLOCK_CLOSE_QUEST_GP				5
#define BLOCK_CLOSE_QUEST_FF				6
#define BLOCK_COIN							7
#define BLOCK_PODEST						8
#define BLOCK_REDPILZ						9
#define BLOCK_GREENPILZ						10
#define BLOCK_OPEN_QUEST					11
#define BLOCK_FAKE							12
#define BLOCK_CHECK							13
#define BLOCK_VISITED						14
#define BLOCK_ZIEL							15
#define BLOCK_MIDDLE_ROHRE					16
#define BLOCK_UP_ROHRE						17
#define BLOCK_DOWN_ROHRE					18
#define BLOCK_FIRE_FLOWER					19
#define BLOCK_BURG_LAVA						20
#define BLOCK_BURG_ERDE						21
#define BLOCK_BURG_GRAS						22
#define BLOCK_OVER_ERDE						23
#define BLOCK_OVER_GRAS						24
#define BLOCK_OVER_UNVISITED_TILE			25
#define BLOCK_OVER_RED_TILE					26
#define BLOCK_OVER_VISITED_TILE				27
#define BLOCK_STAR_COIN						28	
#define BLOCK_STONE							29
#define BLOCK_STONE_BRICK					30
#define BLOCK_STONE_GRAS					31

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

typedef struct World World;

typedef struct Animation {
	AnimationType type;
	char bg;
	union {
		struct{
			Sprite sprite_img;
		};
		struct{
			unsigned short atlas_dx;
			unsigned short atlas_dy;
			Sprite atlas_img;
			SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int);
		};
		struct{
			Vector sprites_img;
			SubSprite (*sprites_get)(struct Animation*,World*,unsigned int,unsigned int);
		};
		struct{
			unsigned short aatlas_dx;
			unsigned short aatlas_dy;
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
Animation Animation_Make_Atlas(char* Path,char bg,unsigned short dx,unsigned short dy,SubSprite (*atlas_get)(struct Animation*,World*,unsigned int,unsigned int)){
	Animation a;
	a.type = ANIMATIONTYPE_ATLAS;
	a.bg = bg;
	a.atlas_img = Sprite_Load(Path);
	a.atlas_dx = dx;
	a.atlas_dy = dy;
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
Animation Animation_Make_AnimationAtlas(char* Path,char bg,unsigned short dx,unsigned short dy,FDuration aatlas_duration){
	Animation a;
	a.type = ANIMATIONTYPE_ANIMATIONATLAS;
	a.bg = bg;
	a.aatlas_img = Sprite_Load(Path);
	a.aatlas_dx = dx;
	a.aatlas_dy = dy;
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
			if(a->atlas_img.w != width || a->atlas_img.h != height){
				Sprite_Reload(&a->atlas_img,width,height);
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
			if(a->aatlas_img.w != width || a->aatlas_img.h != height){
				Sprite_Reload(&a->aatlas_img,width,height);
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
Block World_Std_Mapper(char c){
	switch (c){
	case '.': return BLOCK_NONE;
	case 'e': return BLOCK_DIRT;
	case 'g': return BLOCK_GRAS;
	case '#': return BLOCK_BRICK;
	case '!': return BLOCK_OPEN_QUEST;
	case '?': return BLOCK_CLOSE_QUEST_RP;
	case 'q': return BLOCK_CLOSE_QUEST_GP;
	case 'Q': return BLOCK_CLOSE_QUEST_FF;
	case 'o': return BLOCK_COIN;
	case 'p': return BLOCK_PODEST;
	case 'f': return BLOCK_FAKE;
	case 'c': return BLOCK_CHECK;
	case 'v': return BLOCK_VISITED;
	case 'z': return BLOCK_ZIEL;
	case 'm': return BLOCK_MIDDLE_ROHRE;
	case 'u': return BLOCK_UP_ROHRE;
	case 'd': return BLOCK_DOWN_ROHRE;
	case '0': return BLOCK_REDPILZ;
	case '1': return BLOCK_GREENPILZ;
	case '2': return BLOCK_FIRE_FLOWER;
	case 'L': return BLOCK_BURG_LAVA;
	case 'B': return BLOCK_BURG_ERDE;
	case '=': return BLOCK_BURG_GRAS;
	case 'E': return BLOCK_OVER_ERDE;
	case 'G': return BLOCK_OVER_GRAS;
	case 'U': return BLOCK_OVER_UNVISITED_TILE;
	case 'R': return BLOCK_OVER_RED_TILE;
	case 'V': return BLOCK_OVER_VISITED_TILE;
	case '@': return BLOCK_STAR_COIN;	
	case 's': return BLOCK_STONE;
	case 'b': return BLOCK_STONE_BRICK;
	case 'M': return BLOCK_STONE_GRAS;
	}
	return BLOCK_NONE;
}
void World_Load(World* w,char* Path,Block (*MapperFunc)(char c)){
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
	return BLOCK_NONE;
}
void World_Set(World* w,unsigned int x,unsigned int y,Block b){
	if(x<w->width && y<w->height) w->data[y * w->width + x] = b;
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
					const int img = (int)((p - F64_Floor(p)) * a->animation_img.size);
					return SubSprite_New(&a->aatlas_img,img * a->aatlas_dx,0.0f,a->aatlas_dx,a->aatlas_dy);
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
void World_RenderBg(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
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