/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 10:48:15 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_vision.h"

void framebuffer_init(t_raycast *raycast, t_framebuffer *frame_buffer)
{
	int i = 0;
	while (i < NBR_RAY)
	{
		frame_buffer->rays[i].distance = raycast[i].distance;
		frame_buffer->rays[i].side = raycast[i].side;
		frame_buffer->rays[i].hit_x = raycast[i].hit_x;
		frame_buffer->rays[i].hit_y = raycast[i].hit_y;
		if (raycast[i].side == 0 && raycast[i].dir_x > 0)
			frame_buffer->rays[i].face = 'W';
		else if (raycast[i].side == 0 && raycast[i].dir_x < 0)
			frame_buffer->rays[i].face = 'E';
		else if(raycast[i].side == 1 && raycast[i].dir_y > 0)
			frame_buffer->rays[i].face = 'S';
		else if (raycast[i].side == 1 && raycast[i].dir_y < 0)
			frame_buffer->rays[i].face = 'N';
		else
			frame_buffer->rays[i].face = '?';

		i++;
	}
}

void update_vision(const t_player *player, const t_map *map, const t_displayer *display)
{
	t_raycast *raycast;
	t_framebuffer frame_buffer;
	
	raycast = raycasting_multiple(player, map);
	framebuffer_init(raycast, &frame_buffer);
	//free(raycast);
	display->display(display, &frame_buffer);
}
