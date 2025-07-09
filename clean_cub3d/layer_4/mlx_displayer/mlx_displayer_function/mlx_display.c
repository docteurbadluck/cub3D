/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 18:10:57 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "mlx_displayer_function.h"

void mlx_display_env(const t_i_displayer *self, const t_framebuffer *frame_buff)
{
	t_mlx_displayer *displayer = (t_mlx_displayer *)self;

	background_render(displayer->sky_color, displayer->ground_color, displayer->mlx);
	for (int i = 0; i < NBR_RAY; i++)
	{
		double dist = frame_buff->rays[i].distance;
		if (dist < 0.0001)
			dist = 0.0001;

		int line_height = (int)(HEIGHT / dist);
		int draw_start = (HEIGHT - line_height) / 2;
		int draw_end = (HEIGHT + line_height) / 2;
		if (draw_start < 0) draw_start = 0;
		if (draw_end > HEIGHT) draw_end = HEIGHT;
		int screen_x = (i * WIDTH) / NBR_RAY;

		// === Choose correct texture based on wall face ===
		t_img *tex;
		switch (frame_buff->rays[i].face)
		{
			case 'N': tex = &displayer->textures[0]; break;
			case 'S': tex = &displayer->textures[1]; break;
			case 'E': tex = &displayer->textures[2]; break;
			case 'W': tex = &displayer->textures[3]; break;
			default:  tex = &displayer->textures[0]; break; // fallback to north
		}

		// === Texture sampling using hit_x / hit_y ===
		double wall_x = (frame_buff->rays[i].side == 0)
			? frame_buff->rays[i].hit_y
			: frame_buff->rays[i].hit_x;
		wall_x -= floor(wall_x); // keep fractional part

		int tex_x = (int)(wall_x * tex->width);
		if (tex_x < 0) tex_x = 0;
		if (tex_x >= tex->width) tex_x = tex->width - 1;

		for (int y = draw_start; y < draw_end; y++)
		{
			int d = y * 256 - HEIGHT * 128 + line_height * 128;
			int tex_y = ((d * tex->height) / line_height) / 256;
			if (tex_y < 0) tex_y = 0;
			if (tex_y >= tex->height) tex_y = tex->height - 1;

			char *pixel = tex->img_pixels_ptr
				+ tex_y * tex->line_len
				+ tex_x * (tex->bits_per_pixel / 8);

			int color = *(int *)pixel;
			my_pixel_put(screen_x, y, &displayer->mlx->img, color);
		}
	}
}
