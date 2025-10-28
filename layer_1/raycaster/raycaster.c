/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:56:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 13:10:13 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

t_raycast	raycasting(const t_player *player, const t_map *map, double angle)
{
	t_raycast	raycast;

	raycast_init(player, map, &raycast, angle);
	raycasting_send_a_ray(&raycast, map);
	raycasting_find_distance_and_hit_point(&raycast, map->size_of_block);
	raycast.distance = fabs(raycast.distance);
	return (raycast);
}

void	raycasting_send_a_ray(t_raycast *r, const t_map *map)
{
	while (1)
	{
		if (r->side_dist_x < r->side_dist_y)
			step_in_x_direction(r);
		else 
			step_in_y_direction(r);
		if (map->grid[r->case_y][r->case_x] == 1)
			break ;
	}
}

void	step_in_x_direction(t_raycast *r)
{
	r->side_dist_x += r->delta_x;
	r->case_x += r->step_x; 
	r->side = 0;
}

void	step_in_y_direction(t_raycast *r)
{
	r->side_dist_y += r->delta_y;
	r->case_y += r->step_y;
	r->side = 1;
}

void	raycasting_find_distance_and_hit_point(t_raycast *r, int size_of_block)
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
