/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:28:44 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:51:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#define EPS 1e-10

void	raycast_init(const t_player *player, const t_map *map,
	t_raycast *r, double angle)
{
	raycast_init_pos_and_direction_in_radian(
		r, player->pos_x, player->pos_y, angle);
	raycast_init_vector_and_grid_pos(r, map->size_of_block);
	raycast_init_delta(r, map->size_of_block);
	raycast_init_step_direction_and_side_dist(r, map->size_of_block);
}

void	raycast_init_pos_and_direction_in_radian(t_raycast *r, double pos_x,
	double pos_y, double direction)
{
	r->pos_x = pos_x;
	r->pos_y = pos_y;
	r->direction = direction;
}

//we use the trigonometrique circle to get a number beetween -1 and 1;
//this number will allow us to know : 
//	> in wich direction goes the ray,
//	> delta, the distance to pass a square
void	raycast_init_vector_and_grid_pos(t_raycast *r, int size_of_block)
{
	r->dir_x = cos(r->direction);
	r->dir_y = sin(r->direction);
	r->case_x = r->pos_x / size_of_block;
	r->case_y = r->pos_y / size_of_block;
	if (fabs(r->dir_x) < EPS)
	{
		if (r->dir_x > 0)
			r->dir_x = EPS;
		else
			r->dir_x = -EPS;
	}
	if (fabs(r->dir_y) < EPS)
	{
		if (r->dir_y > 0)
			r->dir_y = EPS;
		else
			r->dir_y = -EPS;
	}
}

// delta is the distance to pass a square we use an absolute value.
void	raycast_init_delta(t_raycast *r, int size_of_block)
{
	if (r->dir_x != 0)
		r->delta_x = fabs(size_of_block / r->dir_x);
	else
		r->delta_x = 1e30;
	if (r->dir_y != 0)
		r->delta_y = fabs(size_of_block / r->dir_y);
	else
		r->delta_y = 1e30;
}

//side_dist_x is the distance with the next x border that we cross.
void	raycast_init_step_direction_and_side_dist(t_raycast *r, int size_block)
{
	if (r->dir_x > 0)
	{
		r->step_x = 1;
		r->side_dist_x = ((r->case_x + 1) * size_block - r->pos_x) / r->dir_x;
	}
	else
	{
		r->step_x = -1;
		r->side_dist_x = (r->pos_x - r->case_x * size_block) / -r->dir_x;
	}
	if (r->dir_y > 0)
	{
		r->step_y = 1;
		r->side_dist_y = ((r->case_y + 1) * size_block - r->pos_y) / r->dir_y;
	}
	else
	{
		r->step_y = -1;
		r->side_dist_y = (r->pos_y - r->case_y * size_block) / -r->dir_y;
	}
}
