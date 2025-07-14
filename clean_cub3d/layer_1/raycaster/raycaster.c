/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:56:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 09:33:46 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

// At each step, compare the distance to the next
// vertical (X) and horizontal (Y) grid lines.
// Move to the next tile in the shortest direction (either X or Y).
// Update `side` to remember whether the wall hit was vertical
// (side == 0) or horizontal (side == 1).
void	raycasting_send_a_ray(t_raycast *r, const t_map *map)
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
			break ;
	}
}

//we recalcule the distance know that we now the position of the wall.
// we also look where does hit the other y to know which part of the wall 
// has been hitted.

void raycasting_finalize_hit(t_raycast *r, int size_of_block)
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

	r->hit_x = r->pos_x + r->distance * r->dir_x;
	r->hit_y = r->pos_y + r->distance * r->dir_y;
}
// Sends a ray in a given direction to detect the first wall hit.
// Uses DDA to walk through the map grid until a wall is found.
// Then calculates the exact distance to the wall and hit position.
// This data is later used for rendering, including texture sampling.
t_raycast	raycasting(const t_player *player, const t_map *map, double angle)
{
	t_raycast	raycast;

	raycast_init(player, map, &raycast, angle);
	raycasting_send_a_ray(&raycast, map);
	raycasting_finalize_hit(&raycast, map->size_of_block);
	raycast.distance = fabs(raycast.distance);
	return (raycast);
}
