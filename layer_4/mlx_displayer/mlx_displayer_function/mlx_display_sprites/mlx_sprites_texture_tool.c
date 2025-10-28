/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprites_texture_tool.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:43:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:11:56 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer_function.h"

int	is_line_not_visible(int line, t_spritebuffer *sprite_buff,
			t_sprite_view *sprite, const t_framebuffer *frame_buff )
{
	if (line < 0 || line >= NBR_RAY)
		return (1);
	if ((sprite->distance * sprite_buff->size_of_block)
		>= frame_buff->rays[line].distance)
		return (1);
	return (0);
}

void	init_sprite_texture_coords(t_sprite_view *sprite, int x, int y,
			t_img *out_coords)
{
	sprite->texture_x = ((x - sprite->draw_start_x) * out_coords->width)
		/ (sprite->draw_end_x - sprite->draw_start_x);
	sprite->texture_y = ((y - sprite->draw_start_y) * out_coords->height)
		/ (sprite->draw_end_y - sprite->draw_start_y);
}

unsigned int	get_sprite_pixel_color(t_sprite_view *sprite, 
			t_img *coords)
{
	char	*pixel;

	pixel = coords->img_pixels_ptr + 
		sprite->texture_y * coords->line_len + 
		sprite->texture_x * (coords->bits_per_pixel / 8);
	return (*(unsigned int *)pixel);
}
