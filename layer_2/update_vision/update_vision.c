/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:56:02 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_vision.h"
#include "update_sprite.h"

void	update_vision(const t_player *player,
	const t_map *map, t_i_displayer *displayer, t_sprite *sprites)
{
	t_raycast		*raycast;
	t_framebuffer	frame_buffer;
	t_spritebuffer	sprite_buffer;

	update_sprite(sprites, player, map, &sprite_buffer);
	update_raycast(player, map, &raycast, &frame_buffer);
	displayer->display_wall(displayer, &frame_buffer);
	displayer->display_minimap(displayer, map, player);
	if (sprite_buffer.count > 0)
		displayer->display_sprites(displayer, &sprite_buffer, &frame_buffer);
}

void	update_raycast(const t_player *player, const t_map *map,
			t_raycast **raycast, t_framebuffer *frame_buffer)
{
	*raycast = raycasting_player_view(player, map);
	transform_raycast_into_framebuffer(*raycast, frame_buffer);
	free(*raycast);
}

void	transform_raycast_into_framebuffer(t_raycast *raycast,
			t_framebuffer *frame_buffer)
{
	int	i;

	i = 0;
	while (i < NBR_RAY)
	{
		frame_buffer->rays[i].distance_brut = raycast[i].distance;
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
