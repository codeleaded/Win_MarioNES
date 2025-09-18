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


typedef struct Figure{
	Sprite img;
	Rect r;
	Vec2 v;
	Vec2 a;
	Vec2 spawn;
	Timepoint start;
	unsigned char lookdir;
	unsigned char ground;
	unsigned char jumping;
	unsigned char stamp;
	unsigned char reverse;
	unsigned char power;
	unsigned char dead;
} Figure;

char World_Figure_Block_IsPickUp(World* w,Figure* f,unsigned int x,unsigned int y);
char World_Figure_Block_IsCollision(World* w,Figure* f,unsigned int x,unsigned int y,Side s);
void World_Figure_Block_Collision(World* w,Figure* f,unsigned int x,unsigned int y,Side s);


Figure Figure_New(Vec2 p,Vec2 d){
	Figure f;
	f.img = Sprite_None();
	f.r = Rect_New(p,d);
	f.v = (Vec2){ 0.0f,0.0f };
	f.a = (Vec2){ 0.0f,FIGURE_ACC_GRAVITY };
	f.spawn = p;

	f.start = 0UL;

	f.lookdir = FIGURE_RIGHT;
	f.ground = FIGURE_FALSE;
	f.jumping = FIGURE_FALSE;
	f.stamp = FIGURE_FALSE;
	f.reverse = FIGURE_FALSE;
	f.power = 0;
	f.dead = FIGURE_FALSE;
	return f;
}
Figure Figure_Make(Vec2 p,Vec2 d,Sprite* s){
	Figure f = Figure_New(p,d);
	f.img = *s;
	return f;
}
void Figure_Respawn(Figure* f){
	f->r.p = f->spawn;
	f->a.x = 0.0f;
	f->v.x = 0.0f;
	f->v.y = 0.0f;
}
void Figure_Move(Figure* f,const float dir){//dir := [-1;1]
	if(dir < -0.2f){// min for clean acc
		if(f->v.x>0.0f) f->reverse = FIGURE_TRUE;
		if(f->ground) 	f->a.x = -FIGURE_ACC_GRD * F32_Abs(dir);
		else 			f->a.x = -FIGURE_ACC_AIR * F32_Abs(dir);
	}else if(dir > 0.2f){
		if(f->v.x<0.0f) f->reverse = FIGURE_TRUE;
		if(f->ground) 	f->a.x = FIGURE_ACC_GRD * F32_Abs(dir);
		else 			f->a.x = FIGURE_ACC_AIR * F32_Abs(dir);
	}else
		f->a.x = 0.0f;
}
void Figure_Update(Figure* f,const float t){
	f->a.x = F32_Clamp(f->a.x,-FIGURE_ACC_MAX,FIGURE_ACC_MAX);
	if(f->ground) 	f->v.x = F32_Clamp(f->v.x,-FIGURE_VEL_MAX_GRD,FIGURE_VEL_MAX_GRD);
	else			f->v.x = F32_Clamp(f->v.x,-FIGURE_VEL_MAX_AIR,FIGURE_VEL_MAX_AIR);

	if(f->v.x<0.0f) f->lookdir = FIGURE_LEFT;
	if(f->v.x>0.0f) f->lookdir = FIGURE_RIGHT;

	if(F32_Abs(f->v.x)>FIGURE_VEL_CLP){
		const float add = -F32_Sign(f->v.x) * (f->ground ? FIGURE_ACC_GGP : FIGURE_ACC_AGP) * t;
		f->v.x = F32_Passes(f->v.x,add,0.0f) ? 0.0f : f->v.x + add;
	}else
		f->v.x = 0.0f;

	f->v.x = f->v.x + F32_Krung(f->a.x,FIGURE_ACC_MAX) * t;
	f->v.y = f->v.y + f->a.y * t * (!f->jumping ? FIGURE_VEL_MUL : 1.0f);// && f->v.y<0.0f
	
	//f->v = Vec2_Add(f->v,Vec2_Mulf(f->a,t * (f->jumping ? 1.0f : 2.0f)));
	f->r.p = Vec2_Add(f->r.p,Vec2_Mulf(f->v,t));

	if(f->r.p.x < 0.0f) f->r.p.x = 0.0f;
	if(f->r.p.y < 0.0f) f->r.p.y = 0.0f;

	f->jumping = FIGURE_FALSE;
}
void Figure_Collision(Figure* f,World* w,int (*Rect_Rect_Compare)(const void*,const void*)){
	Vector rects = Vector_New(sizeof(Rect));
	
	float searchX = F32_Max(2.0f,2.0f * f->r.d.x);
	float searchY = F32_Max(2.0f,2.0f * f->r.d.y);

	for(float x = -searchX;x<searchX;x+=1.0f) {
		for(float y = -searchY;y<searchY;y+=1.0f) {
			int sx = (int)(f->r.p.x + x);
			int sy = (int)(f->r.p.y + y);
			
            if(sy>=0 && sy<w->height && sx>=0 && sx<w->width) {
                Block b = World_Get(w,sx,sy);
                Rect br = { (Vec2){ sx,sy },(Vec2){ 1.0f,1.0f } };

				if(Overlap_Rect_Rect(f->r,br)){
					if(b!=BLOCK_NONE){
						Vector_Push(&rects,&br);
					}
				}
			}
		}
	}
	
    f->ground = FIGURE_FALSE;
	
	qsort(rects.Memory,rects.size,rects.ELEMENT_SIZE,Rect_Rect_Compare);
	
	for(int i = 0;i<rects.size;i++) {
        Rect rect = *(Rect*)Vector_Get(&rects,i);
		
		Side s = Side_Rect_Rect(f->r,rect);
		if(!World_Figure_Block_IsPickUp(w,f,rect.p.x,rect.p.y) && World_Figure_Block_IsCollision(w,f,rect.p.x,rect.p.y,s)){
			Resolve_Rect_Rect_Side(&f->r,rect,s);

			if(s==SIDE_TOP) 					f->ground = FIGURE_TRUE;
			if(s==SIDE_TOP && f->v.y>0.0f) 		f->v.y = 0.0f;
			if(s==SIDE_BOTTOM && f->v.y<0.0f) 	f->v.y = 0.0f;
			if(s==SIDE_LEFT && f->v.x>0.0f) 	f->v.x = 0.0f;
			if(s==SIDE_RIGHT && f->v.x<0.0f) 	f->v.x = 0.0f;

			World_Figure_Block_Collision(w,f,rect.p.x,rect.p.y,s);
		}
	}

	Vector_Free(&rects);


	if(!f->dead && f->r.p.y>w->height){
		f->dead = FIGURE_TRUE;
		f->v.y = -FIGURE_VEL_DEAD;
		f->r.p.y = w->height - f->r.d.y;
	}
	if(f->dead && f->r.p.y>w->height){
		f->dead = FIGURE_FALSE;
		Figure_Respawn(f);
	}
}
Rect Figure_Get_Img(Figure* f){
	Rect r;
	r.d = (Vec2){ 1.0f,1.0f };
	
	if(f->dead)				r.p = (Vec2){ 2.0f,1.0f };
	else if(!f->ground){
		if(!f->stamp)		r.p = (Vec2){ 2.0f,0.0f };
		else 				r.p = (Vec2){ 1.0f,1.0f };
	}else if(f->stamp){
		if(f->v.x==0.0f)	r.p = (Vec2){ 1.0f,1.0f };
		else 				r.p = (Vec2){ 0.0f,1.0f };
	}
	else if(f->reverse)		r.p = (Vec2){ 3.0f,0.0f };
	else if(f->v.x==0.0f)	r.p = (Vec2){ 7.0f,0.0f };
	else{
		FDuration d = Time_Elapsed(f->start,Time_Nano());
		//d *= (F32_Abs(f->v.x) / F32_Max(FIGURE_VEL_MAX_GRD,FIGURE_VEL_MAX_AIR));
		d = d - F32_Floor(d);
		d *= F32_Abs(f->v.x) * 0.65f;
		d = d - F32_Floor(d);
		
		//printf("O: %f %f %d\n",F32_Abs(f->v.x),d,(int)(3.0f * d));
		r.p = (Vec2){ 4.0f + (int)(3.0f * d),0.0f };
	}

	if(f->power==1)			r.p.y = 2.0f + r.p.y * 2.0f;
	else if(f->power==2)	r.p.y = 6.0f + r.p.y * 2.0f;

	if(f->lookdir==FIGURE_RIGHT) r.p.x = 15.0f - r.p.x;
	return r;
}
void Figure_Resize(Figure* f,unsigned int w,unsigned int h){
	if(f->img.w != w || f->img.h != h){
		Sprite_Reload(&f->img,w * 16,h * 12);
	}
}
void Figure_Render(Figure* f,TransformedView* tv,Pixel* out,unsigned int w,unsigned int h){
	const Vec2 scp = TransformedView_WorldScreenPos(tv,(Vec2){ f->r.p.x,f->r.p.y });
	const Vec2 scd = TransformedView_WorldScreenLength(tv,(Vec2){ f->r.d.x,f->r.d.y });
	
	Figure_Resize(f,(unsigned int)F32_Ceil(scd.x),(unsigned int)F32_Ceil(scd.x));
	
	//printf("O: %d %d -> %d %d -> %d %d\n",f->img.w,f->img.h,(int)scd.x,(int)scd.y,f->img.w / (int)scd.x,f->img.h / (int)scd.y);

	Rect r = Figure_Get_Img(f);
	if(r.p.x>=0.0f && r.p.y>=0.0f)
		//RenderSpriteAlpha(&f->img,scp.x,scp.y);
		RenderSubSpriteAlpha(&f->img,scp.x,scp.y,r.p.x * (unsigned int)F32_Ceil(scd.x),r.p.y * (unsigned int)F32_Ceil(scd.x),r.d.x * (unsigned int)F32_Ceil(scd.x),r.d.y * (unsigned int)F32_Ceil(scd.y));

	f->stamp = FIGURE_FALSE;
	f->reverse = FIGURE_FALSE;
}
void Figure_Free(Figure* f){
	Sprite_Free(&f->img);
}

#endif