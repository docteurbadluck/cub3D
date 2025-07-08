
#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include "map.h"

#define SPEED 0.2
#define ROTATION_SPEED (M_PI/180)

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double camera_direction; //angle in radiant
	double speed; // unit by update
	double rotation_speed;
}	t_player;



void player_move_backward(t_player *player, const t_map *map);
void player_move_forward(t_player *player, const t_map *map);
void player_rotate_step(t_player *player, int  direction);
void player_rotate(t_player *player, double angle);
void player_print_state(const t_player *player);
void init_player(t_player *A, int pos_x, int pos_y, double camera_direction);

#endif
