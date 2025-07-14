/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 15:38:47 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_vision.h"

void	framebuffer_init_face(int i,
			t_raycast *raycast, t_framebuffer *frame_buffer)
{
		if (raycast[i].side == 0 && raycast[i].dir_x > 0)
			frame_buffer->rays[i].face = 'W';
		else if (raycast[i].side == 0 && raycast[i].dir_x < 0)
			frame_buffer->rays[i].face = 'E';
		else if (raycast[i].side == 1 && raycast[i].dir_y > 0)
			frame_buffer->rays[i].face = 'S';
		else if (raycast[i].side == 1 && raycast[i].dir_y < 0)
			frame_buffer->rays[i].face = 'N';
		else
			frame_buffer->rays[i].face = '?';
}
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
		framebuffer_init_face(i, raycast, frame_buffer);
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
	const t_map *map, t_i_displayer *displayer)
{
	t_raycast		*raycast;
	t_framebuffer	frame_buffer;
	t_raycast		*raycast_sprite;

	raycast = raycasting_multiple(player, map);
	framebuffer_init(raycast, &frame_buffer);
	free(raycast);
	displayer->display(displayer, &frame_buffer);
	displayer->display_minimap(displayer, map, player);
	
	raycast_sprite = raycasting_multiple_sprite(player, map);
	printf("raycast_sprite : dist : %.2f, dir x : %.2f, dir y : %.2f, sprite_type : %d\n", raycast_sprite->distance, raycast_sprite->dir_x, raycast_sprite->dir_y, raycast_sprite->sprite_type);
	

	
//	displayer->display_sprite(displayer, map, player);
}
