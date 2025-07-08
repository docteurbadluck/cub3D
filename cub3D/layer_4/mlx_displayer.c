/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 17:50:01 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../layer_3/displayer.h"
#include "mlx_displayer.h"


void my_pixel_put(int x, int y, t_img *img, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;  // sécurité pour ne pas écrire hors de l'image

	char *dst = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	background_render(int color_sky, int color_ground, t_mlx_data *my_mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y, &my_mlx->img, color_sky);
			x++;
		}
		y++;
	}
	while (y < HEIGHT )
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y,  &my_mlx->img, color_ground);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
		my_mlx->img.img_ptr, 0, 0);
}
#include <stdio.h>



// Load texture function

void mlx_display(const t_displayer *self, const t_framebuffer *frame_buff)
{
	t_mlx_displayer *displayer = (t_mlx_displayer *)self;

	if (!displayer->first_texture.img_pixels_ptr)
	{
		printf("Error: texture addr is NULL\n");
		exit(EXIT_FAILURE);
	}
	background_render(displayer->sky_color, displayer->ground_color, displayer->mlx);
	(void)frame_buff;
	printf("texture : %d %d\n", displayer->first_texture.height, displayer->first_texture.width);
	
	
	for (int i = 0; i < NBR_RAY; i++)
	{
		printf("rays[i].hit_y : %f\nrays[i].hit_x : %f\n", frame_buff->rays[i].hit_y, frame_buff->rays[i].hit_x);
	}

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

		// === Texture sampling using hit_x / hit_y ===
		//printf("rays hit y %f\n",frame_buff->rays[i].hit_x);
		double wall_x = (frame_buff->rays[i].side == 0) ? frame_buff->rays[i].hit_y : frame_buff->rays[i].hit_x;
		wall_x -= floor(wall_x);  // keep only fractional part  
		
		int tex_x = (int)(wall_x * displayer->first_texture.width);
		//printf("tex_x avant correction  : %d\n", tex_x);

		if (tex_x < 0) tex_x = 0;
		if (tex_x >= displayer->first_texture.width) tex_x = displayer->first_texture.width - 1;

	//	printf("tex_x : %d\n", tex_x);

		// Draw textured vertical slce
		for (int y = draw_start; y < draw_end; y++)
		{
			int d = y * 256 - HEIGHT * 128 + line_height * 128;
			int tex_y = ((d * displayer->first_texture.height) / line_height) / 256;
			if (tex_y < 0) 
				tex_y = 0;
			if (tex_y >= displayer->first_texture.height) 
				tex_y = displayer->first_texture.height - 1;
			char *pixel = displayer->first_texture.img_pixels_ptr
			+ tex_y * displayer->first_texture.line_len
			+ tex_x * (displayer->first_texture.bits_per_pixel / 8);
			int color = *(int *)pixel;
			my_pixel_put(screen_x, y, &displayer->mlx->img, color);
		}
	}
}

// color are not in framebuffer anymore but in displayer 
// functionning white wall 
/*
void mlx_display(const t_displayer *self, const t_framebuffer *frame_buff)
{
	const t_mlx_displayer *displayer = (const t_mlx_displayer *)self;

	// Fill background (e.g., sky and floor)
	background_render(displayer->sky_color, displayer->ground_color, displayer->mlx);

	for (int i = 0; i < NBR_RAY; i++)
	{
		double dist = (frame_buff->rays[i].distance);
		if (dist < 0.0001)
			dist = 0.0001;
		int line_height = (int)(HEIGHT / dist);
		int draw_start = (HEIGHT - line_height) / 2;
		int draw_end = (HEIGHT + line_height) / 2;
		int screen_x = (i * WIDTH) / NBR_RAY;
		// Clamp drawing boundaries
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end > HEIGHT)
			draw_end = HEIGHT;

		for (int y = draw_start; y < draw_end; y++)
		{
			my_pixel_put(screen_x, y, &displayer->mlx->img, 0xFFFFFF);
		}
	}
}*/


void mlx_clear_screen(const t_displayer *self)
{
	t_mlx_displayer *d = (t_mlx_displayer *)self;
	mlx_clear_window(d->mlx->mlx_ptr, d->mlx->win_ptr);
}

int load_texture(t_mlx_displayer *displayer, const char *filepath)
{
	if (!displayer || !filepath)
		return -1;
	displayer->first_texture.img_ptr = mlx_xpm_file_to_image(
		displayer->mlx->mlx_ptr,
		(char *)filepath,
		&displayer->first_texture.width,
		&displayer->first_texture.height);
	if (!displayer->first_texture.img_ptr)
	{
		fprintf(stderr, "Failed to load texture image: %s\n", filepath);
		return -1;
	}
	displayer->first_texture.img_pixels_ptr = mlx_get_data_addr(
		displayer->first_texture.img_ptr,
		&displayer->first_texture.bits_per_pixel,
		&displayer->first_texture.line_len,
		&displayer->first_texture.endian);
	if (!displayer->first_texture.img_pixels_ptr)
	{
		mlx_destroy_image(displayer->mlx->mlx_ptr, displayer->first_texture.img_ptr);
		displayer->first_texture.img_ptr = NULL;
		return -1;
	}
	printf("load texture success\n");
	return 0;  // success
}

void init_displayer_texture(t_displayer *displayer, const char *filepath, int sky_color, int ground_color)
{
	t_mlx_displayer *my_dipslayer = (t_mlx_displayer *)displayer;
	if (load_texture(my_dipslayer, filepath))
	{
		printf("ERROR\n");	
	}
	my_dipslayer->sky_color = sky_color;
	my_dipslayer->ground_color = ground_color;
}

 
t_displayer *create_displayer(t_mlx_data *mlx)
{
	t_mlx_displayer *displayer = malloc(sizeof(t_mlx_displayer));
	if (!displayer)
		return NULL;

	displayer->mlx = mlx;
	displayer->base.display = mlx_display;
	displayer->base.clear_screen = mlx_clear_screen; // optional

	return (t_displayer *)displayer;
}