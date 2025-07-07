#ifndef RAYCAST_H
#define RAYCAST_H

#include "player.h"
#include "map.h"

typedef struct s_raycast
{
	double dir_x;
	double dir_y;
	double pos_x;
	double pos_y;
	double delta_x;
	double delta_y;
	double side_dist_x;
	double side_dist_y;
	int	case_x;
	int	case_y;
	int	step_x;
	int	step_y;
	int	side;
	double	distance;
}t_raycast;


void raycast_init(const t_player *player, const t_map *map, t_raycast *r);
double raycasting(const t_player *player, t_map *map);

#endif
