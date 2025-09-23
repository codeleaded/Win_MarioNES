#ifndef FIGURE_H
#define FIGURE_H

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"

#include "World.h"

// NES MOVEMENT
// #define FIGURE_ACC_GRD		7.0f
// #define FIGURE_ACC_AIR		5.0f
// #define FIGURE_ACC_MAX		100.0f
// #define FIGURE_ACC_GGP		20.0f
// #define FIGURE_ACC_AGP		2.0f
// #define FIGURE_VEL_MAX_GRD	8.0f
// #define FIGURE_VEL_MAX_AIR	10.0f
// #define FIGURE_VEL_CLP		0.01f
// #define FIGURE_VEL_JP 		20.0f
// #define FIGURE_VEL_DEAD 		25.0f
// #define FIGURE_VEL_MUL 		4.0f

#define FIGURE_ACC_GRAVITY	30.0f
#define FIGURE_ACC_GRD		7.0f
#define FIGURE_ACC_AIR		5.0f
#define FIGURE_ACC_MAX		100.0f
#define FIGURE_ACC_GGP		20.0f
#define FIGURE_ACC_AGP		2.0f
#define FIGURE_VEL_MAX_GRD	8.0f
#define FIGURE_VEL_MAX_AIR	10.0f
#define FIGURE_VEL_CLP		0.01f
#define FIGURE_VEL_JP 		17.5f
#define FIGURE_VEL_DEAD 	25.0f
#define FIGURE_VEL_MUL 		3.0f

#define FIGURE_FALSE		0
#define FIGURE_TRUE			1

#define FIGURE_LEFT			0
#define FIGURE_RIGHT		1


typedef struct Figure {
	Entity* e;
	void (*Update)(Figure*,const float);
	void (*Move)(Figure*,const float);
	void (*Free)(void*);
} Figure;
 

char World_Figure_Block_IsPickUp(World* w,Figure* f,unsigned int x,unsigned int y);
char World_Figure_Block_IsCollision(World* w,Figure* f,unsigned int x,unsigned int y,Side s);
void World_Figure_Block_Collision(World* w,Figure* f,unsigned int x,unsigned int y,Side s);

Figure Figure_New(
	void* e,
	void (*Update)(Figure*,const float),
	void (*Move)(Figure*,const float),
	void (*Free)(void*)
){
	Figure f;
	f.e = e;
	f.Update = Update;
	f.Move = Move;
	f.Free = Free;
	return f;
}
void Figure_Move(Figure* f,const float dir){//dir := [-1;1]
	if(f->Move) f->Move(f->e,dir);
}
void Figure_Update(Figure* f,const float t){
	if(f->Update) f->Update(f->e,t);
}
void Figure_Collision(Figure* f,World* w){
    World_Collision(w,f->e);
	World_EntityCollision(w,f->e);
}
void Figure_Render(Figure* f,World* w,TransformedView* tv,Pixel* out,unsigned int width,unsigned int height){
	const Vec2 tl = TransformedView_ScreenWorldPos(tv,(Vec2){ 0.0f,0.0f });
	const Vec2 br = TransformedView_ScreenWorldPos(tv,(Vec2){ width,height });
	const Rect r = { tl,br };

	//if(!Rect_Overlap(&r,&f->e->r))
	//	return;
		
	EntityAtlas* ea = (EntityAtlas*)Vector_Get(&w->entityatlas,f->e->id - 1);
	if(ea){
		const Vec2 sc = TransformedView_WorldScreenPos(tv,(Vec2){ f->e->r.p.x,f->e->r.p.y });
		SubSprite ss = ea->GetRender(f->e,ea);
		if(ss.sp)
			Sprite_RenderSubAlpha(out,width,height,ss.sp,sc.x,sc.y,ss.ox,ss.oy,ss.dx,ss.dy);
	}
}
void Figure_Free(Figure* f){
	if(f->Free) f->Free(f->e);
	free(f->e);
	f->e = NULL;
}

#endif