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
#define BLOCK_SPAWN_FIREJUMPER			27U
#define BLOCK_SPAWN_FISH				28U
#define BLOCK_SPAWN_GUMBA				29U
#define BLOCK_SPAWN_LAKITU				30U
#define BLOCK_SPAWN_PLANTUG				31U
#define BLOCK_SPAWN_PLANT				32U
#define BLOCK_SPAWN_SPIKE				33U
#define BLOCK_SPAWN_SQUID				34U
#define BLOCK_SPAWN_WILLI				35U
#define BLOCK_SPAWN_EXPLOSION			36U
#define BLOCK_SPAWN_FIREBALL			37U
#define BLOCK_SPAWN_FIREBEAM			38U
#define BLOCK_SPAWN_HAMMER				39U

#define ENTITY_MARIO					1U
#define ENTITY_BOWLER					2U
#define ENTITY_BOWSER					3U
#define ENTITY_BRO						4U
#define ENTITY_COOPA					5U
#define ENTITY_FIREJUMPER				6U
#define ENTITY_FISH						7U
#define ENTITY_GUMBA					8U
#define ENTITY_LAKITU					9U
#define ENTITY_PLANTUG					10U
#define ENTITY_PLANT					11U
#define ENTITY_SPIKE					12U
#define ENTITY_SQUID					13U
#define ENTITY_WILLI					14U
#define ENTITY_EXPLOSION				15U
#define ENTITY_FIREBALL					16U
#define ENTITY_FIREBEAM					17U
#define ENTITY_HAMMER					18U

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
#define BOWLER_VEL_X					3.0f
#define BOWLER_VEL_ROLLX				9.0f

#define BOWSER_DIM_X					1.9f
#define BOWSER_DIM_Y					1.9f
#define BOWSER_VEL_X					0.4f
#define BOWSER_VEL_Y					20.0f
#define BOWSER_THROW_DELAY				0.9f
#define BOWSER_LIFES					5U

#define BRO_DIM_X						0.9f
#define BRO_DIM_Y						1.9f
#define BRO_VEL_X						0.5f
#define BRO_VEL_Y						15.0f
#define BRO_THROW_DELAY					0.5f

#define COOPA_DIM_X						0.9f
#define COOPA_DIM_Y						0.9f
#define COOPA_VEL_X						2.0f
#define COOPA_VEL_ROLLX					9.0f

#define FIREJUMPER_DIM_X				0.9f
#define FIREJUMPER_DIM_Y				0.9f

#define FISH_DIM_X						0.9f
#define FISH_DIM_Y						0.9f
#define FISH_VEL_X						2.0f
#define FISH_VEL_Y						2.0f

#define GUMBA_DIM_X						0.9f
#define GUMBA_DIM_Y						0.9f
#define GUMBA_VEL_X						2.0f
#define GUMBA_VEL_Y						2.0f

#define LAKITU_DIM_X					0.9f
#define LAKITU_DIM_Y					1.9f
#define LAKITU_VEL_X					0.5f
#define LAKITU_THROW_DELAY				1.0f

#define PLANT_DIM_X						0.9f
#define PLANT_DIM_Y						1.9f
#define PLANTUG_DIM_X					0.9f
#define PLANTUG_DIM_Y					1.9f

#define SPIKE_DIM_X						0.9f
#define SPIKE_DIM_Y						0.9f
#define SPIKE_VEL_X						2.0f
#define SPIKE_VEL_Y						2.0f

#define SQUID_DIM_X						0.9f
#define SQUID_DIM_Y						1.9f

#define WILLI_DIM_X						0.9f
#define WILLI_DIM_Y						0.9f
#define WILLI_VEL_X						4.0f
#define WILLI_VEL_Y						4.0f

#define EXPLOSION_DIM_X					0.9f
#define EXPLOSION_DIM_Y					0.9f

#define FIREBALL_DIM_X					0.9f
#define FIREBALL_DIM_Y					0.9f
#define FIREBALL_VEL_X					12.0f
#define FIREBALL_VEL_Y					8.0f
#define FIREBALL_BOUNCE					8U

#define FIREBEAM_DIM_X					1.9f
#define FIREBEAM_DIM_Y					0.9f
#define FIREBEAM_VEL_X					7.0f
#define FIREBEAM_VEL_Y					0.0f

#define HAMMER_DIM_X					0.9f
#define HAMMER_DIM_Y					0.9f
#define HAMMER_VEL_X					11.0f
#define HAMMER_VEL_Y					8.0f

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


typedef struct MarioWorld {
    World world;
    Figure mario;
    TransformedView tv;
    AudioPlayer ap;
    unsigned int level;
    Block selected;
} MarioWorld;


typedef struct Bowler {
	Entity e;
	char inside;
} Bowler;

void Bowler_Free(Bowler* e){
	Entity_Free(&e->e);
}
void Bowler_Update(Bowler* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Bowler_WorldCollision(Bowler* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Bowler_IsSolid(Bowler* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Bowler_Collision(Bowler* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Bowler_EntityCollision(Bowler* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			Bowler* m2 = (Bowler*)other;

			char move1 = m->inside && m->e.v.x != 0.0f;
			char move2 = m2->inside && m2->e.v.x != 0.0f;

			if(move1 && move2){
				World_Remove(w,(Entity*)m);
				World_Remove(w,other);
			}else if(move1){
				World_Remove(w,other);
			}else if(move2){
				World_Remove(w,(Entity*)m);
			}else{
				m->e.v.x = F32_Abs(m->e.v.x) * F32_Sign(m->e.r.p.x - m2->e.r.p.x);
				m2->e.v.x = F32_Abs(m2->e.v.x) * F32_Sign(m2->e.r.p.x - m->e.r.p.x);
			}
			break;
		}
		case ENTITY_BOWSER:		{
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_COOPA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_FIREJUMPER:	{
			
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,other);
			break;
		}
	}
}
SubSprite Bowler_GetRender(Bowler* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 1.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);

	if(e->e.v.x > 0.0f) ox = 4 - ox;
	if(e->inside) ox = 2;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Bowler* Bowler_New(Vec2 p){
	Bowler b;
	b.e.id = ENTITY_BOWLER;
	b.e.r = (Rect){ { p.x,p.y - (BOWLER_DIM_Y - 1.0f)},{ BOWLER_DIM_X,BOWLER_DIM_Y } };
	b.e.v = (Vec2){ -BOWLER_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Bowler_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Bowler_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Bowler_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Bowler_EntityCollision;
	
	b.inside = 0;

	Bowler* hb = malloc(sizeof(Bowler));
	memcpy(hb,&b,sizeof(Bowler));
	return hb;
}


typedef struct Firebeam {
	Entity e;
} Firebeam;

typedef struct Bowser {
	Entity e;
	float startx;
	char dir;
	char ground;
	unsigned short lifes;
	Timepoint start;
} Bowser;

void Bowser_Free(Bowser* e){
	Entity_Free(&e->e);
}
void Bowser_Update(Bowser* e,float t){
	e->ground = 0;

	const float dir = e->startx - e->e.r.p.x;
	if(F32_Abs(dir) > 2.0f){
		e->e.v.x = dir * BOWSER_VEL_X;
		e->e.r.p.x = e->startx - F32_Sign(dir) * 2.0f;
	}

	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Bowser_Damage(Bowser* m,World* w,unsigned short damage){
	if((int)m->lifes - (int)damage < 0){
		AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/BowserDown.wav");
		World_Remove(w,(Entity*)m);
	}
	
	m->lifes-=damage;
}
void Bowser_WorldCollision(Bowser* m,World* w){
	m->dir = (((MarioWorld*)w)->mario.e->r.p.x - m->e.r.p.x) < 0.0f ? 0 : 1; 
	
	const float dir = m->startx - m->e.r.p.x;
	if(F32_Abs(dir) > 1.0f){
		m->start = 0UL;
	}else{
		if(m->start == 0UL)
			m->start = Time_Nano();
	}

	if(m->ground && m->start > 0UL && Time_Elapsed(m->start,Time_Nano()) > BOWSER_THROW_DELAY * 0.5f){
		m->e.v.y = -BOWSER_VEL_Y;
	}
	if(m->start > 0UL && Time_Elapsed(m->start,Time_Nano()) > BOWSER_THROW_DELAY){
		const Vec2 mp = Vec2_Add(m->e.r.p,Vec2_Mulf(m->e.r.d,0.5f));
		const Vec2 off = { (m->e.r.d.x + FIREBEAM_DIM_X) * 0.51f,0.0f };
		
		AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Bowserfire.wav");
		Firebeam* s = (Firebeam*)World_Spawn(
			w,
			ENTITY_FIREBEAM,
			Vec2_Add(
				Vec2_Sub(
					mp,
					Vec2_Mulf(
						(Vec2){ FIREBEAM_DIM_X,HAMMER_DIM_Y },
						0.5f
					)
				),
				Vec2_Mulf(
					off,
					m->dir == 0 ? -1.0f : 1.0f
				)
			)
		);
		s->e.v.x = FIREBEAM_VEL_X * F32_Sign(s->e.r.p.x - mp.x);
		s->e.v.y = FIREBEAM_VEL_Y;

		m->start = 0UL;
	}

	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Bowser_IsSolid(Bowser* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Bowser_Collision(Bowser* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f){
		m->e.v.y = 0.0f;
		m->ground = 1;
	}
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x = 0.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x = 0.0f;
}
void Bowser_EntityCollision(Bowser* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Bowser_GetRender(Bowser* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 1.0f;
	d = d - F32_Floor(d);
	unsigned int a = (int)(2.0f * d);

	if(e->start > 0UL && Time_Elapsed(e->start,Time_Nano()) > BOWSER_THROW_DELAY * 0.5f)
		ox = a;
	else
		ox = 2U + a;

	if(e->dir) ox = 7U - ox;

	dx *= 2;
	dy *= 2;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Bowser* Bowser_New(Vec2 p){
	Bowser b;
	b.e.id = ENTITY_BOWSER;
	b.e.r = (Rect){ { p.x,p.y - (BOWSER_DIM_Y - 1.0f)},{ BOWSER_DIM_X,BOWSER_DIM_Y } };
	b.e.v = (Vec2){ -BOWSER_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Bowser_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Bowser_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Bowser_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Bowser_EntityCollision;
	
	b.startx = p.x;
	b.dir = 0;
	b.ground = 0;
	b.lifes = BOWSER_LIFES;
	b.start = 0UL;

	Bowser* hb = malloc(sizeof(Bowser));
	memcpy(hb,&b,sizeof(Bowser));
	return hb;
}


typedef struct Hammer {
	Entity e;
} Hammer;

typedef struct Bro {
	Entity e;
	float startx;
	char dir;
	char ground;
	Timepoint start;
} Bro;

void Bro_Free(Bro* e){
	Entity_Free(&e->e);
}
void Bro_Update(Bro* e,float t){
	e->ground = 0;

	const float dir = e->startx - e->e.r.p.x;
	if(F32_Abs(dir) > 2.0f){
		e->e.v.x = dir * BRO_VEL_X;
		e->e.r.p.x = e->startx - F32_Sign(dir) * 2.0f;
	}

	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Bro_WorldCollision(Bro* m,World* w){
	m->dir = (((MarioWorld*)w)->mario.e->r.p.x - m->e.r.p.x) < 0.0f ? 0 : 1; 
	
	const float dir = m->startx - m->e.r.p.x;
	if(F32_Abs(dir) > 1.0f){
		m->start = 0UL;
	}else{
		if(m->start == 0UL)
			m->start = Time_Nano();
	}

	if(m->ground && m->start > 0UL && Time_Elapsed(m->start,Time_Nano()) > BRO_THROW_DELAY){
		const Vec2 mp = Vec2_Add(m->e.r.p,Vec2_Mulf(m->e.r.d,0.5f));
		const Vec2 off = { (m->e.r.d.x + HAMMER_DIM_X) * 0.51f,0.0f };

		m->e.v.y = -BRO_VEL_Y;
		
		Hammer* s = (Hammer*)World_Spawn(
			w,
			ENTITY_HAMMER,
			Vec2_Add(
				Vec2_Sub(
					mp,
					Vec2_Mulf(
						(Vec2){ HAMMER_DIM_X,HAMMER_DIM_Y },
						0.5f
					)
				),
				Vec2_Mulf(
					off,
					m->dir == 0 ? -1.0f : 1.0f
				)
			)
		);
		s->e.v.x = HAMMER_VEL_X * F32_Sign(s->e.r.p.x - mp.x);
		s->e.v.y = -HAMMER_VEL_Y + m->e.v.y;

		m->start = 0UL;
	}

	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Bro_IsSolid(Bro* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Bro_Collision(Bro* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f){
		m->e.v.y = 0.0f;
		m->ground = 1;
	}
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Bro_EntityCollision(Bro* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Bro_GetRender(Bro* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 1.0f;
	d = d - F32_Floor(d);
	ox = (int)(3.0f * d);

	if(e->dir) ox = 5U - ox;

	dy *= 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Bro* Bro_New(Vec2 p){
	Bro b;
	b.e.id = ENTITY_BRO;
	b.e.r = (Rect){ { p.x,p.y - (BRO_DIM_Y - 1.0f)},{ BRO_DIM_X,BRO_DIM_Y } };
	b.e.v = (Vec2){ -BRO_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Bro_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Bro_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Bro_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Bro_EntityCollision;

	b.startx = p.x;
	b.dir = 0;
	b.ground = 0;
	b.start = 0UL;
	
	Bro* hb = malloc(sizeof(Bro));
	memcpy(hb,&b,sizeof(Bro));
	return hb;
}


typedef struct Coopa {
	Entity e;
	char inside;
} Coopa;

void Coopa_Free(Coopa* e){
	Entity_Free(&e->e);
}
void Coopa_Update(Coopa* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Coopa_WorldCollision(Coopa* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Coopa_IsSolid(Coopa* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Coopa_Collision(Coopa* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Coopa_EntityCollision(Coopa* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_BOWSER:		{
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_COOPA:		{
			Coopa* m2 = (Coopa*)other;

			char move1 = m->inside && m->e.v.x != 0.0f;
			char move2 = m2->inside && m2->e.v.x != 0.0f;

			if(move1 && move2){
				World_Remove(w,(Entity*)m);
				World_Remove(w,other);
			}else if(move1){
				World_Remove(w,other);
			}else if(move2){
				World_Remove(w,(Entity*)m);
			}else{
				m->e.v.x = F32_Abs(m->e.v.x) * F32_Sign(m->e.r.p.x - m2->e.r.p.x);
				m2->e.v.x = F32_Abs(m2->e.v.x) * F32_Sign(m2->e.r.p.x - m->e.r.p.x);
			}
			break;
		}
		case ENTITY_FIREJUMPER:	{
			
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,other);
			break;
		}
	}
}
SubSprite Coopa_GetRender(Coopa* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.5f;
	d = d - F32_Floor(d);
	unsigned int a = (int)(2.0f * d);
	ox = 2U + a;

	if(e->e.v.x > 0.0f) ox = 7U - ox;
	if(e->inside) 		ox = 8U + a;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Coopa* Coopa_New(Vec2 p){
	Coopa b;
	b.e.id = ENTITY_COOPA;
	b.e.r = (Rect){ { p.x,p.y - (COOPA_DIM_Y - 1.0f)},{ COOPA_DIM_X,COOPA_DIM_Y } };
	b.e.v = (Vec2){ -COOPA_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Coopa_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Coopa_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Coopa_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Coopa_EntityCollision;
	
	b.inside = 0;

	Coopa* hb = malloc(sizeof(Coopa));
	memcpy(hb,&b,sizeof(Coopa));
	return hb;
}


typedef struct FireJumper {
	Entity e;
} FireJumper;

void FireJumper_Free(FireJumper* e){
	Entity_Free(&e->e);
}
void FireJumper_Update(FireJumper* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void FireJumper_WorldCollision(FireJumper* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height){
		m->e.r.p.y = w->height;
		m->e.v.y *= -1.0f;
	}
}
char FireJumper_IsSolid(FireJumper* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	return 0;
}
void FireJumper_Collision(FireJumper* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void FireJumper_EntityCollision(FireJumper* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite FireJumper_GetRender(FireJumper* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	if(e->e.v.y > 0.0f) ox = 0U;
	if(e->e.v.y < 0.0f) ox = 1U;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
FireJumper* FireJumper_New(Vec2 p){
	FireJumper b;
	b.e.id = ENTITY_FIREJUMPER;
	b.e.r = (Rect){ { p.x,p.y - (FIREJUMPER_DIM_Y - 1.0f)},{ FIREJUMPER_DIM_X,FIREJUMPER_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))FireJumper_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))FireJumper_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))FireJumper_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))FireJumper_EntityCollision;
	
	FireJumper* hb = malloc(sizeof(FireJumper));
	memcpy(hb,&b,sizeof(FireJumper));
	return hb;
}


typedef struct Fish {
	Entity e;
} Fish;

void Fish_Free(Fish* e){
	Entity_Free(&e->e);
}
void Fish_Update(Fish* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Fish_WorldCollision(Fish* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height){
		m->e.r.p.y = w->height;
		m->e.v.y *= -1.0f;
	}
}
char Fish_IsSolid(Fish* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	return 0;
}
void Fish_Collision(Fish* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	//if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y *= -1.0f;
	//else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y *= -1.0f;
	//else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	//else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Fish_EntityCollision(Fish* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Fish_GetRender(Fish* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);

	if(e->e.v.x > 0.0f) ox = 3U - ox;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Fish* Fish_New(Vec2 p){
	Fish b;
	b.e.id = ENTITY_FISH;
	b.e.r = (Rect){ { p.x,p.y - (FISH_DIM_Y - 1.0f)},{ FISH_DIM_X,FISH_DIM_Y } };
	b.e.v = (Vec2){ -FISH_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Fish_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Fish_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Fish_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Fish_EntityCollision;
	
	Fish* hb = malloc(sizeof(Fish));
	memcpy(hb,&b,sizeof(Fish));
	return hb;
}


typedef struct Gumba {
	Entity e;
	char dead;
} Gumba;

void Gumba_Free(Gumba* e){
	Entity_Free(&e->e);
}
void Gumba_Update(Gumba* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Gumba_WorldCollision(Gumba* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Gumba_IsSolid(Gumba* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Gumba_Collision(Gumba* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Gumba_EntityCollision(Gumba* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Gumba_GetRender(Gumba* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);

	if(e->dead) ox = 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Gumba* Gumba_New(Vec2 p){
	Gumba b;
	b.e.id = ENTITY_GUMBA;
	b.e.r = (Rect){ { p.x,p.y - (GUMBA_DIM_Y - 1.0f)},{ GUMBA_DIM_X,GUMBA_DIM_Y } };
	b.e.v = (Vec2){ -BOWLER_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Gumba_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Gumba_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Gumba_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Gumba_EntityCollision;
	
	b.dead = 0;

	Gumba* hb = malloc(sizeof(Gumba));
	memcpy(hb,&b,sizeof(Gumba));
	return hb;
}


typedef struct Spike {
	Entity e;
	char ground;
} Spike;

typedef struct Lakitu {
	Entity e;
	Timepoint start;
} Lakitu;

void Lakitu_Free(Lakitu* e){
	Entity_Free(&e->e);
}
void Lakitu_Update(Lakitu* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Lakitu_WorldCollision(Lakitu* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);

	const float dir = ((MarioWorld*)w)->mario.e->r.p.x - m->e.r.p.x;
	if(F32_Abs(dir) > 1.0f){
		m->e.v.x = LAKITU_VEL_X * dir;
		m->start = 0UL;
	}else{
		if(m->start == 0UL)
			m->start = Time_Nano();
	}

	if(m->start > 0UL && Time_Elapsed(m->start,Time_Nano()) > LAKITU_THROW_DELAY){
		const Vec2 mp = Vec2_Add(m->e.r.p,Vec2_Mulf(m->e.r.d,0.5f));
		const Vec2 off = { (m->e.r.d.x + SPIKE_DIM_X),0.0f };
		
		Spike* s = (Spike*)World_Spawn(
			w,
			ENTITY_SPIKE,
			Vec2_Add(
				Vec2_Sub(
					mp,
					Vec2_Mulf(
						(Vec2){ SPIKE_DIM_X,SPIKE_DIM_Y },
						0.5f
					)
				),
				Vec2_Mulf(
					off,
					F32_Sign(m->e.v.x)
				)
			)
		);
		s->e.v.x = SPIKE_VEL_X * F32_Sign(s->e.r.p.x - mp.x);
		s->e.v.y = -SPIKE_VEL_Y + m->e.v.y;

		m->start = 0UL;
	}
}
char Lakitu_IsSolid(Lakitu* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	return 0;
}
void Lakitu_Collision(Lakitu* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Lakitu_EntityCollision(Lakitu* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Lakitu_GetRender(Lakitu* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	if(e->e.v.x > 0.0f) ox = 2U;
	if(e->start > 0UL && Time_Elapsed(e->start,Time_Nano()) > 0.5f * LAKITU_THROW_DELAY)
		ox = 1U;

	dy *= 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Lakitu* Lakitu_New(Vec2 p){
	Lakitu b;
	b.e.id = ENTITY_LAKITU;
	b.e.r = (Rect){ { p.x,p.y - (LAKITU_DIM_Y - 1.0f)},{ LAKITU_DIM_X,LAKITU_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,0.0f };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Lakitu_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Lakitu_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Lakitu_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Lakitu_EntityCollision;
	
	b.start = 0UL;

	Lakitu* hb = malloc(sizeof(Lakitu));
	memcpy(hb,&b,sizeof(Lakitu));
	return hb;
}


typedef struct PlantUG {
	Entity e;
} PlantUG;

void PlantUG_Free(PlantUG* e){
	Entity_Free(&e->e);
}
void PlantUG_Update(PlantUG* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void PlantUG_WorldCollision(PlantUG* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char PlantUG_IsSolid(PlantUG* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void PlantUG_Collision(PlantUG* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void PlantUG_EntityCollision(PlantUG* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite PlantUG_GetRender(PlantUG* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= 0.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);
	
	dy *= 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
PlantUG* PlantUG_New(Vec2 p){
	PlantUG b;
	b.e.id = ENTITY_PLANTUG;
	b.e.r = (Rect){ { p.x,p.y - (PLANTUG_DIM_Y - 1.0f)},{ PLANTUG_DIM_X,PLANTUG_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))PlantUG_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))PlantUG_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))PlantUG_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))PlantUG_EntityCollision;
	
	PlantUG* hb = malloc(sizeof(PlantUG));
	memcpy(hb,&b,sizeof(PlantUG));
	return hb;
}


typedef struct Plant {
	Entity e;
} Plant;

void Plant_Free(Plant* e){
	Entity_Free(&e->e);
}
void Plant_Update(Plant* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Plant_WorldCollision(Plant* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Plant_IsSolid(Plant* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Plant_Collision(Plant* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Plant_EntityCollision(Plant* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Plant_GetRender(Plant* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= 0.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);

	dy *= 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Plant* Plant_New(Vec2 p){
	Plant b;
	b.e.id = ENTITY_PLANT;
	b.e.r = (Rect){ { p.x,p.y - (PLANT_DIM_Y - 1.0f)},{ PLANT_DIM_X,PLANT_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Plant_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Plant_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Plant_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Plant_EntityCollision;
	
	Plant* hb = malloc(sizeof(Plant));
	memcpy(hb,&b,sizeof(Plant));
	return hb;
}



void Spike_Free(Spike* e){
	Entity_Free(&e->e);
}
void Spike_Update(Spike* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
	e->ground = 0;
}
void Spike_WorldCollision(Spike* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Spike_IsSolid(Spike* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Spike_Collision(Spike* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f){
		m->e.v.y = 0.0f;
		m->ground = 1;
	}
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Spike_EntityCollision(Spike* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Spike_GetRender(Spike* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.5f;
	d = d - F32_Floor(d);
	unsigned int a = (int)(2.0f * d);

	ox = a;
	if(e->e.v.x > 0.0f) ox = 3 - ox;
	if(!e->ground)		ox = 5 - a;
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Spike* Spike_New(Vec2 p){
	Spike b;
	b.e.id = ENTITY_SPIKE;
	b.e.r = (Rect){ { p.x,p.y - (SPIKE_DIM_Y - 1.0f)},{ SPIKE_DIM_X,SPIKE_DIM_Y } };
	b.e.v = (Vec2){ -SPIKE_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Spike_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Spike_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Spike_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Spike_EntityCollision;
	
	b.ground = 0;

	Spike* hb = malloc(sizeof(Spike));
	memcpy(hb,&b,sizeof(Spike));
	return hb;
}


typedef struct Squid {
	Entity e;
} Squid;

void Squid_Free(Squid* e){
	Entity_Free(&e->e);
}
void Squid_Update(Squid* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Squid_WorldCollision(Squid* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Squid_IsSolid(Squid* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Squid_Collision(Squid* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Squid_EntityCollision(Squid* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Squid_GetRender(Squid* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	dy *= 2;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Squid* Squid_New(Vec2 p){
	Squid b;
	b.e.id = ENTITY_SQUID;
	b.e.r = (Rect){ { p.x,p.y - (SQUID_DIM_Y - 1.0f)},{ SQUID_DIM_X,SQUID_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Squid_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Squid_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Squid_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Squid_EntityCollision;
	
	Squid* hb = malloc(sizeof(Squid));
	memcpy(hb,&b,sizeof(Squid));
	return hb;
}


typedef struct Willi {
	Entity e;
} Willi;

void Willi_Free(Willi* e){
	Entity_Free(&e->e);
}
void Willi_Update(Willi* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Willi_WorldCollision(Willi* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Willi_IsSolid(Willi* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Willi_Collision(Willi* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Willi_EntityCollision(Willi* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	
}
SubSprite Willi_GetRender(Willi* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	if(e->e.v.x > 0.0f) ox = 1 - ox;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Willi* Willi_New(Vec2 p){
	Willi b;
	b.e.id = ENTITY_WILLI;
	b.e.r = (Rect){ { p.x,p.y - (WILLI_DIM_Y - 1.0f)},{ WILLI_DIM_X,WILLI_DIM_Y } };
	b.e.v = (Vec2){ -WILLI_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,0.0f };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Willi_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Willi_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Willi_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Willi_EntityCollision;
	
	Willi* hb = malloc(sizeof(Willi));
	memcpy(hb,&b,sizeof(Willi));
	return hb;
}


typedef struct Explosion {
	Entity e;
} Explosion;

void Explosion_Free(Explosion* e){
	Entity_Free(&e->e);
}
void Explosion_Update(Explosion* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Explosion_WorldCollision(Explosion* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Explosion_IsSolid(Explosion* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Explosion_Collision(Explosion* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Explosion_EntityCollision(Explosion* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_BOWSER:		{
			Bowser_Damage((Bowser*)other,w,1U);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_COOPA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,other);
			break;
		}
	}
}
SubSprite Explosion_GetRender(Explosion* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 1.5f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(3.0f * d);

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Explosion* Explosion_New(Vec2 p){
	Explosion b;
	b.e.id = ENTITY_EXPLOSION;
	b.e.r = (Rect){ { p.x,p.y - (EXPLOSION_DIM_Y - 1.0f)},{ EXPLOSION_DIM_X,EXPLOSION_DIM_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,0.0f };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Explosion_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Explosion_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Explosion_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Explosion_EntityCollision;
	
	Explosion* hb = malloc(sizeof(Explosion));
	memcpy(hb,&b,sizeof(Explosion));
	return hb;
}


typedef struct Fireball {
	Entity e;
	unsigned char bounce;
} Fireball;

void Fireball_Free(Fireball* e){
	Entity_Free(&e->e);
}
void Fireball_Update(Fireball* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Fireball_WorldCollision(Fireball* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Fireball_IsSolid(Fireball* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Fireball_Collision(Fireball* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f){
		m->e.v.y = -FIREBALL_VEL_Y;
		m->bounce--;
		if(m->bounce == 0U) World_Remove(w,(Entity*)m);
	}else if(s==SIDE_BOTTOM && m->e.v.y<0.0f){
		m->e.v.y = FIREBALL_VEL_Y;
		m->bounce--;
		if(m->bounce == 0U) World_Remove(w,(Entity*)m);
	}else if(s==SIDE_LEFT && m->e.v.x>0.0f){
		m->e.v.x *= -1.0f;
		m->bounce--;
		if(m->bounce == 0U) World_Remove(w,(Entity*)m);
	}else if(s==SIDE_RIGHT && m->e.v.x<0.0f){
		m->e.v.x *= -1.0f;
		m->bounce--;
		if(m->bounce == 0U) World_Remove(w,(Entity*)m);
	}
}
void Fireball_EntityCollision(Fireball* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BOWSER:		{
			Bowser_Damage((Bowser*)other,w,1U);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_COOPA:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,(Entity*)m);
			break;
		}
	}
}
SubSprite Fireball_GetRender(Fireball* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.25f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(4.0f * d);

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Fireball* Fireball_New(Vec2 p){
	Fireball b;
	b.e.id = ENTITY_FIREBALL;
	b.e.r = (Rect){ { p.x,p.y - (FIREBALL_DIM_Y - 1.0f)},{ FIREBALL_DIM_X,FIREBALL_DIM_Y } };
	b.e.v = (Vec2){ -FIREBALL_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Fireball_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Fireball_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Fireball_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Fireball_EntityCollision;
	
	b.bounce = FIREBALL_BOUNCE;

	Fireball* hb = malloc(sizeof(Fireball));
	memcpy(hb,&b,sizeof(Fireball));
	return hb;
}


void Firebeam_Free(Firebeam* e){
	Entity_Free(&e->e);
}
void Firebeam_Update(Firebeam* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Firebeam_WorldCollision(Firebeam* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Firebeam_IsSolid(Firebeam* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Firebeam_Collision(Firebeam* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		World_Remove(w,(Entity*)m);
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	World_Remove(w,(Entity*)m);
}
void Firebeam_EntityCollision(Firebeam* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_BOWSER:		{
			Bowser_Damage((Bowser*)other,w,1U);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_COOPA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,other);
			break;
		}
	}
}
SubSprite Firebeam_GetRender(Firebeam* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	dx *= 2;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 1.0f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(2.0f * d);

	if(e->e.v.x > 0.0f) ox = 3 - ox;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Firebeam* Firebeam_New(Vec2 p){
	Firebeam b;
	b.e.id = ENTITY_FIREBEAM;
	b.e.r = (Rect){ { p.x,p.y - (FIREBEAM_DIM_Y - 1.0f)},{ FIREBEAM_DIM_X,FIREBEAM_DIM_Y } };
	b.e.v = (Vec2){ -FIREBEAM_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,0.0f };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Firebeam_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Firebeam_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Firebeam_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Firebeam_EntityCollision;
	
	Firebeam* hb = malloc(sizeof(Firebeam));
	memcpy(hb,&b,sizeof(Firebeam));
	return hb;
}


void Hammer_Free(Hammer* e){
	Entity_Free(&e->e);
}
void Hammer_Update(Hammer* e,float t){
	e->e.v = Vec2_Add(e->e.v,Vec2_Mulf(e->e.a,t));
	e->e.r.p = Vec2_Add(e->e.r.p,Vec2_Mulf(e->e.v,t));
}
void Hammer_WorldCollision(Hammer* m,World* w){
	if(m->e.r.p.x < -m->e.r.d.x) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y < -m->e.r.d.y) 	World_Remove(w,(Entity*)m);
	else if(m->e.r.p.x>w->width) 		World_Remove(w,(Entity*)m);
	else if(m->e.r.p.y>w->height) 		World_Remove(w,(Entity*)m);
}
char Hammer_IsSolid(Hammer* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);
	if(b==BLOCK_COIN)				return 0;
	else if(b==BLOCK_FIRE_FLOWER)	return 0;
	else if(b==BLOCK_SUPER_STAR) 	return 0;

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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}

	return 1;
}
void Hammer_Collision(Hammer* m,World* w,unsigned int x,unsigned int y,Side s){
	Block b = World_Get(w,x,y);

	if(s==SIDE_TOP && m->e.v.y>0.0f)			World_Remove(w,(Entity*)m);
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f)	World_Remove(w,(Entity*)m);
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x *= -1.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x *= -1.0f;
}
void Hammer_EntityCollision(Hammer* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	switch (other->id){
		case ENTITY_BOWLER:		{
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BOWSER:		{
			Bowser_Damage((Bowser*)other,w,1U);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_BRO:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_COOPA:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_FISH:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_GUMBA:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_LAKITU:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_PLANT:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_PLANTUG:	{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_SPIKE:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_SQUID:		{
			World_Remove(w,other);
			World_Remove(w,(Entity*)m);
			break;
		}
		case ENTITY_WILLI:		{
			World_Remove(w,(Entity*)m);
			break;
		}
	}
}
SubSprite Hammer_GetRender(Hammer* e,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;

	FDuration d = Time_Elapsed(0UL,Time_Nano());
	d = d - F32_Floor(d);
	d *= F32_Abs(e->e.v.x) * 0.25f;
	d = d - F32_Floor(d);
	ox = 0U + (int)(4.0f * d);
	
	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
Hammer* Hammer_New(Vec2 p){
	Hammer b;
	b.e.id = ENTITY_HAMMER;
	b.e.r = (Rect){ { p.x,p.y - (HAMMER_DIM_Y - 1.0f)},{ HAMMER_DIM_X,HAMMER_DIM_Y } };
	b.e.v = (Vec2){ -HAMMER_VEL_X,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	
	b.e.WorldCollision = (void(*)(Entity*,World*))Hammer_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Hammer_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Hammer_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Hammer_EntityCollision;
	
	Hammer* hb = malloc(sizeof(Hammer));
	memcpy(hb,&b,sizeof(Hammer));
	return hb;
}



typedef struct Mario {
	Entity e;
	Vec2 spawn;
	Timepoint start;
	unsigned char lookdir;
	unsigned char ground;
	unsigned char jumping;
	unsigned char stamp;
	unsigned char slide;
	unsigned char reverse;
	unsigned char power;
	unsigned char dead;
} Mario;

void Mario_Move(Mario* m,const float dir){//dir := [-1;1]
	if(m->dead){
		m->e.v.x = 0.0f;
		m->e.a.x = 0.0f;
		return;
	}
	
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
void Mario_Die(Mario* m,World* w){
	AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Dead.wav");
	m->dead = ENTITY_TRUE;
	m->e.v.y = -MARIO_VEL_DEAD;
}
void Mario_Stamp(Mario* m){
	if(!m->stamp && !m->slide){
		if(m->ground){
			if(m->e.v.x == 0.0f)	m->stamp = ENTITY_TRUE;
			else					m->slide = ENTITY_TRUE;
		}else{
			m->stamp = ENTITY_TRUE;
			m->slide = ENTITY_TRUE;
			m->e.v.y = MARIO_VEL_JP;
		}
	}else{
		if(m->stamp) m->e.v.x = 0.0f;
	}
}
void Mario_Respawn(Mario* m,Vec2 spawn){
	m->e.r.p = spawn;
	m->dead = ENTITY_FALSE;

	m->e.v.x = 0.0f;
	m->e.v.y = 0.0f;
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
		m->e.r.p.y = w->height - m->e.r.d.y;
		Mario_Die(m,w);
	}
	if(m->dead && m->e.r.p.y>w->height){
		Mario_Respawn(m,w->spawn);
	}

	//m->stamp = FIGURE_FALSE;
	m->jumping = ENTITY_FALSE;
	m->reverse = FIGURE_FALSE;
}
char Mario_IsSolid(Mario* m,World* w,unsigned int x,unsigned int y,Side s){
	if(m->dead) return 0;
	
	Block b = World_Get(w,x,y);

	if(b==BLOCK_COIN){
		AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Coin.wav");
		World_Set(w,x,y,BLOCK_NONE);
		return 0;
	//}else if(b==BLOCK_REDPILZ){
	//	AudioPlayer_Add(&ap,"./data/Sound/upgrade.wav");
	//	World_Set(w,x,y,BLOCK_NONE);
	//	f->power = 1;
	//	f->r.d.y = 1.8f;
	//	return 0;
	//}else if(b==BLOCK_GREENPILZ){
	//	AudioPlayer_Add(&ap,"./data/Sound/OneUp.wav");
	//	World_Set(w,x,y,BLOCK_NONE);
	//	f->power = 0;
	//	f->r.d.y = 0.9f;
	//	return 0;
	}else if(b==BLOCK_FIRE_FLOWER){
		AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Powerup.wav");
		World_Set(w,x,y,BLOCK_NONE);
		m->power = 2;
        m->e.r.p.x -= MARIO_DIM_P2_X - m->e.r.d.x;
		m->e.r.p.y -= MARIO_DIM_P2_Y - m->e.r.d.y;
		m->e.r.d.x = MARIO_DIM_P2_X;
		m->e.r.d.y = MARIO_DIM_P2_Y;
		return 0;
	}else if(b==BLOCK_SUPER_STAR){
		AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Powerup.wav");
		World_Set(w,x,y,BLOCK_NONE);
		//m->power = 3;
        //m->e.r.p.x -= MARIO_DIM_P3_X - m->e.r.d.x;
		//m->e.r.p.y -= MARIO_DIM_P3_Y - m->e.r.d.y;
		//m->e.r.d.x = MARIO_DIM_P3_X;
		//m->e.r.d.y = MARIO_DIM_P3_Y;
		m->power = 1;
        m->e.r.p.x -= MARIO_DIM_P1_X - m->e.r.d.x;
		m->e.r.p.y -= MARIO_DIM_P1_Y - m->e.r.d.y;
		m->e.r.d.x = MARIO_DIM_P1_X;
		m->e.r.d.y = MARIO_DIM_P1_Y;
		return 0;
	}
	
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
		case BLOCK_SPAWN_FIREJUMPER:return 0;
		case BLOCK_SPAWN_FISH:		return 0;
		case BLOCK_SPAWN_GUMBA:		return 0;
		case BLOCK_SPAWN_LAKITU:	return 0;
		case BLOCK_SPAWN_PLANT:		return 0;
		case BLOCK_SPAWN_PLANTUG:	return 0;
		case BLOCK_SPAWN_SPIKE:		return 0;
		case BLOCK_SPAWN_SQUID:		return 0;
		case BLOCK_SPAWN_WILLI:		return 0;
		case BLOCK_SPAWN_EXPLOSION:	return 0;
		case BLOCK_SPAWN_FIREBALL:	return 0;
		case BLOCK_SPAWN_FIREBEAM:	return 0;
		case BLOCK_SPAWN_HAMMER:	return 0;
	}
	
	return 1;
}
void Mario_Collision(Mario* m,World* w,unsigned int x,unsigned int y,Side s){
	if(m->dead) return;
	
	if(s==SIDE_TOP && m->e.v.y>0.0f) 			m->e.v.y = 0.0f;
	else if(s==SIDE_BOTTOM && m->e.v.y<0.0f) 	m->e.v.y = 0.0f;
	else if(s==SIDE_LEFT && m->e.v.x>0.0f) 		m->e.v.x = 0.0f;
	else if(s==SIDE_RIGHT && m->e.v.x<0.0f) 	m->e.v.x = 0.0f;

	Block b = World_Get(w,x,y);
	
    if(s==SIDE_TOP)
        m->ground = FIGURE_TRUE;

	if(s==SIDE_BOTTOM || (s==SIDE_TOP && m->stamp && m->e.v.x==0.0f)){
		if(b==BLOCK_BRICK){
			AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Breakblock.wav");
			World_Set(w,x,y,BLOCK_NONE);
		}else{
			AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/Bump.wav");
		}
		
		if(b==BLOCK_CLOSE_QUEST_FF){
			AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/PowerupSpawn.wav");
			World_Set(w,x,y,BLOCK_SOLID);
			World_Set(w,x,y-1,BLOCK_FIRE_FLOWER);
		}else if(b==BLOCK_CLOSE_QUEST_SS){
			AudioPlayer_Add(&((MarioWorld*)w)->ap,"./data/Sound/PowerupSpawn.wav");
			World_Set(w,x,y,BLOCK_SOLID);
			World_Set(w,x,y-1,BLOCK_SUPER_STAR);
		}
	}
}
void Mario_EntityCollision(Mario* m,World* w,Entity* other,unsigned int x,unsigned int y,Side s){
	if(m->dead) return;
	
	switch (other->id){
		case ENTITY_BOWLER:		{
			if(s == SIDE_TOP){
				Bowler* b = (Bowler*)other;
				if(!b->inside){
					b->inside = 1;
					b->e.v.x = 0.0f;
				}else{
					if(b->e.v.x != 0.0f) 
						b->e.v.x = 0.0f;
					else{
						const float dir = F32_Sign(b->e.r.p.x - m->e.r.p.x);
						b->e.v.x = dir * BOWLER_VEL_ROLLX;
					}
				}
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_BOWSER:		{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_BRO:		{
			if(s == SIDE_TOP){
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
				World_Remove(w,other);
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_COOPA:		{
			if(s == SIDE_TOP){
				Coopa* b = (Coopa*)other;
				if(!b->inside){
					b->inside = 1;
					b->e.v.x = 0.0f;
				}else{
					if(b->e.v.x != 0.0f) 
						b->e.v.x = 0.0f;
					else{
						const float dir = F32_Sign(b->e.r.p.x - m->e.r.p.x);
						b->e.v.x = dir * COOPA_VEL_ROLLX;
					}
				}
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_EXPLOSION:	{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_FIREBALL:	{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_FIREBEAM:	{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_FIREJUMPER:	{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_FISH:		{
			if(s == SIDE_TOP){
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
				World_Remove(w,other);
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_GUMBA:		{
			if(s == SIDE_TOP){
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
				World_Remove(w,other);
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_HAMMER:		{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_LAKITU:		{
			if(s == SIDE_TOP){
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
				World_Remove(w,other);
			}else
				Mario_Die(m,w);
			break;
		}
		case ENTITY_PLANT:		{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_PLANTUG:	{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_SPIKE:		{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_SQUID:		{
			Mario_Die(m,w);
			break;
		}
		case ENTITY_WILLI:		{
			if(s == SIDE_TOP){
				Resolve_Rect_Rect_Side(&m->e.r,other->r,s);
				m->e.v.y = -MARIO_VEL_JP;
				World_Remove(w,other);
			}else
				Mario_Die(m,w);
			break;
		}
	}
}
SubSprite Mario_GetRender(Mario* m,EntityAtlas* ea){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = ea->atlas.w / ea->cx;
	unsigned int dy = ea->atlas.h / ea->cy;
	
	if(m->dead)				        ox = 2U,oy = 1U;
	else if(!m->ground){
		if(!m->stamp)		        ox = 2U,oy = 0U;
		else if(m->power==0)		ox = 1U,oy = 1U;
		else						ox = 1U,oy = 0U;
	}else if(m->stamp){
		if(m->power==0)				ox = 1U,oy = 1U;
		else						ox = 1U,oy = 0U;
	}else if(m->slide){
		if(m->ground)	        	ox = 1U,oy = 1U;
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

	if(!m->dead && m->power==1)			        oy = 1.0f + oy,dy *= 2;
	else if(!m->dead && m->power==2)	        oy = 3.0f + oy,dy *= 2;
	//else if(!m->dead && m->power==3)	        oy = 0.0f + oy;

	if(m->lookdir==ENTITY_RIGHT)    ox = 15U - ox;

	m->stamp = ENTITY_FALSE;
	m->slide = ENTITY_FALSE;

	return SubSprite_New(&ea->atlas,ox * dx,oy * dy,dx,dy);
}
void Mario_Free(Mario* m){
	Entity_Free(&m->e);
}
Mario* Mario_New(Vec2 p){
	Mario b;
	b.e.id = ENTITY_MARIO;
	b.e.r = (Rect){ { p.x,p.y - (MARIO_DIM_P0_Y - 1.0f)},{ MARIO_DIM_P0_X,MARIO_DIM_P0_Y } };
	b.e.v = (Vec2){ 0.0f,0.0f };
	b.e.a = (Vec2){ 0.0f,MARIO_ACC_GRAVITY };
	b.e.WorldCollision = (void(*)(Entity*,World*))Mario_WorldCollision;
	b.e.IsSolid = (char(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_IsSolid;
	b.e.Collision = (void(*)(Entity*,World*,unsigned int,unsigned int,Side))Mario_Collision;
	b.e.EntityCollision = (void(*)(Entity*,World*,Entity*,unsigned int,unsigned int,Side))Mario_EntityCollision;

	b.spawn = p;
	b.start = 0UL;
	b.lookdir = ENTITY_RIGHT;
	b.ground = ENTITY_FALSE;
	b.jumping = ENTITY_FALSE;
	b.stamp = ENTITY_FALSE;
	b.slide = ENTITY_FALSE;
	b.reverse = ENTITY_FALSE;
	b.power = 0;
	b.dead = ENTITY_FALSE;

	Mario* hb = malloc(sizeof(Mario));
	memcpy(hb,&b,sizeof(Mario));
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
		case 'U':	return BLOCK_SPAWN_PLANTUG;
		case 'P':	return BLOCK_SPAWN_PLANT;
		case '^':	return BLOCK_SPAWN_SPIKE;
		case 'Q':	return BLOCK_SPAWN_SQUID;
		case 'I':	return BLOCK_SPAWN_WILLI;
		case 'x':	return BLOCK_SPAWN_EXPLOSION;
		case 'l':	return BLOCK_SPAWN_FIREBALL;
		case 'a':	return BLOCK_SPAWN_FIREBEAM;
		case 'm':	return BLOCK_SPAWN_HAMMER;
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
		case BLOCK_SPAWN_PLANTUG:		return 'U';
		case BLOCK_SPAWN_PLANT:			return 'P';
		case BLOCK_SPAWN_SPIKE:			return '^';
		case BLOCK_SPAWN_SQUID:			return 'Q';
		case BLOCK_SPAWN_WILLI:			return 'I';
		case BLOCK_SPAWN_EXPLOSION:		return 'x';
		case BLOCK_SPAWN_FIREBALL:		return 'l';
		case BLOCK_SPAWN_FIREBEAM:		return 'a';
		case BLOCK_SPAWN_HAMMER:		return 'm';
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
		case ENTITY_PLANTUG:	*size = sizeof(PlantUG); 	return PlantUG_New(p);
		case ENTITY_PLANT:		*size = sizeof(Plant); 		return Plant_New(p);
		case ENTITY_SPIKE:		*size = sizeof(Spike); 		return Spike_New(p);
		case ENTITY_SQUID:		*size = sizeof(Squid);	 	return Squid_New(p);
		case ENTITY_WILLI:		*size = sizeof(Willi); 		return Willi_New(p);
		case ENTITY_EXPLOSION:	*size = sizeof(Explosion); 	return Explosion_New(p);
		case ENTITY_FIREBALL:	*size = sizeof(Fireball); 	return Fireball_New(p);
		case ENTITY_FIREBEAM:	*size = sizeof(Firebeam);	return Firebeam_New(p);
		case ENTITY_HAMMER:		*size = sizeof(Hammer); 	return Hammer_New(p);
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
SubSprite MarioWorld_Plant_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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

SubSprite MarioWorld_Explosion_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Fireball_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Firebeam_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite MarioWorld_Hammer_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}


MarioWorld MarioWorld_New(char* path_lvl,char* path_blocks,char* path_entities,char* path_shooters){
    MarioWorld mw;
    mw.mario = Figure_New(
		Mario_New((Vec2){ 0.0f,0.0f }),
		(void(*)(Entity*,World*,const float))Mario_Update,
		(void(*)(Entity*,const float))Mario_Move,
		(void(*)(Entity*))Mario_Free
	);

	mw.tv = TransformedView_New((Vec2){ GetHeight(),GetHeight() });
	TransformedView_Zoom(&mw.tv,(Vec2){ 0.05f,0.05f });
	//TransformedView_Offset(&tv,(Vec2){ -0.5f,0.0f });
	TransformedView_Focus(&mw.tv,&mw.mario.e->r.p);

	mw.ap = AudioPlayer_New();

	mw.selected = BLOCK_NONE;
	mw.level = 0U;
	mw.world = World_Make(path_lvl,BLOCK_SPAWN,MarioWorld_Std_Mapper,MarioWorld_Std_SpawnMapper,
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
		    Animation_Make_AtlasPath(path_entities,"PlantUG.png",ANIMATIONBG_DG,ENTITY_PLANTUG,2,1,MarioWorld_PlantUG_Get),
		    Animation_Make_AtlasPath(path_entities,"Plant.png",ANIMATIONBG_DG,ENTITY_PLANT,2,1,MarioWorld_Plant_Get),
		    Animation_Make_AtlasPath(path_entities,"Spike.png",ANIMATIONBG_DG,ENTITY_SPIKE,6,1,MarioWorld_Spike_Get),
		    Animation_Make_AtlasPath(path_entities,"Squid.png",ANIMATIONBG_DG,ENTITY_SQUID,2,1,MarioWorld_Squid_Get),
		    Animation_Make_AtlasPath(path_entities,"Willi.png",ANIMATIONBG_DG,ENTITY_WILLI,2,1,MarioWorld_Willi_Get),
		    Animation_Make_AtlasPath(path_shooters,"Explosion.png",ANIMATIONBG_DG,ENTITY_EXPLOSION,3,1,MarioWorld_Explosion_Get),
		    Animation_Make_AtlasPath(path_shooters,"Fireball.png",ANIMATIONBG_DG,ENTITY_FIREBALL,4,1,MarioWorld_Fireball_Get),
		    Animation_Make_AtlasPath(path_shooters,"Firebeam.png",ANIMATIONBG_DG,ENTITY_FIREBEAM,8,1,MarioWorld_Firebeam_Get),
		    Animation_Make_AtlasPath(path_shooters,"Hammer.png",ANIMATIONBG_DG,ENTITY_HAMMER,4,2,MarioWorld_Hammer_Get),
		    Animation_Null()
	    },
        (EntityAtlas[]){
		    EntityAtlas_New(path_entities,"Mario.png",16,12,	(void(*)(void*,const float))Mario_Update,		(SubSprite(*)(void*,EntityAtlas*))Mario_GetRender,		(void(*)(void*))Mario_Free),
		    EntityAtlas_New(path_entities,"Bowler.png",5,3,		(void(*)(void*,const float))Bowler_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowler_GetRender,		(void(*)(void*))Bowler_Free),
		    EntityAtlas_New(path_entities,"Bowser.png",16,2,	(void(*)(void*,const float))Bowser_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowser_GetRender,		(void(*)(void*))Bowser_Free),
		    EntityAtlas_New(path_entities,"Bro.png",6,4,		(void(*)(void*,const float))Bro_Update,			(SubSprite(*)(void*,EntityAtlas*))Bro_GetRender,		(void(*)(void*))Bro_Free),
		    EntityAtlas_New(path_entities,"Coopa.png",10,3,		(void(*)(void*,const float))Coopa_Update,		(SubSprite(*)(void*,EntityAtlas*))Coopa_GetRender,		(void(*)(void*))Coopa_Free),
		    EntityAtlas_New(path_entities,"FireJumper.png",2,1,	(void(*)(void*,const float))FireJumper_Update,	(SubSprite(*)(void*,EntityAtlas*))FireJumper_GetRender,	(void(*)(void*))FireJumper_Free),
		    EntityAtlas_New(path_entities,"Fish.png",4,3,		(void(*)(void*,const float))Fish_Update,		(SubSprite(*)(void*,EntityAtlas*))Fish_GetRender,		(void(*)(void*))Fish_Free),
		    EntityAtlas_New(path_entities,"Gumba.png",3,3,		(void(*)(void*,const float))Gumba_Update,		(SubSprite(*)(void*,EntityAtlas*))Gumba_GetRender,		(void(*)(void*))Gumba_Free),
		    EntityAtlas_New(path_entities,"Lakitu.png",3,2,		(void(*)(void*,const float))Lakitu_Update,		(SubSprite(*)(void*,EntityAtlas*))Lakitu_GetRender,		(void(*)(void*))Lakitu_Free),
		    EntityAtlas_New(path_entities,"PlantUG.png",2,2,	(void(*)(void*,const float))PlantUG_Update,		(SubSprite(*)(void*,EntityAtlas*))PlantUG_GetRender,	(void(*)(void*))PlantUG_Free),
		    EntityAtlas_New(path_entities,"Plant.png",2,2,		(void(*)(void*,const float))Plant_Update,		(SubSprite(*)(void*,EntityAtlas*))Plant_GetRender,		(void(*)(void*))Plant_Free),
		    EntityAtlas_New(path_entities,"Spike.png",6,1,		(void(*)(void*,const float))Spike_Update,		(SubSprite(*)(void*,EntityAtlas*))Spike_GetRender,		(void(*)(void*))Spike_Free),
		    EntityAtlas_New(path_entities,"Squid.png",2,2,		(void(*)(void*,const float))Squid_Update,		(SubSprite(*)(void*,EntityAtlas*))Squid_GetRender,		(void(*)(void*))Squid_Free),
		    EntityAtlas_New(path_entities,"Willi.png",2,1,		(void(*)(void*,const float))Willi_Update,		(SubSprite(*)(void*,EntityAtlas*))Willi_GetRender,		(void(*)(void*))Willi_Free),
		    EntityAtlas_New(path_shooters,"Explosion.png",3,1,	(void(*)(void*,const float))Explosion_Update,	(SubSprite(*)(void*,EntityAtlas*))Explosion_GetRender,	(void(*)(void*))Explosion_Free),
		    EntityAtlas_New(path_shooters,"Fireball.png",4,1,	(void(*)(void*,const float))Fireball_Update,	(SubSprite(*)(void*,EntityAtlas*))Fireball_GetRender,	(void(*)(void*))Fireball_Free),
		    EntityAtlas_New(path_shooters,"Firebeam.png",8,1,	(void(*)(void*,const float))Firebeam_Update,	(SubSprite(*)(void*,EntityAtlas*))Firebeam_GetRender,	(void(*)(void*))Firebeam_Free),
		    EntityAtlas_New(path_shooters,"Hammer.png",4,2,		(void(*)(void*,const float))Hammer_Update,		(SubSprite(*)(void*,EntityAtlas*))Hammer_GetRender,		(void(*)(void*))Hammer_Free),
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