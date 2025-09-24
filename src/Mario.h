#ifndef MARIO_H
#define MARIO_H

#include "World.h"
#include "Figure.h"

#include "/home/codeleaded/System/Static/Library/AudioPlayer.h"

#define BLOCK_GRAS						1U
#define BLOCK_BRICK						2U
#define BLOCK_CLOSE_QUEST_FF			3U
#define BLOCK_CLOSE_QUEST_SS			4U
#define BLOCK_COIN						5U
#define BLOCK_PODEST					6U
#define BLOCK_SOLID						7U
#define BLOCK_TUBE						8U
#define BLOCK_SILVERTUBE				9U
#define BLOCK_FIRE_FLOWER				10U
#define BLOCK_SUPER_STAR				11U
#define BLOCK_BUSH						12U
#define BLOCK_CASTLE					13U
#define BLOCK_CLOUD						14U
#define BLOCK_FENCE						15U
#define BLOCK_FLAG						16U
#define BLOCK_GRASFAKE					17U
#define BLOCK_TREE						18U
#define BLOCK_SNOWTREE					19U
#define BLOCK_BACKTREE					20U
#define BLOCK_ROCKET					21U
#define BLOCK_SPAWN						22U
#define BLOCK_SPAWN_BOWLER				23U
#define BLOCK_SPAWN_BOWSER				24U
#define BLOCK_SPAWN_BRO					25U
#define BLOCK_SPAWN_COOPA				26U
#define BLOCK_SPAWN_EXPLOSION			27U
#define BLOCK_SPAWN_FIREBALL			28U
#define BLOCK_SPAWN_FIREBEAM			29U
#define BLOCK_SPAWN_FIREJUMPER			30U
#define BLOCK_SPAWN_FISH				31U
#define BLOCK_SPAWN_GUMBA				32U
#define BLOCK_SPAWN_HAMMER				33U
#define BLOCK_SPAWN_LAKITU				34U
#define BLOCK_SPAWN_PLANT				35U
#define BLOCK_SPAWN_PLANT_UG			36U
#define BLOCK_SPAWN_SPIKE				37U
#define BLOCK_SPAWN_SQUID				38U
#define BLOCK_SPAWN_WILLI				39U

#define ENTITY_MARIO					1U
#define ENTITY_BOWLER					2U
#define ENTITY_BOWSER					3U
#define ENTITY_BRO						4U
#define ENTITY_COOPA					5U
#define ENTITY_EXPLOSION				6U
#define ENTITY_FIREBALL					7U
#define ENTITY_FIREBEAM					8U
#define ENTITY_FIREJUMPER				9U
#define ENTITY_FISH						10U
#define ENTITY_GUMBA					11U
#define ENTITY_HAMMER					12U
#define ENTITY_LAKITU					13U
#define ENTITY_PLANT					14U
#define ENTITY_PLANT_UG					15U
#define ENTITY_SPIKE					16U
#define ENTITY_SQUID					17U
#define ENTITY_WILLI					18U

#define ENTITY_FALSE		            0
#define ENTITY_TRUE			            1

#define ENTITY_LEFT			            0
#define ENTITY_RIGHT		            1

#define MARIO_DIM_P0_X	                0.9f
#define MARIO_DIM_P0_Y	                0.9f
#define MARIO_DIM_P1_X	                0.9f
#define MARIO_DIM_P1_Y	                1.9f
#define MARIO_DIM_P2_X	                0.9f
#define MARIO_DIM_P2_Y	                1.9f
#define MARIO_DIM_P3_X	                0.9f
#define MARIO_DIM_P3_Y	                0.9f

#define BOWLER_DIM_X					0.9f
#define BOWLER_DIM_Y					0.9f
#define BOWSER_DIM_X					0.9f
#define BOWSER_DIM_Y					0.9f
#define BRO_DIM_X						0.9f
#define BRO_DIM_Y						0.9f
#define COOPA_DIM_X						0.9f
#define COOPA_DIM_Y						0.9f
#define EXPLOSION_DIM_X					0.9f
#define EXPLOSION_DIM_Y					0.9f
#define FIREBALL_DIM_X					0.9f
#define FIREBALL_DIM_Y					0.9f
#define FIREBEAM_DIM_X					0.9f
#define FIREBEAM_DIM_Y					0.9f
#define FIREJUMPER_DIM_X				0.9f
#define FIREJUMPER_DIM_Y				0.9f
#define FISH_DIM_X						0.9f
#define FISH_DIM_Y						0.9f
#define GUMBA_DIM_X						0.9f
#define GUMBA_DIM_Y						0.9f
#define HAMMER_DIM_X					0.9f
#define HAMMER_DIM_Y					0.9f
#define LAKITU_DIM_X					0.9f
#define LAKITU_DIM_Y					0.9f
#define PLANT_DIM_X						0.9f
#define PLANT_DIM_Y						0.9f
#define PLANT_UG_DIM_X					0.9f
#define PLANT_UG_DIM_Y					0.9f
#define SPIKE_DIM_X						0.9f
#define SPIKE_DIM_Y						0.9f
#define SQUID_DIM_X						0.9f
#define SQUID_DIM_Y						0.9f
#define WILLI_DIM_X						0.9f
#define WILLI_DIM_Y						0.9f

#define MARIO_ACC_GRAVITY	            30.0f
#define MARIO_ACC_GRAVITY	            30.0f
#define MARIO_ACC_GRD		            7.0f
#define MARIO_ACC_AIR		            5.0f
#define MARIO_ACC_MAX		            100.0f
#define MARIO_ACC_GGP		            20.0f
#define MARIO_ACC_AGP		            2.0f
#define MARIO_VEL_MAX_GRD	            8.0f
#define MARIO_VEL_MAX_AIR	            10.0f
#define MARIO_VEL_CLP		            0.01f
#define MARIO_VEL_JP 		            17.5f
#define MARIO_VEL_DEAD 	                25.0f
#define MARIO_VEL_MUL 		            3.0f



typedef struct Mario {
	Entity e;
	Vec2 spawn;
	Timepoint start;
	unsigned char lookdir;
	unsigned char ground;
	unsigned char jumping;
	unsigned char stamp;
	unsigned char reverse;
	unsigned char power;
	unsigned char dead;
} Mario;

void Mario_Move(Mario* m,const float dir){//dir := [-1;1]
	if(dir < -0.2f){// min for clean acc
		if(m->e.v.x>0.0f)   m->reverse = ENTITY_TRUE;
		if(m->ground) 	    m->e.a.x = -MARIO_ACC_GRD * F32_Abs(dir);
		else 			    m->e.a.x = -MARIO_ACC_AIR * F32_Abs(dir);
	}else if(dir > 0.2f){
		if(m->e.v.x<0.0f)   m->reverse = ENTITY_TRUE;
		if(m->ground) 	    m->e.a.x = MARIO_ACC_GRD * F32_Abs(dir);
		else 			    m->e.a.x = MARIO_ACC_AIR * F32_Abs(dir);
	}else
		m->e.a.x = 0.0f;
}
void Mario_Update(Mario* m,World* w,float t){
    m->e.a.x = F32_Clamp(m->e.a.x,-MARIO_ACC_MAX,MARIO_ACC_MAX);
	if(m->ground) 	m->e.v.x = F32_Clamp(m->e.v.x,-MARIO_VEL_MAX_GRD,MARIO_VEL_MAX_GRD);
	else			m->e.v.x = F32_Clamp(m->e.v.x,-MARIO_VEL_MAX_AIR,MARIO_VEL_MAX_AIR);

	if(m->e.v.x<0.0f) m->lookdir = ENTITY_LEFT;
	if(m->e.v.x>0.0f) m->lookdir = ENTITY_RIGHT;

	if(F32_Abs(m->e.v.x)>MARIO_VEL_CLP){
		const float add = -F32_Sign(m->e.v.x) * (m->ground ? MARIO_ACC_GGP : MARIO_ACC_AGP) * t;
		m->e.v.x = F32_Passes(m->e.v.x,add,0.0f) ? 0.0f : m->e.v.x + add;
	}else
		m->e.v.x = 0.0f;

	m->e.v.x = m->e.v.x + F32_Krung(m->e.a.x,MARIO_ACC_MAX) * t;
	m->e.v.y = m->e.v.y + m->e.a.y * t * (!m->jumping ? MARIO_VEL_MUL : 1.0f);// && m->e.v.y<0.0f
	
	//m->e.v = Vec2_Add(m->e.v,Vec2_Mulf(m->e.a,t * (m->jumping ? 1.0f : 2.0f)));
	m->e.r.p = Vec2_Add(m->e.r.p,Vec2_Mulf(m->e.v,t));
    m->ground = ENTITY_FALSE;
}
void Mario_WorldCollision(Mario* m,World* w){
	if(m->e.r.p.x < 0.0f) m->e.r.p.x = 0.0f;
	if(m->e.r.p.y < 0.0f) m->e.r.p.y = 0.0f;

	if(!m->dead && m->e.r.p.y>w->height){
		m->dead = ENTITY_TRUE;
		m->e.v.y = -MARIO_VEL_DEAD;
		m->e.r.p.y = w->height - m->e.r.d.y;
	}
	if(m->dead && m->e.r.p.y>w->height){
		m->dead = ENTITY_FALSE;
		m->e.r.p = w->spawn;
	}

	//m->stamp = FIGURE_FALSE;
	m->jumping = ENTITY_FALSE;
	m->reverse = FIGURE_FALSE;
}
char Mario_IsPickUp(Mario* m,World* w,unsigned int x,unsigned int y){
	Block b = World_Get(w,x,y);

	if(b==BLOCK_COIN){
		//AudioPlayer_Add(&ap,"./data/Sound/coin.wav");
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
		//AudioPlayer_Add(&ap,"./data/Sound/upgrade.wav");
		World_Set(w,x,y,BLOCK_NONE);
		m->power = 2;
        m->e.r.p.x -= MARIO_DIM_P2_X - m->e.r.d.x;
		m->e.r.p.y -= MARIO_DIM_P2_Y - m->e.r.d.y;
		m->e.r.d.x = MARIO_DIM_P2_X;
		m->e.r.d.y = MARIO_DIM_P2_Y;
		return 1;
	}else if(b==BLOCK_SUPER_STAR){
		//AudioPlayer_Add(&ap,"./data/Sound/powerup.wav");
		World_Set(w,x,y,BLOCK_NONE);
		m->power = 3;
        m->e.r.p.x -= MARIO_DIM_P3_X - m->e.r.d.x;
		m->e.r.p.y -= MARIO_DIM_P3_Y - m->e.r.d.y;
		m->e.r.d.x = MARIO_DIM_P3_X;
		m->e.r.d.y = MARIO_DIM_P3_Y;
		return 1;
	}
	return 0;
}
char Mario_IsCollision(Mario* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	switch(b){
		case BLOCK_PODEST: 			return s==SIDE_TOP && m->e.v.y>0.0f;
		case BLOCK_FENCE: 			return 0;
		case BLOCK_CLOUD: 			return 0;
		case BLOCK_BUSH: 			return 0;
		case BLOCK_FLAG: 			return 0;
		case BLOCK_CASTLE: 			return 0;
		case BLOCK_GRASFAKE: 		return 0;
		case BLOCK_TREE: 			return 0;
		case BLOCK_SNOWTREE: 		return 0;
		case BLOCK_BACKTREE: 		return s==SIDE_TOP && m->e.v.y>0.0f && World_Get(w,x,y - 1) == BLOCK_NONE;
		case BLOCK_SPAWN:			return 0;
		case BLOCK_SPAWN_BOWLER:	return 0;
		case BLOCK_SPAWN_BOWSER:	return 0;
		case BLOCK_SPAWN_BRO:		return 0;
		case BLOCK_SPAWN_COOPA:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANT_UG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
	}
	return 1;
}
void Mario_Collision(Mario* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
    if(s==SIDE_TOP)
        m->ground = FIGURE_TRUE;

	if(s==SIDE_BOTTOM || (s==SIDE_TOP && m->stamp && m->e.v.x==0.0f)){
		if(b==BLOCK_BRICK)
			World_Set(w,x,y,BLOCK_NONE);
		else if(b==BLOCK_CLOSE_QUEST_FF){
			World_Set(w,x,y,BLOCK_SOLID);
			World_Set(w,x,y-1,BLOCK_FIRE_FLOWER);
		}else if(b==BLOCK_CLOSE_QUEST_SS){
			World_Set(w,x,y,BLOCK_SOLID);
			World_Set(w,x,y-1,BLOCK_SUPER_STAR);
		}
	}
}
void Mario_EntityCollision(Mario* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Mario_GetRender(Mario* m,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	if(m->dead)				        ox = 2U,oy = 1U;
	else if(!m->ground){
		if(!m->stamp)		        ox = 2U,oy = 0U;
		else 				        ox = 1U,oy = 1U;
	}else if(m->stamp){
		if(m->e.v.x==0.0f)	        ox = 1U,oy = 1U;
		else 				        ox = 0U,oy = 1U;
	}
	else if(m->reverse)		        ox = 3U,oy = 0U;
	else if(m->e.v.x==0.0f)	        ox = 7U,oy = 0U;
	else{
		FDuration d = Time_Elapsed(m->start,Time_Nano());
		//d *= (F32_Abs(f->v.x) / F32_Max(MARIO_VEL_MAX_GRD,MARIO_VEL_MAX_AIR));
		d = d - F32_Floor(d);
		d *= F32_Abs(m->e.v.x) * 0.65f;
		d = d - F32_Floor(d);

		ox = 4U + (int)(3.0f * d);
        oy = 0U;
	}

	if(m->power==1)			        oy = 1.0f + oy,dy *= 2;
	else if(m->power==2)	        oy = 3.0f + oy,dy *= 2;
	//else if(m->power==3)	        oy = 0.0f + oy;

	if(m->lookdir==ENTITY_RIGHT)    ox = 15U - ox;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Mario_Free(Mario* m){
	
}
Mario* Mario_New(Vec2 p){
	Mario b;
	b.e.id = ENTITY_MARIO;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;

	b.spawn = p;
	b.start = 0UL;
	b.lookdir = ENTITY_RIGHT;
	b.ground = ENTITY_FALSE;
	b.jumping = ENTITY_FALSE;
	b.stamp = ENTITY_FALSE;
	b.reverse = ENTITY_FALSE;
	b.power = 0;
	b.dead = ENTITY_FALSE;

	Mario* hb = malloc(sizeof(Mario));
	memcpy(hb,&b,sizeof(Mario));
	return hb;
}


typedef struct Bowler {
	Entity e;
} Bowler;

void Bowler_Update(Bowler* e,float t){
}
SubSprite Bowler_GetRender(Bowler* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Bowler_Free(Bowler* e){
}
Bowler* Bowler_New(Vec2 p){
	Bowler b;
	b.e.id = ENTITY_BOWLER;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Bowler* hb = malloc(sizeof(Bowler));
	memcpy(hb,&b,sizeof(Bowler));
	return hb;
}


typedef struct Bowser {
	Entity e;
} Bowser;

void Bowser_Update(Bowser* e,float t){
}
SubSprite Bowser_GetRender(Bowser* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Bowser_Free(Bowser* e){
}
Bowser* Bowser_New(Vec2 p){
	Bowser b;
	b.e.id = ENTITY_BOWSER;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Bowser* hb = malloc(sizeof(Bowser));
	memcpy(hb,&b,sizeof(Bowser));
	return hb;
}


typedef struct Bro {
	Entity e;
} Bro;

void Bro_Update(Bro* e,float t){
}
SubSprite Bro_GetRender(Bro* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Bro_Free(Bro* e){
}
Bro* Bro_New(Vec2 p){
	Bro b;
	b.e.id = ENTITY_BRO;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Bro* hb = malloc(sizeof(Bro));
	memcpy(hb,&b,sizeof(Bro));
	return hb;
}


typedef struct Coopa {
	Entity e;
} Coopa;

void Coopa_Update(Coopa* e,float t){
}
SubSprite Coopa_GetRender(Coopa* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Coopa_Free(Coopa* e){
}
Coopa* Coopa_New(Vec2 p){
	Coopa b;
	b.e.id = ENTITY_COOPA;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Coopa* hb = malloc(sizeof(Coopa));
	memcpy(hb,&b,sizeof(Coopa));
	return hb;
}


typedef struct FireJumper {
	Entity e;
} FireJumper;

void FireJumper_Update(FireJumper* e,float t){
}
SubSprite FireJumper_GetRender(FireJumper* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void FireJumper_Free(FireJumper* e){
}
FireJumper* FireJumper_New(Vec2 p){
	FireJumper b;
	b.e.id = ENTITY_FIREJUMPER;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	FireJumper* hb = malloc(sizeof(FireJumper));
	memcpy(hb,&b,sizeof(FireJumper));
	return hb;
}


typedef struct Fish {
	Entity e;
} Fish;

void Fish_Update(Fish* e,float t){
}
SubSprite Fish_GetRender(Fish* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Fish_Free(Fish* e){
}
Fish* Fish_New(Vec2 p){
	Fish b;
	b.e.id = ENTITY_FISH;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Fish* hb = malloc(sizeof(Fish));
	memcpy(hb,&b,sizeof(Fish));
	return hb;
}


typedef struct Gumba {
	Entity e;
} Gumba;

void Gumba_Update(Gumba* e,float t){
}
SubSprite Gumba_GetRender(Gumba* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Gumba_Free(Gumba* e){
}
Gumba* Gumba_New(Vec2 p){
	Gumba b;
	b.e.id = ENTITY_GUMBA;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Gumba* hb = malloc(sizeof(Gumba));
	memcpy(hb,&b,sizeof(Gumba));
	return hb;
}


typedef struct Lakitu {
	Entity e;
} Lakitu;

void Lakitu_Update(Lakitu* e,float t){
}
SubSprite Lakitu_GetRender(Lakitu* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Lakitu_Free(Lakitu* e){
}
Lakitu* Lakitu_New(Vec2 p){
	Lakitu b;
	b.e.id = ENTITY_LAKITU;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Lakitu* hb = malloc(sizeof(Lakitu));
	memcpy(hb,&b,sizeof(Lakitu));
	return hb;
}


typedef struct PlantUG {
	Entity e;
} PlantUG;

void PlantUG_Update(PlantUG* e,float t){
}
SubSprite PlantUG_GetRender(PlantUG* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void PlantUG_Free(PlantUG* e){
}
PlantUG* PlantUG_New(Vec2 p){
	PlantUG b;
	b.e.id = ENTITY_PLANT_UG;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	PlantUG* hb = malloc(sizeof(PlantUG));
	memcpy(hb,&b,sizeof(PlantUG));
	return hb;
}


typedef struct Plant {
	Entity e;
} Plant;

void Plant_Update(Plant* e,float t){
}
SubSprite Plant_GetRender(Plant* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Plant_Free(Plant* e){
}
Plant* Plant_New(Vec2 p){
	Plant b;
	b.e.id = ENTITY_PLANT;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Plant* hb = malloc(sizeof(Plant));
	memcpy(hb,&b,sizeof(Plant));
	return hb;
}


typedef struct Spike {
	Entity e;
} Spike;

void Spike_Update(Spike* e,float t){
}
SubSprite Spike_GetRender(Spike* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Spike_Free(Spike* e){
}
Spike* Spike_New(Vec2 p){
	Spike b;
	b.e.id = ENTITY_SPIKE;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Spike* hb = malloc(sizeof(Spike));
	memcpy(hb,&b,sizeof(Spike));
	return hb;
}


typedef struct Squid {
	Entity e;
} Squid;

void Squid_Update(Squid* e,float t){
}
SubSprite Squid_GetRender(Squid* e,EntityAtlas* ea){

	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Squid_Free(Squid* e){
}
Squid* Squid_New(Vec2 p){
	Squid b;
	b.e.id = ENTITY_SQUID;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Squid* hb = malloc(sizeof(Squid));
	memcpy(hb,&b,sizeof(Squid));
	return hb;
}


typedef struct Willi {
	Entity e;
} Willi;

void Willi_Update(Willi* e,float t){
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
SubSprite Willi_GetRender(Willi* e,EntityAtlas* ea){

	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	if(e->e.v.x > 0.0f) ox = 1U;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Willi_Free(Willi* e){
}
Willi* Willi_New(Vec2 p){
	Willi b;
	b.e.id = ENTITY_WILLI;
	b.e.r = (Rect){ p,{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ -1.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsPickUp = (char(*)(Entity*,World*,unsigned int,unsigned int))Mario_IsPickUp;
	b.e.IsCollision = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsCollision;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;
	Willi* hb = malloc(sizeof(Willi));
	memcpy(hb,&b,sizeof(Willi));
	return hb;
}



Block MarioWorld_Std_Mapper(char c){
	switch (c){
		case '.':	return BLOCK_NONE;
		case '_':	return BLOCK_GRAS;
		case '#':	return BLOCK_BRICK;
		case 'F':	return BLOCK_CLOSE_QUEST_FF;
		case 'S':	return BLOCK_CLOSE_QUEST_SS;
		case 'o':	return BLOCK_COIN;
		case 'p':	return BLOCK_PODEST;
		case '!':	return BLOCK_SOLID;
		case '|':	return BLOCK_TUBE;
		case '/':	return BLOCK_SILVERTUBE;
		case 'f':	return BLOCK_FIRE_FLOWER;
		case 's':	return BLOCK_SUPER_STAR;
		case 'b':	return BLOCK_BUSH;
		case 'c':	return BLOCK_CASTLE;
		case '~':	return BLOCK_CLOUD;
		case '+':	return BLOCK_FENCE;
		case '$':	return BLOCK_FLAG;
		case '-':	return BLOCK_GRASFAKE;
		case '(':	return BLOCK_TREE;
		case ')':	return BLOCK_SNOWTREE;
		case 'R':	return BLOCK_ROCKET;
		case '%':	return BLOCK_SPAWN;
		case 'B':	return BLOCK_SPAWN_BOWLER;
		case 'W':	return BLOCK_SPAWN_BOWSER;
		case 'O':	return BLOCK_SPAWN_BRO;
		case 'C':	return BLOCK_SPAWN_COOPA;
		case 'J':	return BLOCK_SPAWN_FIREJUMPER;
		case 'H':	return BLOCK_SPAWN_FISH;
		case 'G':	return BLOCK_SPAWN_GUMBA;
		case 'L':	return BLOCK_SPAWN_LAKITU;
		case 'U':	return BLOCK_SPAWN_PLANT_UG;
		case 'P':	return BLOCK_SPAWN_PLANT;
		case '^':	return BLOCK_SPAWN_SPIKE;
		case 'Q':	return BLOCK_SPAWN_SQUID;
		case 'I':	return BLOCK_SPAWN_WILLI;
	}
	return BLOCK_NONE;
}
char MarioWorld_Std_MapperR(Block b){
	switch (b){
		case BLOCK_NONE:				return '.';
		case BLOCK_GRAS:				return '_';
		case BLOCK_BRICK:				return '#';
		case BLOCK_CLOSE_QUEST_FF:		return 'F';
		case BLOCK_CLOSE_QUEST_SS:		return 'S';
		case BLOCK_COIN:				return 'o';
		case BLOCK_PODEST:				return 'p';
		case BLOCK_SOLID:				return '!';
		case BLOCK_TUBE:				return '|';
		case BLOCK_SILVERTUBE:			return '/';
		case BLOCK_FIRE_FLOWER:			return 'f';
		case BLOCK_SUPER_STAR:			return 's';
		case BLOCK_BUSH:				return 'b';
		case BLOCK_CASTLE:				return 'c';
		case BLOCK_CLOUD:				return '~';
		case BLOCK_FENCE:				return '+';
		case BLOCK_FLAG:				return '$';
		case BLOCK_GRASFAKE:			return '-';
		case BLOCK_TREE:				return '(';
		case BLOCK_SNOWTREE:			return ')';
		case BLOCK_BACKTREE:			return '[';
		case BLOCK_ROCKET:				return 'R';
		case BLOCK_SPAWN:				return '%';
		case BLOCK_SPAWN_BOWLER:		return 'B';
		case BLOCK_SPAWN_BOWSER:		return 'W';
		case BLOCK_SPAWN_BRO:			return 'O';
		case BLOCK_SPAWN_COOPA:			return 'C';
		case BLOCK_SPAWN_FIREJUMPER:	return 'J';
		case BLOCK_SPAWN_FISH:			return 'H';
		case BLOCK_SPAWN_GUMBA:			return 'G';
		case BLOCK_SPAWN_LAKITU:		return 'L';
		case BLOCK_SPAWN_PLANT_UG:		return 'U';
		case BLOCK_SPAWN_PLANT:			return 'P';
		case BLOCK_SPAWN_SPIKE:			return '^';
		case BLOCK_SPAWN_SQUID:			return 'Q';
		case BLOCK_SPAWN_WILLI:			return 'I';
	}
	return '.';
}
void* MarioWorld_Std_SpawnMapper(Vec2 p,SpawnType st,unsigned int* size){
	switch (st){
		case ENTITY_BOWLER:		*size = sizeof(Bowler); 	return Bowler_New(p);
		case ENTITY_BOWSER:		*size = sizeof(Bowser); 	return Bowser_New(p);
		case ENTITY_BRO:		*size = sizeof(Bro); 		return Bro_New(p);
		case ENTITY_COOPA:		*size = sizeof(Coopa);		return Coopa_New(p);
		case ENTITY_FIREJUMPER:	*size = sizeof(FireJumper); return FireJumper_New(p);
		case ENTITY_FISH:		*size = sizeof(Fish); 		return Fish_New(p);
		case ENTITY_GUMBA:		*size = sizeof(Gumba); 		return Gumba_New(p);
		case ENTITY_LAKITU:		*size = sizeof(Lakitu); 	return Lakitu_New(p);	
		case ENTITY_PLANT_UG:	*size = sizeof(PlantUG); 	return PlantUG_New(p);
		case ENTITY_PLANT:		*size = sizeof(Plant); 		return Plant_New(p);
		case ENTITY_SPIKE:		*size = sizeof(Spike); 		return Spike_New(p);
		case ENTITY_SQUID:		*size = sizeof(Squid);	 	return Squid_New(p);
		case ENTITY_WILLI:		*size = sizeof(Willi); 		return Willi_New(p);
	}
	return NULL;
}

SubSprite MarioWorld_Tube_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	unsigned char nbs = World_GetNeigbours(w,BLOCK_TUBE,x,y);
	
	if(World_Get(w,x - 2,y) == BLOCK_TUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 10U;
	else if(World_Get(w,x - 2,y) == BLOCK_TUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 11U;
	else if(World_Get(w,x + 2,y) == BLOCK_TUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 12U;
	else if(World_Get(w,x + 2,y) == BLOCK_TUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 13U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 2U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 3U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 4U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 5U;
	
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 6U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 7U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 8U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 9U;
	
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;

	// if(World_Get(w,x,y - 1) != BLOCK_TUBE){
	// 	oy = 0U;
	// 	if(World_Get(w,x + 1,y) == BLOCK_TUBE)			ox = 4U;
	// 	else if(World_Get(w,x - 1,y) == BLOCK_TUBE)		ox = 5U;
	// }else if(World_Get(w,x,y - 1) == BLOCK_TUBE){
	// 	oy = 1U;
	// 	if(World_Get(w,x + 1,y) == BLOCK_TUBE)			ox = 4U;
	// 	else if(World_Get(w,x - 1,y) == BLOCK_TUBE)		ox = 5U;
	// }
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_SilverTube_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	unsigned char nbs = World_GetNeigbours(w,BLOCK_SILVERTUBE,x,y);
	
	if(World_Get(w,x - 2,y) == BLOCK_SILVERTUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 10U;
	else if(World_Get(w,x - 2,y) == BLOCK_SILVERTUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 11U;
	else if(World_Get(w,x + 2,y) == BLOCK_SILVERTUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 12U;
	else if(World_Get(w,x + 2,y) == BLOCK_SILVERTUBE && nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 13U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){ 
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	})) ox = 0U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 1U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 2U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 3U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 4U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 5U;
	
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 6U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 7U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 8U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 9U;
	
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_BOTTOM_MID,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 14U;

	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_LEFT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;
	else if(nbs == World_Neighbour_Mask((unsigned char[]){
		WORLD_NEIGHBOUR_TOP_LEFT,
		WORLD_NEIGHBOUR_TOP_MID,
		WORLD_NEIGHBOUR_TOP_RIGHT,
		WORLD_NEIGHBOUR_MID_LEFT,
		WORLD_NEIGHBOUR_MID_RIGHT,
		WORLD_NEIGHBOUR_BOTTOM_RIGHT,
		WORLD_NEIGHBOUR_NONE
	}))	ox = 15U;

	// if(World_Get(w,x,y - 1) != BLOCK_SILVERTUBE){
	// 	oy = 0U;
	// 	if(World_Get(w,x + 1,y) == BLOCK_SILVERTUBE)			ox = 4U;
	// 	else if(World_Get(w,x - 1,y) == BLOCK_SILVERTUBE)		ox = 5U;
	// }else if(World_Get(w,x,y - 1) == BLOCK_SILVERTUBE){
	// 	oy = 1U;
	// 	if(World_Get(w,x + 1,y) == BLOCK_SILVERTUBE)			ox = 4U;
	// 	else if(World_Get(w,x - 1,y) == BLOCK_SILVERTUBE)		ox = 5U;
	// }
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Bush_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_BUSH && World_Get(w,x + 1,y) == BLOCK_BUSH)	ox = 3U;
	else if(World_Get(w,x + 1,y) == BLOCK_BUSH)										ox = 0U;
	else if(World_Get(w,x - 1,y) == BLOCK_BUSH)										ox = 1U;
	else																			ox = 2U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Castle_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;
	
	if(World_Get(w,x - 1,y) == BLOCK_CASTLE && World_Get(w,x + 1,y) == BLOCK_CASTLE){
		if(World_Get(w,x,y - 1) != BLOCK_CASTLE){
			ox = 0U;
		}else if(World_Get(w,x,y + 1) != BLOCK_CASTLE){
			ox = 5U;
		}else{
			if(y % 2 == 0){
				ox = 1U;
			}else{
				if(x % 2 == 0){
					ox = 2U;
				}else{
					ox = 5U;
				}
			}
		}
	}else if(World_Get(w,x - 1,y) == BLOCK_CASTLE){
		if(World_Get(w,x,y - 1) != BLOCK_CASTLE){
			ox = 0U;
		}else{
			ox = 5U;
		}
	}else if(World_Get(w,x + 1,y) == BLOCK_CASTLE){
		if(World_Get(w,x,y - 1) != BLOCK_CASTLE){
			ox = 0U;
		}else{
			if(World_Get(w,x,y + 1) == BLOCK_CASTLE) 	ox = 3U;
			else 										ox = 4U;
		}
	}else{
		ox = 5U;
	}
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Cloud_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_CLOUD && World_Get(w,x + 1,y) == BLOCK_CLOUD)	ox = 3U;
	else if(World_Get(w,x + 1,y) == BLOCK_CLOUD)									ox = 0U;
	else if(World_Get(w,x - 1,y) == BLOCK_CLOUD)									ox = 1U;
	else																			ox = 2U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Fence_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_FENCE && World_Get(w,x + 1,y) == BLOCK_FENCE)	ox = 3U;
	else if(World_Get(w,x + 1,y) == BLOCK_FENCE)									ox = 0U;
	else if(World_Get(w,x - 1,y) == BLOCK_FENCE)									ox = 1U;
	else																			ox = 2U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Flag_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x,y + 1) == BLOCK_FLAG && World_Get(w,x,y - 1) == BLOCK_FLAG)	ox = 0U;
	else if(World_Get(w,x,y + 1) == BLOCK_FLAG)										ox = 1U;
	else if(World_Get(w,x,y - 1) == BLOCK_FLAG)										ox = 0U;
	else																			ox = 0U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Tree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_NONE && World_Get(w,x + 1,y) == BLOCK_NONE && World_Get(w,x,y + 1) == BLOCK_NONE)
		ox = 2U;
	else if(World_Get(w,x,y + 1) == BLOCK_TREE){
		if(World_Get(w,x - 1,y) == BLOCK_TREE || World_Get(w,x + 1,y) == BLOCK_TREE)
			if(World_Get(w,x,y - 1) == BLOCK_TREE)	ox = 6U;
			else 									ox = 2U;
		else
			if(World_Get(w,x,y - 1) == BLOCK_TREE)	ox = 0U;
			else 									ox = 2U;
	}else{
		if(World_Get(w,x,y + 1) == BLOCK_NONE){
			if(World_Get(w,x - 1,y) == BLOCK_TREE) 		ox = 4U;
			else if(World_Get(w,x + 1,y) == BLOCK_TREE) ox = 5U;
			else if(World_Get(w,x,y - 1) == BLOCK_TREE)	ox = 3U;
			else 										ox = 1U;
		}else{
			ox = 0U;
		}
	}

	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_SnowTree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_NONE && World_Get(w,x + 1,y) == BLOCK_NONE && World_Get(w,x,y + 1) == BLOCK_NONE)
		ox = 2U;
	else if(World_Get(w,x,y + 1) == BLOCK_SNOWTREE){
		if(World_Get(w,x - 1,y) == BLOCK_SNOWTREE || World_Get(w,x + 1,y) == BLOCK_SNOWTREE)
			if(World_Get(w,x,y - 1) == BLOCK_SNOWTREE)	ox = 6U;
			else 										ox = 2U;
		else
			if(World_Get(w,x,y - 1) == BLOCK_SNOWTREE)	ox = 0U;
			else 										ox = 2U;
	}else{
		if(World_Get(w,x,y + 1) == BLOCK_NONE){
			if(World_Get(w,x - 1,y) == BLOCK_SNOWTREE) 		ox = 4U;
			else if(World_Get(w,x + 1,y) == BLOCK_SNOWTREE) ox = 5U;
			else if(World_Get(w,x,y - 1) == BLOCK_SNOWTREE)	ox = 3U;
			else 											ox = 1U;
		}else{
			ox = 0U;
		}
	}
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_BackTree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x - 1,y) == BLOCK_NONE && World_Get(w,x,y + 1) == BLOCK_NONE) 		ox = 0U;
	else if(World_Get(w,x + 1,y) == BLOCK_NONE && World_Get(w,x,y + 1) == BLOCK_NONE) 	ox = 2U;
	else if(World_Get(w,x,y - 1) != BLOCK_BACKTREE) 									ox = 1U;
	else 																				ox = 3U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Rocket_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}

SubSprite MarioWorld_Bowler_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Bowser_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Bro_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Coopa_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_FireJumper_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Fish_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Gumba_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Lakitu_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_PlantUG_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_PLant_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Spike_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Squid_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Willi_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}

typedef struct MarioWorld {
    World world;
    Figure mario;
    TransformedView tv;
    AudioPlayer ap;
    unsigned int level;
    Block selected;
} MarioWorld;

MarioWorld MarioWorld_New(char* path_lvl,char* path_blocks,char* path_entities){
    MarioWorld mw;
    mw.mario = Figure_New(
		Mario_New((Vec2){ 0.0f,0.0f }),
		(void(*)(Entity*,World*,const float))Mario_Update,
		(void(*)(Entity*,const float))Mario_Move,
		(void(*)(Entity*))Mario_Free
	);

	mw.tv = TransformedView_New((Vec2){ GetHeight(),GetHeight() });
	TransformedView_Zoom(&mw.tv,(Vec2){ 0.1f,0.1f });
	//TransformedView_Offset(&tv,(Vec2){ -0.5f,0.0f });
	TransformedView_Focus(&mw.tv,&mw.mario.e->r.p);

	mw.ap = AudioPlayer_New();

	mw.selected = BLOCK_NONE;
	mw.level = 0U;
	mw.world = World_Make(path_lvl,BLOCK_SPAWN,MarioWorld_Std_Mapper,
        (Animation[]){
		    Animation_Make_SpritePath(path_blocks,"Dirt.png",ANIMATIONBG_BG,ENTITY_NONE),
		    Animation_Make_SpritePath(path_blocks,"Brick.png",ANIMATIONBG_BG,ENTITY_NONE),
		    Animation_Make_AnimationAtlasPath(path_blocks,"QuestionMark.png",ANIMATIONBG_BG,ENTITY_NONE,3,1,1.0),
		    Animation_Make_AnimationAtlasPath(path_blocks,"QuestionMark.png",ANIMATIONBG_BG,ENTITY_NONE,3,1,1.0),
		    Animation_Make_AnimationAtlasPath(path_blocks,"Coin.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,1.0),
		    Animation_Make_SpritePath(path_blocks,"Podest.png",ANIMATIONBG_BG,ENTITY_NONE),
		    Animation_Make_SpritePath(path_blocks,"Solid.png",ANIMATIONBG_BG,ENTITY_NONE),
		    Animation_Make_AtlasPath(path_blocks,"Tube.png",ANIMATIONBG_BG,ENTITY_NONE,16,1,MarioWorld_Tube_Get),
		    Animation_Make_AtlasPath(path_blocks,"SilverTube.png",ANIMATIONBG_BG,ENTITY_NONE,16,1,MarioWorld_SilverTube_Get),
		    Animation_Make_AnimationAtlasPath(path_blocks,"FireFlower.png",ANIMATIONBG_BG,ENTITY_NONE,4,2,1.0),
		    Animation_Make_AnimationAtlasPath(path_blocks,"SuperStar.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,1.0),
		    Animation_Make_AtlasPath(path_blocks,"Bush.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,MarioWorld_Bush_Get),
		    Animation_Make_AtlasPath(path_blocks,"Castle.png",ANIMATIONBG_FG,ENTITY_NONE,6,1,MarioWorld_Castle_Get),
		    Animation_Make_AtlasPath(path_blocks,"Cloud.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,MarioWorld_Cloud_Get),
		    Animation_Make_AtlasPath(path_blocks,"Fence.png",ANIMATIONBG_FG,ENTITY_NONE,4,1,MarioWorld_Fence_Get),
		    Animation_Make_AtlasPath(path_blocks,"Flag.png",ANIMATIONBG_FG,ENTITY_NONE,2,1,MarioWorld_Flag_Get),
		    Animation_Make_SpritePath(path_blocks,"Dirt.png",ANIMATIONBG_FG,ENTITY_NONE),
		    Animation_Make_AtlasPath(path_blocks,"Tree.png",ANIMATIONBG_BG,ENTITY_NONE,7,1,MarioWorld_Tree_Get),
		    Animation_Make_AtlasPath(path_blocks,"SnowTree.png",ANIMATIONBG_FG,ENTITY_NONE,7,1,MarioWorld_SnowTree_Get),
		    Animation_Make_AtlasPath(path_blocks,"BackTree.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,MarioWorld_BackTree_Get),
		    Animation_Make_AtlasPath(path_blocks,"Rocket.png",ANIMATIONBG_BG,ENTITY_NONE,2,1,MarioWorld_Rocket_Get),
		    Animation_Make_SpritePath(path_blocks,"Solid.png",ANIMATIONBG_DG,ENTITY_NONE),
		    Animation_Make_AtlasPath(path_entities,"Bowler.png",ANIMATIONBG_DG,ENTITY_BOWLER,5,3,MarioWorld_Bowler_Get),
		    Animation_Make_AtlasPath(path_entities,"Bowser.png",ANIMATIONBG_DG,ENTITY_BOWSER,8,1,MarioWorld_Bowser_Get),
		    Animation_Make_AtlasPath(path_entities,"Bro.png",ANIMATIONBG_DG,ENTITY_BRO,6,2,MarioWorld_Bro_Get),
		    Animation_Make_AtlasPath(path_entities,"Coopa.png",ANIMATIONBG_DG,ENTITY_COOPA,10,3,MarioWorld_Coopa_Get),
		    Animation_Make_AtlasPath(path_entities,"FireJumper.png",ANIMATIONBG_DG,ENTITY_FIREJUMPER,2,1,MarioWorld_FireJumper_Get),
		    Animation_Make_AtlasPath(path_entities,"Fish.png",ANIMATIONBG_DG,ENTITY_FISH,4,3,MarioWorld_Fish_Get),
		    Animation_Make_AtlasPath(path_entities,"Gumba.png",ANIMATIONBG_DG,ENTITY_GUMBA,3,3,MarioWorld_Gumba_Get),
		    Animation_Make_AtlasPath(path_entities,"Lakitu.png",ANIMATIONBG_DG,ENTITY_LAKITU,3,3,MarioWorld_Lakitu_Get),
		    Animation_Make_AtlasPath(path_entities,"Plant_UG.png",ANIMATIONBG_DG,ENTITY_PLANT_UG,2,1,MarioWorld_PlantUG_Get),
		    Animation_Make_AtlasPath(path_entities,"Plant.png",ANIMATIONBG_DG,ENTITY_PLANT,2,1,MarioWorld_PLant_Get),
		    Animation_Make_AtlasPath(path_entities,"Spike.png",ANIMATIONBG_DG,ENTITY_SPIKE,6,1,MarioWorld_Spike_Get),
		    Animation_Make_AtlasPath(path_entities,"Squid.png",ANIMATIONBG_DG,ENTITY_SQUID,2,1,MarioWorld_Squid_Get),
		    Animation_Make_AtlasPath(path_entities,"Willi.png",ANIMATIONBG_DG,ENTITY_WILLI,2,1,MarioWorld_Willi_Get),
		    Animation_Null()
	    },
        (EntityAtlas[]){
		    EntityAtlas_New(path_entities,"Mario.png",16,12,	(void(*)(void*,const float))Mario_Update,		(SubSprite(*)(void*,EntityAtlas*))Mario_GetRender,		(void(*)(void*))Mario_Free),
		    EntityAtlas_New(path_entities,"Bowler.png",5,3,		(void(*)(void*,const float))Bowler_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowler_GetRender,		(void(*)(void*))Bowler_Free),
		    EntityAtlas_New(path_entities,"Bowser.png",8,1,		(void(*)(void*,const float))Bowser_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowser_GetRender,		(void(*)(void*))Bowser_Free),
		    EntityAtlas_New(path_entities,"Bro.png",6,2,		(void(*)(void*,const float))Bro_Update,			(SubSprite(*)(void*,EntityAtlas*))Bro_GetRender,		(void(*)(void*))Bro_Free),
		    EntityAtlas_New(path_entities,"Coopa.png",10,3,		(void(*)(void*,const float))Coopa_Update,		(SubSprite(*)(void*,EntityAtlas*))Coopa_GetRender,		(void(*)(void*))Coopa_Free),
		    EntityAtlas_New(path_entities,"FireJumper.png",2,1,	(void(*)(void*,const float))FireJumper_Update,	(SubSprite(*)(void*,EntityAtlas*))FireJumper_GetRender,	(void(*)(void*))FireJumper_Free),
		    EntityAtlas_New(path_entities,"Fish.png",4,3,		(void(*)(void*,const float))Fish_Update,		(SubSprite(*)(void*,EntityAtlas*))Fish_GetRender,		(void(*)(void*))Fish_Free),
		    EntityAtlas_New(path_entities,"Gumba.png",3,3,		(void(*)(void*,const float))Gumba_Update,		(SubSprite(*)(void*,EntityAtlas*))Gumba_GetRender,		(void(*)(void*))Gumba_Free),
		    EntityAtlas_New(path_entities,"Lakitu.png",3,3,		(void(*)(void*,const float))Lakitu_Update,		(SubSprite(*)(void*,EntityAtlas*))Lakitu_GetRender,		(void(*)(void*))Lakitu_Free),
		    EntityAtlas_New(path_entities,"Plant_UG.png",2,1,	(void(*)(void*,const float))PlantUG_Update,		(SubSprite(*)(void*,EntityAtlas*))PlantUG_GetRender,	(void(*)(void*))PlantUG_Free),
		    EntityAtlas_New(path_entities,"Plant.png",2,1,		(void(*)(void*,const float))Plant_Update,		(SubSprite(*)(void*,EntityAtlas*))Plant_GetRender,		(void(*)(void*))Plant_Free),
		    EntityAtlas_New(path_entities,"Spike.png",6,1,		(void(*)(void*,const float))Spike_Update,		(SubSprite(*)(void*,EntityAtlas*))Spike_GetRender,		(void(*)(void*))Spike_Free),
		    EntityAtlas_New(path_entities,"Squid.png",2,1,		(void(*)(void*,const float))Squid_Update,		(SubSprite(*)(void*,EntityAtlas*))Squid_GetRender,		(void(*)(void*))Squid_Free),
		    EntityAtlas_New(path_entities,"Willi.png",2,1,		(void(*)(void*,const float))Willi_Update,		(SubSprite(*)(void*,EntityAtlas*))Willi_GetRender,		(void(*)(void*))Willi_Free),
		    EntityAtlas_Null()
	    }
    );

    mw.mario.e->r.p = mw.world.spawn;
    return mw;
}
void MarioWorld_AudioPlayerStart(MarioWorld* mw){
    AudioPlayer_Start(&mw->ap);
}
void MarioWorld_Free(MarioWorld* mw){
    World_Free(&mw->world);
    Figure_Free(&mw->mario);
    AudioPlayer_Free(&mw->ap);
    //TransformedView tv;
    //unsigned int level;
    //Block selected;
}

#endif