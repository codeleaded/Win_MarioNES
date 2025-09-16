//#define IMAGE_PNG_ONLY

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"
#include "/home/codeleaded/System/Static/Library/AudioPlayer.h"

#include "World.h"
#include "Figure.h"

Figure mario;
World world;
TransformedView tv;
AudioPlayer ap;


char World_Figure_Block_IsPickUp(World* w,Figure* f,unsigned int x,unsigned int y){
	Block b = World_Get(w,x,y);

	if(b==BLOCK_COIN){
		AudioPlayer_Add(&ap,"./data/Sound/coin.wav");
		World_Set(w,x,y,BLOCK_NONE);
		return 1;
	//}else if(b==BLOCK_STAR_COIN){
	//	AudioPlayer_Add(&ap,"./data/Sound/coin.wav");
	//	World_Set(w,x,y,BLOCK_NONE);
	//	return 1;
	//}else if(b==BLOCK_REDPILZ){
	//	AudioPlayer_Add(&ap,"./data/Sound/upgrade.wav");
	//	World_Set(w,x,y,BLOCK_NONE);
	//	f->power = 1;
	//	f->r.d.y = 1.8f;
	//	return 1;
	//}else if(b==BLOCK_GREENPILZ){
	//	AudioPlayer_Add(&ap,"./data/Sound/powerup.wav");
	//	World_Set(w,x,y,BLOCK_NONE);
	//	f->power = 0;
	//	f->r.d.y = 0.9f;
	//	return 1;
	}else if(b==BLOCK_FIRE_FLOWER){
		AudioPlayer_Add(&ap,"./data/Sound/upgrade.wav");
		World_Set(w,x,y,BLOCK_NONE);
		f->power = 2;
		f->r.d.y = 1.8f;
		return 1;
	}else if(b==BLOCK_SUPER_STAR){
		AudioPlayer_Add(&ap,"./data/Sound/powerup.wav");
		World_Set(w,x,y,BLOCK_NONE);
		//f->power = 3;
		//f->r.d.y = 1.8f;
		return 1;
	}
	return 0;
}
char World_Figure_Block_IsCollision(World* w,Figure* f,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(b==BLOCK_PODEST) return s==SIDE_TOP && f->v.y>0.0f;
	return 1;
}
void World_Figure_Block_Collision(World* w,Figure* f,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_BOTTOM || (s==SIDE_TOP && f->stamp && f->v.x==0.0f)){
		if(b==BLOCK_BRICK)
			World_Set(w,x,y,BLOCK_NONE);
		else if(b==BLOCK_CLOSE_QUEST_FF){
			World_Set(w,x,y,BLOCK_OPEN_QUEST);
			World_Set(w,x,y-1,BLOCK_FIRE_FLOWER);
		}else if(b==BLOCK_CLOSE_QUEST_SS){
			World_Set(w,x,y,BLOCK_OPEN_QUEST);
			World_Set(w,x,y-1,BLOCK_SUPER_STAR);
		}
	}
}
SubSprite Tube_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}
SubSprite Bush_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}
SubSprite Castle_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}
SubSprite Cloud_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}
SubSprite Fence_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}
SubSprite Flag_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;


	
	SubSprite ss;
	return ss;
}

int Rect_Rect_Compare(const void* e1,const void* e2) {
	Rect r1 = *(Rect*)e1;
	Rect r2 = *(Rect*)e2;
    float d1 = Vec2_Mag(Vec2_Sub(r1.p,mario.r.p));
    float d2 = Vec2_Mag(Vec2_Sub(r2.p,mario.r.p));
    return d1 == d2 ? 0 : (d1 < d2 ? -1 : 1);
}

void Setup(AlxWindow* w){
	AlxFont_Resize(&window.AlxFont,16,16);
	
	tv = TransformedView_New((Vec2){ GetHeight(),GetHeight() });
	TransformedView_Zoom(&tv,(Vec2){ 0.1f,0.1f });
	//TransformedView_Offset(&tv,(Vec2){ -0.5f,0.0f });
	TransformedView_Focus(&tv,&mario.r.p);

	ap = AudioPlayer_New();
	AudioPlayer_Start(&ap);

	world = World_Make("./data/World/Level1.txt",World_Std_Mapper,(Animation[]){
		Animation_Make_Sprite("./data/Blocks/Void.png",ANIMATIONBG_FG),
		Animation_Make_Sprite("./data/Blocks/Dirt.png",ANIMATIONBG_FG),
		Animation_Make_Sprite("./data/Blocks/Brick.png",ANIMATIONBG_FG),
		Animation_Make_AnimationAtlas("./data/Atlas/QuestionMark.png",ANIMATIONBG_FG,3,1,1.0),
		Animation_Make_AnimationAtlas("./data/Atlas/QuestionMark.png",ANIMATIONBG_FG,3,1,1.0),
		Animation_Make_AnimationAtlas("./data/Atlas/Coin.png",ANIMATIONBG_FG,4,1,1.0),
		Animation_Make_Sprite("./data/Blocks/Podest.png",ANIMATIONBG_FG),
		Animation_Make_Sprite("./data/Blocks/Open_Block.png",ANIMATIONBG_FG),
		Animation_Make_Atlas("./data/Atlas/Tubes.png",ANIMATIONBG_FG,8,4,Tube_Get),
		Animation_Make_AnimationAtlas("./data/Atlas/FireFlower.png",ANIMATIONBG_FG,4,2,1.0),
		Animation_Make_AnimationAtlas("./data/Atlas/SuperStar.png",ANIMATIONBG_FG,4,1,1.0),
		Animation_Make_Atlas("./data/Atlas/Bush.png",ANIMATIONBG_FG,4,1,Bush_Get),
		Animation_Make_Atlas("./data/Atlas/Castle.png",ANIMATIONBG_FG,4,1,Castle_Get),
		Animation_Make_Atlas("./data/Atlas/Cloud.png",ANIMATIONBG_FG,4,1,Cloud_Get),
		Animation_Make_Atlas("./data/Atlas/Fence.png",ANIMATIONBG_FG,4,1,Fence_Get),
		Animation_Make_Atlas("./data/Atlas/Flag.png",ANIMATIONBG_FG,4,1,Flag_Get),
		Animation_Null()
	});

	// mario = Figure_Make((Vec2){ 1.0f,25.0f },(Vec2){ 0.5f,1.8f },(Sprite[]){
	// 	Sprite_Load("./data/Sandra/Sandra1_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra1_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra2_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra2_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra3_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra3_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra4_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra4_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra5_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra5_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra0_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra0_l.png"),
	// 	Sprite_Load("./data/Sandra/Sandra0_r.png"),
	// 	Sprite_Load("./data/Sandra/Sandra0_l.png"),
	// 	Sprite_None()
	// });

	mario = Figure_Make((Vec2){ 1.0f,25.0f },(Vec2){ 0.9f,0.9f },(Sprite[]){
		//Sprite_Load("./data/Images/MarioAtlas.png"),
		Sprite_Load("./data/Atlas/MarioAtlas.png"),
	});
}
void Update(AlxWindow* w){
	TransformedView_Output(&tv,(Vec2){ GetWidth(),GetHeight() });
	TransformedView_HandlePanZoom(&tv,window.Strokes,GetMouse());
	TransformedView_Border(&tv,(Rect){ { 0.0f,0.0f },{ world.width,world.height } });


	if(Stroke(ALX_KEY_A).DOWN){
		if(mario.v.x>0.0f) 	mario.reverse = FIGURE_TRUE;

		if(mario.ground) 	mario.a.x = -FIGURE_ACC_GRD;
		else 				mario.a.x = -FIGURE_ACC_AIR;
	}else if(Stroke(ALX_KEY_D).DOWN){
		if(mario.v.x<0.0f) 	mario.reverse = FIGURE_TRUE;
		
		if(mario.ground) 	mario.a.x = FIGURE_ACC_GRD;
		else 				mario.a.x = FIGURE_ACC_AIR;
	}else
		mario.a.x =  0.0f;

	if(mario.ground){
		if(Stroke(ALX_KEY_W).PRESSED){
			mario.v.y = -FIGURE_VEL_JP;
			AudioPlayer_Add(&ap,"./data/Sound/jump.wav");
		}
	}
	if(Stroke(ALX_KEY_W).DOWN){
		//if(mario.v.y<0.0f)
		mario.jumping = FIGURE_TRUE;
		//else 				mario.jumping = FIGURE_FALSE;
	}
	if(Stroke(ALX_KEY_S).PRESSED){
		//mario.v.y = 0.0f;
	}
	if(Stroke(ALX_KEY_S).DOWN){
		mario.stamp = FIGURE_TRUE;
	}

	Figure_Update(&mario,w->ElapsedTime);
	Figure_Collision(&mario,&world,Rect_Rect_Compare);

	Clear(LIGHT_BLUE);

	World_RenderFg(&world,&tv,WINDOW_STD_ARGS);
	Figure_Render(&mario,&tv,WINDOW_STD_ARGS);
	World_RenderBg(&world,&tv,WINDOW_STD_ARGS);

	// for(int i = 0;i<world.animations.size;i++){
	// 	Animation* a = (Animation*)Vector_Get(&world.animations,i);
	// 	Sprite* s = (Sprite*)Vector_Get(a,0);
	// 	String str = String_Format("S:%d,%d",s->w,s->h);
	// 	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,i * window.AlxFont.CharSizeY,WHITE);
	// 	String_Free(&str);
	// }

	String str = String_Format("S:%d,%d",window.Width,window.Height);
	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,0.0f,WHITE);
	String_Free(&str);
}
void Delete(AlxWindow* w){
	AudioPlayer_Free(&ap);
	
	World_Free(&world);
	Figure_Free(&mario);
}

int main(){
    if(Create("Mario",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}