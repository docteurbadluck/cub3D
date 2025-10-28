/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:54:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:58:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_sprite.h"
#include "sprite_buffer.h"

void	update_sprite(t_sprite *sprites, const t_player *player,
			const t_map *map, t_spritebuffer *buffer)
{
	update_spriteview_data(sprites, player, map, buffer);
	if (buffer->count > 0)
	{
		update_spritebuffer_info(sprites, player, buffer);
	}
}

void	update_spriteview_data(t_sprite *sprites,
			const t_player *player, const t_map *map, t_spritebuffer *buffer)
{
	int				i;
	t_sprite_view	*view;

	i = 0;
	buffer->count = 0;
	while (i < map->sprite_count)
	{
		update_sprite_data(&sprites[i], player, map);
		if (sprites[i].flag_in_fov)
		{
			view = &buffer->sprites[buffer->count];
			copy_data_from_sprite(view, sprites, i);
			buffer->count++;
		}
		i++;
	}
}

void	copy_data_from_sprite(t_sprite_view *view, t_sprite *sprites, int i)
{
	view->distance = sprites[i].lenght_sprite_v;
	view->type = sprites[i].type;
	view->vector_player_to_sprite_x = sprites[i].vector_player_to_sprite_x;
	view->vector_player_to_sprite_y = sprites[i].vector_player_to_sprite_y;
}

void	update_spritebuffer_info(t_sprite *sprites,
			const t_player *player, t_spritebuffer *buffer)
{
	buffer->player_fov = player->fov;
	buffer->player_dir_x = sprites[0].vector_player_direction_x;
	buffer->player_dir_y = sprites[0].vector_player_direction_y;
	update_world_to_camera_space_data(sprites, player, buffer);
}

void	update_world_to_camera_space_data(t_sprite *sprites,
			const t_player *player, t_spritebuffer *buffer)
{
	buffer->player_plane_x = (-buffer->player_dir_y * tan(player->fov / 2));
	buffer->player_plane_y = buffer->player_dir_x * tan(player->fov / 2);
	buffer->inv_det = 1.0f / (buffer->player_plane_x * buffer->player_dir_y
			- buffer->player_dir_x * buffer->player_plane_y);
	buffer->size_of_block = sprites[0].size_of_block;
}
