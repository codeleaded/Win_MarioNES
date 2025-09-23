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

Figure mario;
World world;
TransformedView tv;
AudioPlayer ap;
unsigned int level = 0;
Block selected = BLOCK_NONE;
PS4_Controller ps4c;

Block World_Std_Mapper(char c){
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
char World_Std_MapperR(Block b){
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
void* World_Std_SpawnMapper(Vec2 p,SpawnType st,unsigned int* size){
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

SubSprite World_Tube_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_SilverTube_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Bush_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Castle_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Cloud_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Fence_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Flag_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Tree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_SnowTree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_BackTree_Get(Animation* a,World* w,unsigned int x,unsigned int y){
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
SubSprite World_Rocket_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w / a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}

SubSprite World_Bowler_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Bowser_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Bro_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Coopa_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_FireJumper_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Fish_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Gumba_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Lakitu_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_PlantUG_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_PLant_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Spike_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Squid_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}
SubSprite World_Willi_Get(Animation* a,World* w,unsigned int x,unsigned int y){
	unsigned int ox = 0U;
	unsigned int oy = 0U;
	unsigned int dx = a->atlas_img.w /	a->atlas_cx;
	unsigned int dy = a->atlas_img.h / a->atlas_cy;

	//if(World_Get(w,x,y - 1) != BLOCK_ROCKET) 	ox = 0U;
	//else 										ox = 1U;
	
	return SubSprite_New(&a->atlas_img,ox * dx,oy * dy,dx,dy);
}

void Setup(AlxWindow* w){
	AlxFont_Resize(&window.AlxFont,16,16);

	ps4c = PS4_Controller_New("/dev/input/by-id/usb-Sony_Interactive_Entertainment_Wireless_Controller-if03-event-joystick");

	mario = Figure_New(
		Mario_New((Vec2){ 1.0f,25.0f }),
		(void(*)(Entity*,World*,const float))Mario_Update,
		(void(*)(Entity*,const float))Mario_Move,
		(void(*)(Entity*))Mario_Free
	);

	tv = TransformedView_New((Vec2){ GetHeight(),GetHeight() });
	TransformedView_Zoom(&tv,(Vec2){ 0.1f,0.1f });
	//TransformedView_Offset(&tv,(Vec2){ -0.5f,0.0f });
	TransformedView_Focus(&tv,&mario.e->r.p);

	ap = AudioPlayer_New();
	AudioPlayer_Start(&ap);

	level = 0U;
	world = World_Make("./data/World/Level0.txt",BLOCK_SPAWN,World_Std_Mapper,(Animation[]){
		Animation_Make_Sprite("./data/Blocks/Dirt.png",ANIMATIONBG_BG,ENTITY_NONE),
		Animation_Make_Sprite("./data/Blocks/Brick.png",ANIMATIONBG_BG,ENTITY_NONE),
		Animation_Make_AnimationAtlas("./data/Blocks/QuestionMark.png",ANIMATIONBG_BG,ENTITY_NONE,3,1,1.0),
		Animation_Make_AnimationAtlas("./data/Blocks/QuestionMark.png",ANIMATIONBG_BG,ENTITY_NONE,3,1,1.0),
		Animation_Make_AnimationAtlas("./data/Blocks/Coin.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,1.0),
		Animation_Make_Sprite("./data/Blocks/Podest.png",ANIMATIONBG_BG,ENTITY_NONE),
		Animation_Make_Sprite("./data/Blocks/Solid.png",ANIMATIONBG_BG,ENTITY_NONE),
		Animation_Make_Atlas("./data/Blocks/Tube.png",ANIMATIONBG_BG,ENTITY_NONE,16,1,World_Tube_Get),
		Animation_Make_Atlas("./data/Blocks/SilverTube.png",ANIMATIONBG_BG,ENTITY_NONE,16,1,World_SilverTube_Get),
		Animation_Make_AnimationAtlas("./data/Blocks/FireFlower.png",ANIMATIONBG_BG,ENTITY_NONE,4,2,1.0),
		Animation_Make_AnimationAtlas("./data/Blocks/SuperStar.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,1.0),
		Animation_Make_Atlas("./data/Blocks/Bush.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,World_Bush_Get),
		Animation_Make_Atlas("./data/Blocks/Castle.png",ANIMATIONBG_FG,ENTITY_NONE,6,1,World_Castle_Get),
		Animation_Make_Atlas("./data/Blocks/Cloud.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,World_Cloud_Get),
		Animation_Make_Atlas("./data/Blocks/Fence.png",ANIMATIONBG_FG,ENTITY_NONE,4,1,World_Fence_Get),
		Animation_Make_Atlas("./data/Blocks/Flag.png",ANIMATIONBG_FG,ENTITY_NONE,2,1,World_Flag_Get),
		Animation_Make_Sprite("./data/Blocks/Dirt.png",ANIMATIONBG_FG,ENTITY_NONE),
		Animation_Make_Atlas("./data/Blocks/Tree.png",ANIMATIONBG_BG,ENTITY_NONE,7,1,World_Tree_Get),
		Animation_Make_Atlas("./data/Blocks/SnowTree.png",ANIMATIONBG_FG,ENTITY_NONE,7,1,World_SnowTree_Get),
		Animation_Make_Atlas("./data/Blocks/BackTree.png",ANIMATIONBG_BG,ENTITY_NONE,4,1,World_BackTree_Get),
		Animation_Make_Atlas("./data/Blocks/Rocket.png",ANIMATIONBG_BG,ENTITY_NONE,2,1,World_Rocket_Get),

		Animation_Make_Sprite("./data/Blocks/Solid.png",ANIMATIONBG_DG,ENTITY_NONE),

		Animation_Make_Atlas("./data/Entity/Bowler.png",ANIMATIONBG_DG,ENTITY_BOWLER,5,3,World_Bowler_Get),
		Animation_Make_Atlas("./data/Entity/Bowser.png",ANIMATIONBG_DG,ENTITY_BOWSER,8,1,World_Bowser_Get),
		Animation_Make_Atlas("./data/Entity/Bro.png",ANIMATIONBG_DG,ENTITY_BRO,6,2,World_Bro_Get),
		Animation_Make_Atlas("./data/Entity/Coopa.png",ANIMATIONBG_DG,ENTITY_COOPA,10,3,World_Coopa_Get),
		Animation_Make_Atlas("./data/Entity/FireJumper.png",ANIMATIONBG_DG,ENTITY_FIREJUMPER,2,1,World_FireJumper_Get),
		Animation_Make_Atlas("./data/Entity/Fish.png",ANIMATIONBG_DG,ENTITY_FISH,4,3,World_Fish_Get),
		Animation_Make_Atlas("./data/Entity/Gumba.png",ANIMATIONBG_DG,ENTITY_GUMBA,3,3,World_Gumba_Get),
		Animation_Make_Atlas("./data/Entity/Lakitu.png",ANIMATIONBG_DG,ENTITY_LAKITU,3,3,World_Lakitu_Get),
		Animation_Make_Atlas("./data/Entity/Plant_UG.png",ANIMATIONBG_DG,ENTITY_PLANT_UG,2,1,World_PlantUG_Get),
		Animation_Make_Atlas("./data/Entity/Plant.png",ANIMATIONBG_DG,ENTITY_PLANT,2,1,World_PLant_Get),
		Animation_Make_Atlas("./data/Entity/Spike.png",ANIMATIONBG_DG,ENTITY_SPIKE,6,1,World_Spike_Get),
		Animation_Make_Atlas("./data/Entity/Squid.png",ANIMATIONBG_DG,ENTITY_SQUID,2,1,World_Squid_Get),
		Animation_Make_Atlas("./data/Entity/Willi.png",ANIMATIONBG_DG,ENTITY_WILLI,2,1,World_Willi_Get),
		Animation_Null()
	},(EntityAtlas[]){
		EntityAtlas_New("./data/Entity/Mario.png",16,12,	(void(*)(void*,const float))Mario_Update,		(SubSprite(*)(void*,EntityAtlas*))Mario_GetRender,		(void(*)(void*))Mario_Free),
		EntityAtlas_New("./data/Entity/Bowler.png",5,3,		(void(*)(void*,const float))Bowler_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowler_GetRender,		(void(*)(void*))Bowler_Free),
		EntityAtlas_New("./data/Entity/Bowser.png",8,1,		(void(*)(void*,const float))Bowser_Update,		(SubSprite(*)(void*,EntityAtlas*))Bowser_GetRender,		(void(*)(void*))Bowser_Free),
		EntityAtlas_New("./data/Entity/Bro.png",6,2,		(void(*)(void*,const float))Bro_Update,			(SubSprite(*)(void*,EntityAtlas*))Bro_GetRender,		(void(*)(void*))Bro_Free),
		EntityAtlas_New("./data/Entity/Coopa.png",10,3,		(void(*)(void*,const float))Coopa_Update,		(SubSprite(*)(void*,EntityAtlas*))Coopa_GetRender,		(void(*)(void*))Coopa_Free),
		EntityAtlas_New("./data/Entity/FireJumper.png",2,1,	(void(*)(void*,const float))FireJumper_Update,	(SubSprite(*)(void*,EntityAtlas*))FireJumper_GetRender,	(void(*)(void*))FireJumper_Free),
		EntityAtlas_New("./data/Entity/Fish.png",4,3,		(void(*)(void*,const float))Fish_Update,		(SubSprite(*)(void*,EntityAtlas*))Fish_GetRender,		(void(*)(void*))Fish_Free),
		EntityAtlas_New("./data/Entity/Gumba.png",3,3,		(void(*)(void*,const float))Gumba_Update,		(SubSprite(*)(void*,EntityAtlas*))Gumba_GetRender,		(void(*)(void*))Gumba_Free),
		EntityAtlas_New("./data/Entity/Lakitu.png",3,3,		(void(*)(void*,const float))Lakitu_Update,		(SubSprite(*)(void*,EntityAtlas*))Lakitu_GetRender,		(void(*)(void*))Lakitu_Free),
		EntityAtlas_New("./data/Entity/Plant_UG.png",2,1,	(void(*)(void*,const float))PlantUG_Update,		(SubSprite(*)(void*,EntityAtlas*))PlantUG_GetRender,	(void(*)(void*))PlantUG_Free),
		EntityAtlas_New("./data/Entity/Plant.png",2,1,		(void(*)(void*,const float))Plant_Update,		(SubSprite(*)(void*,EntityAtlas*))Plant_GetRender,		(void(*)(void*))Plant_Free),
		EntityAtlas_New("./data/Entity/Spike.png",6,1,		(void(*)(void*,const float))Spike_Update,		(SubSprite(*)(void*,EntityAtlas*))Spike_GetRender,		(void(*)(void*))Spike_Free),
		EntityAtlas_New("./data/Entity/Squid.png",2,1,		(void(*)(void*,const float))Squid_Update,		(SubSprite(*)(void*,EntityAtlas*))Squid_GetRender,		(void(*)(void*))Squid_Free),
		EntityAtlas_New("./data/Entity/Willi.png",2,1,		(void(*)(void*,const float))Willi_Update,		(SubSprite(*)(void*,EntityAtlas*))Willi_GetRender,		(void(*)(void*))Willi_Free),
		EntityAtlas_Null()
	});
}
void Update(AlxWindow* w){
	PS4_Controller_Update(&ps4c);
	
	TransformedView_Output(&tv,(Vec2){ GetWidth(),GetHeight() });
	TransformedView_HandlePanZoom(&tv,window.Strokes,GetMouse());
	TransformedView_Border(&tv,(Rect){ { 0.0f,0.0f },{ world.width,world.height } });

	if(PS4_Controller_Key(&ps4c,PS4_CONTROLLER_HOME).PRESSED){
		w->Running = 0;
	}

	if(Stroke(ALX_KEY_Q).PRESSED){
		world.mode = world.mode==ANIMATIONBG_DG ? ANIMATIONBG_ALL : ANIMATIONBG_DG;
	}
	if(Stroke(ALX_KEY_1).PRESSED){
		if(selected>0U) selected--;
	}
	if(Stroke(ALX_KEY_2).PRESSED){
		selected++;
	}
	if(Stroke(ALX_KEY_7).PRESSED){
		if(level>0U){
			level--;
		}
	}
	if(Stroke(ALX_KEY_8).PRESSED){
		if(level<5U){
			level++;
		}
	}
	if(Stroke(ALX_KEY_9).PRESSED){
		CStr path = CStr_Format("./data/World/Level%d.txt",level);
		World_Load(&world,path,BLOCK_SPAWN,World_Std_Mapper);
		CStr_Free(&path);
	}
	if(Stroke(ALX_KEY_0).PRESSED){
		CStr path = CStr_Format("./data/World/Level%d.txt",level);
		World_Save(&world,path,World_Std_MapperR);
		CStr_Free(&path);
	}

	if(Stroke(ALX_KEY_Y).PRESSED){
		//CStr path = CStr_Format("./data/World/Level%d.txt",level);
		//World_Load(&world,path,World_Std_Mapper);
		//CStr_Free(&path);
		
		World_Start(&world,World_Std_SpawnMapper);
		mario.e->r.p = world.spawn;
	}

	if(Stroke(ALX_KEY_J).PRESSED){
		World_Resize(&world,world.width - 1,world.height);
	}
	if(Stroke(ALX_KEY_N).PRESSED){
		World_Resize(&world,world.width + 1,world.height);
	}
	if(Stroke(ALX_KEY_K).PRESSED){
		World_Resize(&world,world.width,world.height - 1);
	}
	if(Stroke(ALX_KEY_M).PRESSED){
		World_Resize(&world,world.width,world.height + 1);
	}

	if(world.mode!=ANIMATIONBG_DG){
		mario.e->a.y = MARIO_ACC_GRAVITY;
		
		const signed int abs = PS4_Controller_Abs(&ps4c,PS4_CONTROLLER_LX);
		if(Stroke(ALX_KEY_A).DOWN) 									Figure_Move(&mario,-1.0f);
		else if(Stroke(ALX_KEY_D).DOWN) 							Figure_Move(&mario,1.0f);
		else if(abs >= 0 && abs < 128) 								Figure_Move(&mario,F32_Map(abs,0.0f,255.0f,-1.0f,1.0f));
		else if(abs >= 128) 										Figure_Move(&mario,F32_Map(abs,0.0f,255.0f,-1.0f,1.0f));
		else 														Figure_Move(&mario,0.0f);
		
		if(mario.e->id==ENTITY_MARIO && ((Mario*)mario.e)->ground){
			if(Stroke(ALX_KEY_W).PRESSED || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_X).PRESSED){
				mario.e->v.y = -MARIO_VEL_JP;
				AudioPlayer_Add(&ap,"./data/Sound/jump.wav");
			}
		}
		if(Stroke(ALX_KEY_W).DOWN || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_X).DOWN){
			//if(mario.v.y<0.0f)
			if(mario.e->id==ENTITY_MARIO)
				((Mario*)mario.e)->jumping = ENTITY_TRUE;
			//else 				mario.jumping = ENTITY_FALSE;
		}
		if(Stroke(ALX_KEY_S).PRESSED || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_TRI).PRESSED){
			//mario.e->v.y = MARIO_VEL_JP;
		}
		if(Stroke(ALX_KEY_S).DOWN || PS4_Controller_Key(&ps4c,PS4_CONTROLLER_TRI).DOWN){
			if(mario.e->id==ENTITY_MARIO)
				((Mario*)mario.e)->stamp = ENTITY_TRUE;
		}else
			if(mario.e->id==ENTITY_MARIO)
				((Mario*)mario.e)->stamp = ENTITY_FALSE;
	}else{
		mario.e->a.y = 0.0f;
		((Mario*)mario.e)->dead = ENTITY_FALSE;

		if(Stroke(ALX_MOUSE_M).PRESSED){
			Vec2 p = TransformedView_ScreenWorldPos(&tv,(Vec2){ w->MouseX,w->MouseY });
			mario.e->r.p = p;
		}
		if(Stroke(ALX_MOUSE_L).DOWN){
			Vec2 p = TransformedView_ScreenWorldPos(&tv,(Vec2){ w->MouseX,w->MouseY });
			World_Set(&world,p.x,p.y,selected);
		}
		if(Stroke(ALX_MOUSE_R).DOWN){
			Vec2 p = TransformedView_ScreenWorldPos(&tv,(Vec2){ w->MouseX,w->MouseY });
			World_Set(&world,p.x,p.y,BLOCK_NONE);
		}
		
		if(Stroke(ALX_KEY_A).DOWN){
			if(mario.e->id==ENTITY_MARIO){
				if(mario.e->v.x>0.0f) 		 	((Mario*)mario.e)->reverse = ENTITY_TRUE;
				if(((Mario*)mario.e)->ground)	mario.e->a.x = -MARIO_ACC_GRD;
			}else
				mario.e->a.x = -MARIO_ACC_AIR;
		}else if(Stroke(ALX_KEY_D).DOWN){
			if(mario.e->id==ENTITY_MARIO){
				if(mario.e->v.x<0.0f)			((Mario*)mario.e)->reverse = ENTITY_TRUE;
				if(((Mario*)mario.e)->ground)	mario.e->a.x = MARIO_ACC_GRD;
			}else
				mario.e->a.x = MARIO_ACC_AIR;
		}else{
			mario.e->v.x =  0.0f;
			mario.e->a.x =  0.0f;
		}
		
		if(Stroke(ALX_KEY_W).DOWN){
			mario.e->v.y = -MARIO_VEL_JP;
			if(mario.e->id==ENTITY_MARIO)
				((Mario*)mario.e)->jumping = ENTITY_TRUE;
		}else if(Stroke(ALX_KEY_S).DOWN){
			mario.e->v.y = MARIO_VEL_JP;
			if(mario.e->id==ENTITY_MARIO)
				((Mario*)mario.e)->jumping = ENTITY_TRUE;
		}else{
			mario.e->v.y = 0.0f;
			mario.e->a.y = 0.0f;
		}
	}

	World_Update(&world,w->ElapsedTime);
	World_Collisions(&world);

	Figure_Update(&mario,&world,w->ElapsedTime);
	Figure_Collision(&mario,&world);

	Clear(LIGHT_BLUE);

	World_RenderBg(&world,&tv,WINDOW_STD_ARGS);
	Figure_Render(&mario,&world,&tv,WINDOW_STD_ARGS);
	World_RenderEntities(&world,&tv,WINDOW_STD_ARGS);
	World_RenderFg(&world,&tv,WINDOW_STD_ARGS);

	// for(int i = 0;i<world.animations.size;i++){
	// 	Animation* a = (Animation*)Vector_Get(&world.animations,i);
	// 	Sprite* s = (Sprite*)Vector_Get(a,0);
	// 	String str = String_Format("S:%d,%d",s->w,s->h);
	// 	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,i * window.AlxFont.CharSizeY,WHITE);
	// 	String_Free(&str);
	// }

	if(world.mode==ANIMATIONBG_DG){
		const int preshow = 7;
		const Vec2 sd = TransformedView_WorldScreenLength(&tv,(Vec2){ 1.0f,1.0f });
		const float x = 10.0f;

		RenderRect((preshow >> 1) * (sd.x * 1.1f),0.0f,sd.x + 10.0f,sd.y + 10.0f,RED);

		for(int i = 0;i<preshow;i++){
			const Block b = selected + i - (preshow >> 1);

			if(World_isBlock(&world,b)){
				SubSprite ss = World_Img(&world,b,0.0f,0.0f);
				if(ss.sp) RenderSubSpriteAlpha(ss.sp,x + i * (ss.dx * 1.1f),5.0f,ss.ox,ss.oy,ss.dx,ss.dy);
			}
		}
	}

	String str = String_Format("S:%d,%d | L:%d",window.Width,window.Height,level);
	CStr_RenderSizeAlxFont(WINDOW_STD_ARGS,&window.AlxFont,str.Memory,str.size,0.0f,0.0f,WHITE);
	String_Free(&str);
}
void Delete(AlxWindow* w){
	AudioPlayer_Free(&ap);
	
	World_Free(&world);
	Figure_Free(&mario);
	PS4_Controller_Free(&ps4c);
}

int main(){
    if(Create("Mario",1920,1080,1,1,Setup,Update,Delete))
        Start();
    return 0;
}