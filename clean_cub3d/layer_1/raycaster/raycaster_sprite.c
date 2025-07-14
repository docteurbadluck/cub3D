/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:56:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 15:27:46 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

// At each step, compare the distance to the next
// vertical (X) and horizontal (Y) grid lines.
// Move to the next tile in the shortest direction (either X or Y).
// Update `side` to remember whether the wall hit was vertical
// (side == 0) or horizontal (side == 1).
void	raycasting_send_a_ray_sprite(t_raycast *r, const t_map *map)
{
	while (1)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->case_x += r->step_x; 
			r->side = 0;
		}
		else 
		{
			r->side_dist_y += r->delta_y;
			r->case_y += r->step_y;
			r->side = 1;
		}
		if (map->grid[r->case_y][r->case_x] != 0)
		{
			r->sprite_type = map->grid[r->case_y][r->case_x];
			break ;
		}
	}
}

//we recalcule the distance know that we now the position of the wall.
// we also look where does hit the other y to know which part of the wall 
// has been hitted.

void	raycasting_finalize_hit_sprite(t_raycast *r, int size_of_block)
{
	if (r->side == 0)
	{
		r->distance = ((r->case_x * size_of_block - r->pos_x)
				+ (1 - r->step_x) * size_of_block / 2.0) / r->dir_x;
	}
	else
	{
		r->distance = ((r->case_y * size_of_block - r->pos_y)
				+ (1 - r->step_y) * size_of_block / 2.0) / r->dir_y;
	}
	r->hit_x = r->pos_x + r->distance * r->dir_x - (r->delta_x / 2);
	r->hit_y = r->pos_y + r->distance * r->dir_y- (r->delta_y / 2);
}

// Sends a ray in a given direction to detect the first wall hit.
// Uses DDA to walk through the map grid until a wall is found.
// Then calculates the exact distance to the wall and hit position.
// This data is later used for rendering, including texture sampling.
t_raycast	raycasting_sprite(const t_player *player, const t_map *map, double angle)
{
	t_raycast	raycast;

	raycast_init(player, map, &raycast, angle);
	raycasting_send_a_ray_sprite(&raycast, map);
	raycasting_finalize_hit_sprite(&raycast, map->size_of_block);
	raycast.distance = fabs(raycast.distance);
	return (raycast);
}

t_raycast	*raycasting_multiple_sprite(const t_player *player, const t_map *map)
{
	t_raycast			*rays;
	t_multiple_raycast	caster;
	int					i;

	i = 0;
	rays = malloc(sizeof(t_raycast) * NBR_RAY);
	if (!rays)
		return (NULL);
	caster.angle_step = player->fov / NBR_RAY;
	while (i < NBR_RAY)
	{
		caster.angle_offset = (i - (NBR_RAY / 2.0)) * caster.angle_step;
		caster.angle_current = 
			normalize_angle(player->camera_direction + caster.angle_offset);
		rays[i] = raycasting_sprite(player, map, caster.angle_current);
		caster.angle_diff = 
			normalize_angle(caster.angle_current - player->camera_direction);
		rays[i].distance *= cos(caster.angle_diff);
		i++;
	}
	return (rays);
}
