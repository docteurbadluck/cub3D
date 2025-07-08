#include "raycaster.h"

void raycast_init(const t_player *player, const t_map *map, t_raycast *r)
{
    r->pos_x = player->pos_x;
    r->pos_y = player->pos_y;
    r->dir_x = cos(player->camera_direction);
    r->dir_y = sin(player->camera_direction);
    r->case_x = r->pos_x / map->size_of_block;
    r->case_y = r->pos_y / map->size_of_block;
    if (r->dir_x == 0)
	   r->delta_x = 1e30;
    else 
    	r->delta_x = fabs(map->size_of_block / r->dir_x);

    if (r->dir_y == 0)
	    r->delta_y = 1e30;
    else
    	r->delta_y = fabs(map->size_of_block / r->dir_y);

    if (r->dir_x > 0)
    {
        r->step_x = 1;
        r->side_dist_x = ((r->case_x + 1) * map->size_of_block - r->pos_x) / r->dir_x;
    }
    else
    {
        r->step_x = -1;
        r->side_dist_x = (r->pos_x - (r->case_x * map->size_of_block)) / fabs(r->dir_x);
    }

    if (r->dir_y > 0)
    {
        r->step_y = 1;
        r->side_dist_y = ((r->case_y + 1) * map->size_of_block - r->pos_y) / r->dir_y;
    }
    else
    {
        r->step_y = -1;
        r->side_dist_y = (r->pos_y - (r->case_y * map->size_of_block)) / fabs(r->dir_y);
    }
}

static double normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return angle;
}

t_raycast raycasting(const t_player *player, const t_map *map)
{
	t_raycast raycast;
	
	raycast_init(player, map, &raycast);	

	while (1)
	{
		if (raycast.side_dist_x < raycast.side_dist_y)
		{
			raycast.side_dist_x += raycast.delta_x;
			raycast.case_x += raycast.step_x;
			raycast.side = 0; // vertical
		}
		else 
		{
			raycast.side_dist_y += raycast.delta_y;
			raycast.case_y += raycast.step_y;
			raycast.side = 1;
		}
		if (map->grid[raycast.case_y][raycast.case_x] != 0)
			break;
	}
	if (raycast.side == 0)	
		raycast.distance = ((raycast.case_x - (raycast.pos_x / map->size_of_block)) + (1 - raycast.step_x) / 2 ) * raycast.delta_x;
	else
		raycast.distance = ((raycast.case_y - (raycast.pos_y / map->size_of_block)) + (1 - raycast.step_y) / 2 ) * raycast.delta_y;

	raycast.distance = fabs(raycast.distance);
	return raycast;
}


t_raycast *raycasting_multiple(const t_player *player, const t_map *map)
{
	t_raycast			*rays;
	t_multiple_raycast	raycaster;
	double				angle_step;
	int					i;

	rays = malloc(sizeof(t_raycast) * NBR_RAY);
	if (!rays)
		return NULL;
	raycaster.copy_player = *player;
	raycaster.fov = FOV;
	angle_step = raycaster.fov / NBR_RAY;
	for (i = 0; i < NBR_RAY; i++)
	{
		double angle_offset = (i - (NBR_RAY / 2.0)) * angle_step;
		raycaster.ray_angle = normalize_angle(player->camera_direction + angle_offset);

		raycaster.copy_player.camera_direction = raycaster.ray_angle;
		rays[i] = raycasting(&raycaster.copy_player, map);
		double angle_diff = normalize_angle(raycaster.ray_angle - player->camera_direction);
		rays[i].distance *= cos(angle_diff);
	}
	return rays;
}

