/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:43:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:35:48 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_function.h"

void	draw_sprite(t_spritebuffer *sprite_buff,
			t_sprite_view *s, const t_i_displayer *self,
			const t_framebuffer *frame_buff)
{
	int				line;
	int				y;
	t_mlx_displayer	*mlx_d;
	unsigned int	color;

	mlx_d = (t_mlx_displayer *)self;
	animate_sprite(s, mlx_d);
	line = s->draw_start_x -1;
	while (++line < s->draw_end_x)
	{
		if (is_line_not_visible(line, sprite_buff, s, frame_buff))
			continue ;
		y = s->draw_start_y - 1;
		while (++y < s->draw_end_y)
		{
			init_sprite_texture_coords(s, line, y, &mlx_d->sprites[s->tex_type]
				.textures_sprite[mlx_d->sprites[s->tex_type].current_texture]);
			color = get_sprite_pixel_color(s, &mlx_d->sprites
				[s->tex_type].textures_sprite[mlx_d->sprites[s->tex_type]. 
					current_texture]);
			if ((color >> 24) == 0) 
				my_pixel_put(line, y, &mlx_d->mlx->img, color);
		}
	}
}
