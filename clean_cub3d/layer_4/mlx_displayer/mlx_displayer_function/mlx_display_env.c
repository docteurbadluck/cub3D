/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 10:00:53 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "mlx_displayer_function.h"


typedef struct s_line_to_display
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		screen_x;

	t_img	*texture;
	int		texture_x;
	int		texture_y;

	char	*pixel;
	int		color;
}	t_line_to_display;


// this function look at the size of the screen to calcule the lenght of the line to display.
// draw start and draw end are the boundary of what we will draw.
void	init_line_to_draw_boundary(t_line_to_display *line_to_display, const t_framebuffer *frame_buff, int i)
{
	double	dist;
	int		line_height;
	
	dist = frame_buff->rays[i].distance;
	if (dist < 0.0001)
		dist = 0.0001;
	line_height = (int)(HEIGHT / dist);
	line_to_display->line_height = line_height;
	line_to_display->draw_start = (HEIGHT - line_height) / 2;
	line_to_display->draw_end = (HEIGHT - line_height) / 2;
	if (line_to_display->draw_start < 0)
		line_to_display->draw_start = 0;
	if (line_to_display->draw_end > HEIGHT)
		line_to_display->draw_end = HEIGHT;
}

// this function decide which texture is drawn on the line.
void	init_line_to_draw_texture(t_line_to_display *line_to_display, const t_framebuffer *frame_buff, const t_mlx_displayer *displayer, int i)
{
	if (frame_buff->rays[i].face == 'N')
		line_to_display->texture = &displayer->wall_textures[0];
	else if (frame_buff->rays[i].face == 'S')
		line_to_display->texture = &displayer->wall_textures[1];
	else if (frame_buff->rays[i].face == 'E')
		line_to_display->texture = &displayer->wall_textures[2];
	else if (frame_buff->rays[i].face == 'W')
		line_to_display->texture = &displayer->wall_textures[3];
}

// this function help us to decide which par of the texture will be drawn on the line.
// for that we look were the point touch the wall. (4.5), we keep the .5, then we 
// look the corresponding point in the texture, (in this case texture->width* 0.5)
// we then verify that it's not out boundary by security. 
void	init_line_to_draw_x_texture(t_line_to_display *line_to_display, const t_framebuffer *frame_buff, int i)
{
	double	wall_x;

	if (frame_buff->rays[i].side == 0)
		wall_x = frame_buff->rays[i].hit_x;
	else
		wall_x = frame_buff->rays[i].hit_y;
	wall_x -= floor(wall_x); 
	
	line_to_display->texture_x = (int)(wall_x * line_to_display->texture->width);
	if (line_to_display->texture_x < 0)
		line_to_display->texture_x = 0;
	if (line_to_display->texture_x >= line_to_display->texture->width)
		line_to_display->texture_x = line_to_display->texture->width -1;
}


// the idea here is to find the y point of the texture that we want to render.
// we start by scaling for precision and center it.
/*
2. - HEIGHT * 128 + line_height * 128:
Centers the line vertically on screen:

Imagine HEIGHT is 480. Half of that is 240.

So we align the middle of the wall line to screen center.*/
void	init_line_to_draw_y_texture(const t_mlx_displayer *dispayer, t_line_to_display *line_to_display, int y)
{
	int	d;
	
	d = y * 256 - HEIGHT * 128 + line_to_display->line_height * 128;
	line_to_display->texture_y = ((d * line_to_display->texture->height) / line_to_display->line_height) / 256;
	if (line_to_display->texture_y < 0)
		line_to_display->texture_y = 0;
	if (line_to_display->texture_y > line_to_display->texture->height)
		line_to_display->texture_y = line_to_display->texture->height -1;
}

void	init_line_to_draw_pixel_color(t_line_to_display *line_to_display)
{
		line_to_display->pixel = line_to_display->texture->img_pixels_ptr + 
		line_to_display->texture_y * line_to_display->texture->line_len + 
		line_to_display->texture_x * (line_to_display->texture->bits_per_pixel / 8); 
		line_to_display->color = *(int *)line_to_display->pixel;
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
		init_line_to_draw_y_texture(displayer, line_to_display, y);
		init_line_to_draw_pixel_color(&line_to_display);
		my_pixel_put(screen_x, y, &displayer->mlx->img, line_to_display->color);
		++y;
	}
}

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
