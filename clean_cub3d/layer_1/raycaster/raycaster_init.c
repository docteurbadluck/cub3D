/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:28:44 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 12:54:42 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	raycast_init_pos_and_direction(t_raycast *r, double pos_x,
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
}

// delta is the distance to pass a square we use an absolute value.
// to avoid division by 0 we give to delta an little value instead.
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

// in search the distance on the x and y vector between the player & the next
// we divide it by dir x to have the distance beetween us and the  next wall.
// we will do the next calculation on this variable.
void	raycast_init_step_direction_and_side_dist(t_raycast *r,
	int size_of_block)
{
	if (r->dir_x > 0)
	{
		r->step_x = 1;
		r->side_dist_x = ((r->case_x + 1) * size_of_block - r->pos_x)
			/ r->dir_x;
	}
	else
	{
		r->step_x = -1;
		r->side_dist_x = ((r->pos_x) - (r->case_x * size_of_block)) 
			/ fabs(r->dir_x);
	}
	if (r->dir_y > 0)
	{
		r->step_y = 1;
		r->side_dist_y = ((r->case_y + 1) * size_of_block - r->pos_y)
			/ r->dir_y;
	}
	else
	{
		r->step_y = -1;
		r->side_dist_y = (r->pos_y - (r->case_y * size_of_block))
			/ fabs(r->dir_y);
	}
}

void	raycast_init(const t_player *player, const t_map *map,
	t_raycast *r, double angle)
{
	raycast_init_pos_and_direction(r, player->pos_x, player->pos_y, angle);
	raycast_init_vector_and_grid_pos(r, map->size_of_block);
	raycast_init_delta(r, map->size_of_block);
	raycast_init_step_direction_and_side_dist(r, map->size_of_block);
}
