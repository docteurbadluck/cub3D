
#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include "map.h"

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double camera_direction; //angle in radiant
	int speed; // unit by update
	double rotation_speed;
}	t_player;



void player_move_backward(t_player *player, const t_map *map);
void player_move_forward(t_player *player, const t_map *map);
void player_rotate_step(t_player *player, int  direction);
void player_rotate(t_player *player, double angle);
void player_print_state(const t_player *player);

#endif
