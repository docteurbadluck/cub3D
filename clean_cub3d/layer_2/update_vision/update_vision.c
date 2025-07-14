/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 10:13:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_vision.h"

//tranform the data from t_raycast into a a nicer data structure for 
// our displayer. 
void	framebuffer_init(t_raycast *raycast, t_framebuffer *frame_buffer)
{
	int	i;

	i = 0;
	while (i < NBR_RAY)
	{
		frame_buffer->rays[i].distance = raycast[i].distance;
		frame_buffer->rays[i].side = raycast[i].side;
		frame_buffer->rays[i].hit_x = raycast[i].hit_x;
		if (frame_buffer->rays[i].hit_x < 0)
			frame_buffer->rays[i].hit_x = 0;
		frame_buffer->rays[i].hit_y = raycast[i].hit_y;
		if (frame_buffer->rays[i].hit_y < 0)
			frame_buffer->rays[i].hit_y = 0;
		frame_buffer->rays[i].dir_x = raycast[i].dir_x;
		frame_buffer->rays[i].dir_y = raycast[i].dir_y;
		if (raycast[i].side == 0 && raycast[i].dir_x > 0)
			frame_buffer->rays[i].face = 'W';
		else if (raycast[i].side == 0 && raycast[i].dir_x < 0)
			frame_buffer->rays[i].face = 'E';
		else if (raycast[i].side == 1 && raycast[i].dir_y > 0)
			frame_buffer->rays[i].face = 'S';
		else if (raycast[i].side == 1 && raycast[i].dir_y < 0)
			frame_buffer->rays[i].face = 'N';
		i++;
	}
}

// An interface is also the right moment to transform data into a conveignant
// format for the destinator. here for exemple, instead of passing 
// the full raycast (which contain 17 field) , we encapsulate the data into
// framebuffer which contain an array of t_ray_hit (which contain 5 field only).
// this allow a better readability.
// it alsow allow us to free the data allocated into the logic layer. 
void	update_vision(const t_player *player,
	const t_map *map, t_i_displayer *display)
{
	t_raycast		*raycast;
	t_framebuffer	frame_buffer;

	raycast = raycasting_multiple(player, map);
	framebuffer_init(raycast, &frame_buffer);
	free(raycast);
	display->display(display, &frame_buffer);
	display->display_minimap(display, map, player);
}
