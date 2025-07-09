/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 10:12:54 by tdeliot          ###   ########.fr       */
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

void mlx_display(const t_displayer *self, const t_framebuffer *frame_buff)
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


// Load texture function

// work with one texture
/*
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

		double wall_x = (frame_buff->rays[i].side == 0) ? frame_buff->rays[i].hit_y : frame_buff->rays[i].hit_x;
		wall_x -= floor(wall_x);

		int tex_x = (int)(wall_x * displayer->first_texture.width);

		if (tex_x < 0) tex_x = 0;
		if (tex_x >= displayer->first_texture.width) tex_x = displayer->first_texture.width - 1;

		// Draw textured vertical slce
		printf("ray face : %c\n", frame_buff->rays[i].face);
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
}*/

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

void init_displayer_color(t_displayer *displayer, int sky_color, int ground_color)
{
	t_mlx_displayer *my_dipslayer = (t_mlx_displayer *)displayer;
	my_dipslayer->sky_color = sky_color;
	my_dipslayer->ground_color = ground_color;
}

int load_a_texture(t_mlx_displayer *displayer, char **filepath, int i)
{
	if (!displayer || !filepath[i])
		return -1;
	displayer->textures[i].img_ptr = mlx_xpm_file_to_image(
		displayer->mlx->mlx_ptr,
		filepath[i],
		&displayer->textures[i].width,
		&displayer->textures[i].height);
	if (!displayer->textures[i].img_ptr)
	{
		fprintf(stderr, "Failed to load texture image: %s\n", filepath[i]);
		return -1;
	}
		displayer->textures[i].img_pixels_ptr = mlx_get_data_addr(
		displayer->textures[i].img_ptr,
		&displayer->textures[i].bits_per_pixel,
		&displayer->textures[i].line_len,
		&displayer->textures[i].endian);
	if (!displayer->textures[i].img_pixels_ptr)
	{
		mlx_destroy_image(displayer->mlx->mlx_ptr,displayer->textures[i].img_ptr);
		displayer->textures[i].img_ptr = NULL;
		return -1;
	}
	printf("load texture success\n");
	return 0;  // success
}

void init_displayer_multiple_texture(t_displayer *displayer,char **filepath)
{
	t_mlx_displayer *my_dipslayer = (t_mlx_displayer *)displayer;
	int i = 0;

	while (filepath[i])
	{
		i++;
	}
	my_dipslayer->nbr_textures = i;
	my_dipslayer->textures = malloc(sizeof(t_img) * my_dipslayer->nbr_textures);
	i = 0;
	while (i < my_dipslayer->nbr_textures)
	{
		if (load_a_texture(my_dipslayer, filepath, i))
			printf("error texture\n");
		i++;
	}
	
}

void mlx_display_minimap(const t_displayer *self, const t_map *map, const t_player *player)
{
	t_mlx_displayer *disp = (t_mlx_displayer *)self;
	int tile_size = 10; // pixels per tile

	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			int color = (map->grid[y][x] != 0) ? 0xFFFFFF : 0x000000;

			for (int dy = 0; dy < tile_size; dy++)
			{
				for (int dx = 0; dx < tile_size; dx++)
				{
					my_pixel_put(x * tile_size + dx, y * tile_size + dy, &disp->minimap_img, color);
				}
			}
		}
	}

	// Draw player on top (as a red square)
	int px = player->pos_x / map->size_of_block * tile_size;
	int py = player->pos_y / map->size_of_block * tile_size;
	for (int dy = -2; dy <= 2; dy++)
		for (int dx = -2; dx <= 2; dx++)
			my_pixel_put(px + dx, py + dy, &disp->minimap_img, 0xFF0000);

	// Draw the minimap image to the screen at top-left corner
	mlx_put_image_to_window(disp->mlx->mlx_ptr, disp->mlx->win_ptr, disp->minimap_img.img_ptr, 0, 0);
}



t_displayer *create_displayer(t_mlx_data *mlx)
{
	t_mlx_displayer *displayer = malloc(sizeof(t_mlx_displayer));
	if (!displayer)
		return NULL;

	displayer->mlx = mlx;
	displayer->base.display = mlx_display;
	displayer->base.clear_screen = mlx_clear_screen; // optional
	displayer->base.display_minimap = mlx_display_minimap;

	
	displayer->minimap_img.img_ptr = mlx_new_image(mlx->mlx_ptr, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	displayer->minimap_img.img_pixels_ptr = mlx_get_data_addr(
	displayer->minimap_img.img_ptr,
	&displayer->minimap_img.bits_per_pixel,
	&displayer->minimap_img.line_len,
	&displayer->minimap_img.endian);

	return (t_displayer *)displayer;
}