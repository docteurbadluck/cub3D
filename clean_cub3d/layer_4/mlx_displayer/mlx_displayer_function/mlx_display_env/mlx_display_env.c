/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 13:37:45 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "../mlx_displayer_function.h"

void	draw_the_line(const t_mlx_displayer *displayer, t_line_to_display *line_to_display, int i);

void	mlx_display_env(const t_i_displayer *self, const t_framebuffer *frame_buff)
{
	t_mlx_displayer		*displayer;
	t_line_to_display	line_to_display;
	int					i;

	i = 0;
	displayer = (t_mlx_displayer *)self;
	background_render(displayer->sky_color, displayer->ground_color, displayer->mlx);
	while (i < NBR_RAY)
	{
		init_line_to_draw_boundary(&line_to_display, frame_buff, i);
		init_line_to_draw_texture(&line_to_display, frame_buff, displayer, i);
		init_line_to_draw_x_texture(&line_to_display, frame_buff, i);
		draw_the_line(displayer, &line_to_display, i);
		i++;
	}
}

//for each pixel of the line, we are searching the correspondent into the texture that we defined.
void	draw_the_line(const t_mlx_displayer *displayer, t_line_to_display *line_to_display, int i)
{
	int		screen_x;
	int		y;

	y = line_to_display->draw_start;
	screen_x = (i * WIDTH / NBR_RAY);
	while (y < line_to_display->draw_end)
	{
		init_line_to_draw_y_texture( line_to_display, y);
		init_line_to_draw_pixel_color(line_to_display);
		my_pixel_put(screen_x, y, &displayer->mlx->img, line_to_display->color);
		++y;
	}
}