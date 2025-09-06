#ifndef WORLD_H
#define WORLD_H

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"


#define BLOCK_NONE					0
#define BLOCK_DIRT					1
#define BLOCK_GRAS					2
#define BLOCK_BRICK					3
#define BLOCK_CLOSE_QUEST_RP		4
#define BLOCK_CLOSE_QUEST_GP		5
#define BLOCK_CLOSE_QUEST_FF		6
#define BLOCK_COIN					7
#define BLOCK_PODEST				8
#define BLOCK_REDPILZ				9
#define BLOCK_GREENPILZ				10
#define BLOCK_OPEN_QUEST			11
#define BLOCK_FAKE					12
#define BLOCK_CHECK					13
#define BLOCK_VISITED				14
#define BLOCK_ZIEL					15
#define BLOCK_MIDDLE_ROHRE			16
#define BLOCK_UP_ROHRE				17
#define BLOCK_DOWN_ROHRE			18
#define BLOCK_FIRE_FLOWER			19
#define BLOCK_BURG_LAVA				20
#define BLOCK_BURG_ERDE				21
#define BLOCK_BURG_GRAS				22
#define BLOCK_OVER_ERDE				23
#define BLOCK_OVER_GRAS				24
#define BLOCK_OVER_UNVISITED_TILE	25
#define BLOCK_OVER_RED_TILE			26
#define BLOCK_OVER_VISITED_TILE		27
#define BLOCK_STAR_COIN				28	
#define BLOCK_STONE					29
#define BLOCK_STONE_BRICK			30
#define BLOCK_STONE_GRAS			31

typedef unsigned char Block;

typedef Vector Animation;

Animation Animation_New(){
	Animation a = Vector_New(sizeof(Sprite));
	return a;
}
Animation Animation_Make(char** Paths){
	Animation a = Animation_New();

	for(int i = 0;Paths[i];i++){
		Vector_Push(&a,(Sprite[]){ Sprite_Load(Paths[i]) });
	}

	return a;
}
Animation Animation_Single(char* Path){
	Animation a = Animation_New();
	Vector_Push(&a,(Sprite[]){ Sprite_Load(Path) });
	return a;
}
Animation Animation_Null(){
	Animation a = Vector_Null();
	return a;
}
void Animation_Resize(Animation* a,unsigned int width,unsigned int height){
	for(int i = 0;i<a->size;i++){
		Sprite* s = (Sprite*)Vector_Get(a,i);
		
		if(s->w != width || s->h != height){
			Sprite_Reload(s,width,height);
		}
	}
}
void Animation_Free(Animation* a){
	for(int i = 0;i<a->size;i++){
		Sprite* sp = (Sprite*)Vector_Get(a,i);
		Sprite_Free(sp);
	}
	Vector_Free(a);
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

	for(int i = 0;a[i].Memory;i++){
		Vector_Push(&w.animations,&a[i]);
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
Sprite* World_Img(World* w,Block b){
	if(b!=BLOCK_NONE){
		if(b<w->animations.size){
			Animation* a = (Animation*)Vector_Get(&w->animations,b);
			int t = ((Time_Nano() % TIME_NANOTOSEC) / 10000000ULL);
			float p = (float)t / 100.0f;
			int img = (int)(p * a->size);
			Sprite* s = (Sprite*)Vector_Get(a,img);
			return s;
		}
	}
	return NULL;
}
Sprite* World_Get_Img(World* w,unsigned int x,unsigned int y){
	const Block b = World_Get(w,x,y);
	return World_Img(w,b);
}
void World_Resize(World* w,unsigned int width,unsigned int height){
	for(int i = 0;i<w->animations.size;i++){
		Animation* a = (Animation*)Vector_Get(&w->animations,i);
		Animation_Resize(a,width,height);
	}
}
void World_Render(World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });

	const Vec2 sd = TransformedView_WorldScreenLength(tv,(Vec2){ 1.0f,1.0f });

	World_Resize(w,(unsigned int)F32_Ceil(sd.x),(unsigned int)F32_Ceil(sd.y));
	
	for(int y = tl.y;y<br.y;y++){
		for(int x = tl.x;x<br.x;x++){
			const Block b = World_Get(w,x,y);

			if(b!=BLOCK_NONE){
				const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ x,y });
				Sprite* s = World_Get_Img(w,x,y);
				if(s) RenderSpriteAlpha(s,sc.x,sc.y);
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