//#define IMAGE_PNG_ONLY

#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Files.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"
#include "/home/codeleaded/System/Static/Library/Geometry.h"
#include "/home/codeleaded/System/Static/Library/AudioPlayer.h"
#include "/home/codeleaded/System/Static/Library/PS4_Controller.h"

#include "World.h"
#include "Figure.h"
#include "Mario.h"

MarioWorld world;
PS4_Controller ps4c;

void Setup(AlxWindow* w){
	AlxFont_Resize(&window.AlxFont,16,16);

	ps4c = PS4_Controller_New("/dev/input/by-id/usb-Sony_Interactive_Entertainment_Wireless_Controller-if03-event-joystick");
	world = MarioWorld_New("./data/World/Level0.txt","./data/Blocks/","./data/Entity/");
	MarioWorld_AudioPlayerStart(&world);
}
void Update(AlxWindow* w){
	PS4_Controller_Update(&ps4c);
	
	TransformedView_Output(&world.tv,(Vec2){ GetWidth(),GetHeight() });
	TransformedView_HandlePanZoom(&world.tv,window.Strokes,GetMouse());
	TransformedView_Border(&world.tv,(Rect){ { 0.0f,0.0f },{ world.world.width,world.world.height } });

	if(PS4_Controller_Key(&ps4c,PS4_CONTROLLER_HOME).PRESSED){
		w->Running = 0;
	}

	if(Stroke(ALX_KEY_Q).PRESSED){
		world.world.mode = world.world.mode==ANIMATIONBG_DG ? ANIMATIONBG_ALL : ANIMATIONBG_DG;
	}
	if(Stroke(ALX_KEY_1).PRESSED){
		if(world.selected>0U) world.selected--;
	}
	if(Stroke(ALX_KEY_2).PRESSED){
		world.selected++;
	}
	if(Stroke(ALX_KEY_7).PRESSED){
		if(world.level>0U){
			world.level--;
		}
	}
	if(Stroke(ALX_KEY_8).PRESSED){
		if(world.level<5U){
			world.level++;
		}
	}
	if(Stroke(ALX_KEY_9).PRESSED){
		CStr path = CStr_Format("./data/World/Level%d.txt",world.level);
		World_Load(&world.world,path,BLOCK_SPAWN,MarioWorld_Std_Mapper);
		CStr_Free(&path);
	}
	if(Stroke(ALX_KEY_0).PRESSED){
		CStr path = CStr_Format("./data/World/Level%d.txt",world.level);
		World_Save(&world.world,path,MarioWorld_Std_MapperR);
		CStr_Free(&path);
	}

	if(Stroke(ALX_KEY_Y).PRESSED){
		//CStr path = CStr_Format("./data/World/Level%d.txt",level);
		//World_Load(&world,path,World_Std_Mapper);
		//CStr_Free(&path);
		
		World_Start(&world.world,MarioWorld_Std_SpawnMapper);
		world.mario.e->r.p = world.world.spawn;
	}

	if(Stroke(ALX_KEY_J).PRESSED){
		World_Resize(&world.world,world.world.width - 1,world.world.height);
	}
	if(Stroke(ALX_KEY_N).PRESSED){
		World_Resize(&world.world,world.world.width + 1,world.world.height);
	}
	if(Stroke(ALX_KEY_K).PRESSED){
		World_Resize(&world.world,world.world.width,world.world.height - 1);
	}
	if(Stroke(ALX_KEY_M).PRESSED){
		World_Resize(&world.world,world.world.width,world.world.height + 1);
	}

	if(world.world.mode!=ANIMATIONBG_DG){
		world.mario.e->a.y = MARIO_ACC_GRAVITY;
		
		const signed int abs = PS4_Controller_Abs(&ps4c,PS4_CONTROLLER_LX);
		if(Stroke(ALX_KEY_A).DOWN) 									Figure_Move(&world.mario,-1.0f);
		else if(Stroke(ALX_KEY_D).DOWN) 							Figure_Move(&world.mario,1.0f);
		else if(abs >= 0 && abs < 128) 								Figure_Move(&world.mario,F32_Map(abs,0.0f,255.0f,-1.0f,1.0f));
		else if(abs >= 128) 										Figure_Move(&world.mario,F32_Map(abs,0.0f,255.0f,-1.0f,1.0f));
		else 														Figure_Move(&world.mario,0.0f);
		
		if(world.mario.e->id==ENTITY_MARIO && ((Mario*)world.mario.e)->ground){
			if(Stroke(ALX_KEY_W).PRESSED || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_X).PRESSED){
				world.mario.e->v.y = -MARIO_VEL_JP;
				AudioPlayer_Add(&world.ap,"./data/Sound/jump.wav");
			}
		}
		if(Stroke(ALX_KEY_W).DOWN || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_X).DOWN){
			//if(mario.v.y<0.0f)
			if(world.mario.e->id==ENTITY_MARIO)
				((Mario*)world.mario.e)->jumping = ENTITY_TRUE;
			//else 				mario.jumping = ENTITY_FALSE;
		}
		if(Stroke(ALX_KEY_S).PRESSED || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_TRI).PRESSED){
			//mario.e->v.y = MARIO_VEL_JP;
		}
		if(Stroke(ALX_KEY_S).DOWN || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_TRI).DOWN){
			if(world.mario.e->id==ENTITY_MARIO)
				((Mario*)world.mario.e)->stamp = ENTITY_TRUE;
		}else
			if(world.mario.e->id==ENTITY_MARIO)
				((Mario*)world.mario.e)->stamp = ENTITY_FALSE;
	}else{
		world.mario.e->a.y = 0.0f;
		((Mario*)world.mario.e)->dead = ENTITY_FALSE;

		if(Stroke(ALX_MOUSE_M).PRESSED){
			Vec2 p = TransformedView_ScreenWorldPos(&world.tv,(Vec2){ w->MouseX,w->MouseY });
			world.mario.e->r.p = p;
		}
		if(Stroke(ALX_MOUSE_L).DOWN){
			Vec2 p = TransformedView_ScreenWorldPos(&world.tv,(Vec2){ w->MouseX,w->MouseY });
			World_Set(&world.world,p.x,p.y,world.selected);
		}
		if(Stroke(ALX_MOUSE_R).DOWN){
			Vec2 p = TransformedView_ScreenWorldPos(&world.tv,(Vec2){ w->MouseX,w->MouseY });
			World_Set(&world.world,p.x,p.y,BLOCK_NONE);
		}
		
		if(Stroke(ALX_KEY_A).DOWN){
			if(world.mario.e->id==ENTITY_MARIO){
				if(world.mario.e->v.x>0.0f) 		((Mario*)world.mario.e)->reverse = ENTITY_TRUE;
			}
			if(((Mario*)world.mario.e)->ground)	world.mario.e->a.x = -MARIO_ACC_GRD;
			else								world.mario.e->a.x = -MARIO_ACC_AIR;
		}else if(Stroke(ALX_KEY_D).DOWN){
			if(world.mario.e->id==ENTITY_MARIO){
				if(world.mario.e->v.x<0.0f)			((Mario*)world.mario.e)->reverse = ENTITY_TRUE;
			}
			if(((Mario*)world.mario.e)->ground)	world.mario.e->a.x = MARIO_ACC_GRD;
			else 								world.mario.e->a.x = MARIO_ACC_AIR;
		}else{
			world.mario.e->v.x =  0.0f;
			world.mario.e->a.x =  0.0f;
		}
		
		if(Stroke(ALX_KEY_W).DOWN){
			world.mario.e->v.y = -MARIO_VEL_JP;
			if(world.mario.e->id==ENTITY_MARIO)
				((Mario*)world.mario.e)->jumping = ENTITY_TRUE;
		}else if(Stroke(ALX_KEY_S).DOWN){
			world.mario.e->v.y = MARIO_VEL_JP;
			if(world.mario.e->id==ENTITY_MARIO)
				((Mario*)world.mario.e)->jumping = ENTITY_TRUE;
		}else{
			world.mario.e->v.y = 0.0f;
			world.mario.e->a.y = 0.0f;
		}
	}

	World_Update(&world.world,w->ElapsedTime);
	World_Collisions(&world.world);

	Figure_Update(&world.mario,&world.world,w->ElapsedTime);
	Figure_Collision(&world.mario,&world.world);

	Clear(LIGHT_BLUE);

	World_RenderBg(&world.world,&world.tv,WINDOW_STD_ARGS);
	Figure_Render(&world.mario,&world.world,&world.tv,WINDOW_STD_ARGS);
	World_RenderEntities(&world.world,&world.tv,WINDOW_STD_ARGS);
	World_RenderFg(&world.world,&world.tv,WINDOW_STD_ARGS);

	// for(int i = 0;i<world.animations.size;i++){
	// 	Animation* a = (Animation*)Vector_Get(&world.animations,i);
	// 	Sprite* s = (Sprite*)Vector_Get(a,0);
	// 	String str = String_Format("S:%d,%d",s->w,s->h);
	// 	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,i * window.AlxFont.CharSizeY,WHITE);
	// 	String_Free(&str);
	// }

	if(world.world.mode==ANIMATIONBG_DG){
		const int preshow = 7;
		const Vec2 sd = TransformedView_WorldScreenLength(&world.tv,(Vec2){ 1.0f,1.0f });
		const float x = 10.0f;

		RenderRect((preshow >> 1) * (sd.x * 1.1f),0.0f,sd.x + 10.0f,sd.y + 10.0f,RED);

		for(int i = 0;i<preshow;i++){
			const Block b = world.selected + i - (preshow >> 1);

			if(World_isBlock(&world.world,b)){
				SubSprite ss = World_Img(&world.world,b,0.0f,0.0f);
				if(ss.sp) RenderSubSpriteAlpha(ss.sp,x + i * (ss.dx * 1.1f),5.0f,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}

	String str = String_Format("S:%d,%d | L:%d",window.Width,window.Height,world.level);
	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,0.0f,WHITE);
	String_Free(&str);
}
void Delete(AlxWindow* w){
	MarioWorld_Free(&world);
	PS4_Controller_Free(&ps4c);
}

int main(){
    if(Create("Mario",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}