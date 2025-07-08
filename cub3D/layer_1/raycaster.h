#ifndef RAYCAST_H
#define RAYCAST_H

#include "player.h"
#include "map.h"
#define NBR_RAY 800
#define FOV (M_PI / 2)

typedef struct s_raycast
{
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		case_x;
	int		case_y;
	int		step_x;
	int		step_y;
	int		side;
	double	distance;
	double	hit_x;
	double	hit_y;
}	t_raycast;


typedef struct s_multiple_raycast
{
	t_player	copy_player;
	double		fov; //field of view.
	double		ray_angle;

} t_multiple_raycast;


t_raycast raycasting(const t_player *player, const t_map *map);
t_raycast *raycasting_multiple(const t_player *player, const t_map *map);

#endif
