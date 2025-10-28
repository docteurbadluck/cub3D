/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprites_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:43:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:11:06 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_function.h"

int	transform_world_pos_to_camera_space(
		t_spritebuffer *s_buff, t_sprite_view *sprite)
{
	sprite->transform_x = s_buff->inv_det * (s_buff->player_dir_y * 
			sprite->vector_player_to_sprite_x - s_buff->player_dir_x * 
			sprite->vector_player_to_sprite_y);
	sprite->transform_y = s_buff->inv_det * (-s_buff->player_plane_y * 
			sprite->vector_player_to_sprite_x + s_buff->player_plane_x * 
			sprite->vector_player_to_sprite_y);
	if (sprite->transform_y <= 0)
		return (1);
	return (0);
}

void	set_position_and_size_on_screen(t_sprite_view *sprite)
{
	sprite->screen_x = (int)((WIDTH / 2) * 
			(1 + sprite->transform_x / sprite->transform_y));
	sprite->sprite_size = 100;
	sprite->sprite_height = 
		abs((int)(sprite->sprite_size / sprite->transform_y));
	sprite->sprite_width = sprite->sprite_height;
}

void	set_draw_boundaries(t_sprite_view *sprite)
{
	sprite->draw_start_y = -sprite->sprite_height / 2 + HEIGHT / 2;
	sprite->draw_end_y = sprite->sprite_height / 2 + HEIGHT / 2;
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->screen_x;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->screen_x;
}
