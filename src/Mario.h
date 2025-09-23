#ifndef MARIO_H
#define MARIO_H

#include "World.h"
#include "Figure.h"

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
#define MARIO_DIM_P1_Y	                1.8f
#define MARIO_DIM_P2_X	                0.9f
#define MARIO_DIM_P2_Y	                1.8f
#define MARIO_DIM_P3_X	                0.9f
#define MARIO_DIM_P3_Y	                0.9f

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
		m->e.r.d.x = MARIO_DIM_P2_X;
		m->e.r.d.y = MARIO_DIM_P2_Y;
		return 1;
	}else if(b==BLOCK_SUPER_STAR){
		//AudioPlayer_Add(&ap,"./data/Sound/powerup.wav");
		World_Set(w,x,y,BLOCK_NONE);
		m->power = 3;
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
	b.e.r = (Rect){ p,{ 0.9f,0.9f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
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
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
	Squid* hb = malloc(sizeof(Squid));
	memcpy(hb,&b,sizeof(Squid));
	return hb;
}


typedef struct Willi {
	Entity e;
	Vec2 v;
} Willi;

void Willi_Update(Willi* e,float t){
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->v,t));
}
SubSprite Willi_GetRender(Willi* e,EntityAtlas* ea){

	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	if(e->v.x > 0.0f) ox = 1U;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Willi_Free(Willi* e){
}
Willi* Willi_New(Vec2 p){
	Willi b;
	b.e.id = ENTITY_WILLI;
	b.e.r = (Rect){ p,{ 1.0f,1.0f } };
	b.v = (Vec2){ -1.0f,0.0f };
	Willi* hb = malloc(sizeof(Willi));
	memcpy(hb,&b,sizeof(Willi));
	return hb;
}

#endif