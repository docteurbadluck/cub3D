/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 10:20:56 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"

// TODO 
#define WHITE	0xFFFFFF
#define BLACK	0x000000
#define CYAN	0x00FFFF
#define RED		0xFF0000

typedef struct s_pixel_data
{
	int	map_x;
	int	map_y;
	int	color;
}	t_pixel_data;

void	print_a_case(int tile_size, t_mlx_displayer *displayer,
			t_pixel_data *px)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < tile_size)
	{
		dx = 0;
		while (dx < tile_size)
		{
			my_pixel_put(px->map_x * tile_size + dx,
				px->map_y * tile_size + dy, &displayer->minimap_img, px->color);
			dx++;
		}
		dy++;
	}
}

// we look in map if a case is 0 for void and something else for wall. 
// tile_size is the size of a case. we want that the map always goes into 
// the size of the case depend of the defining size of the minimap.
void	minimap_background(t_mlx_displayer *displayer,
			const t_map *map, int tile_size)
{
	t_pixel_data	px;

	px.map_y = 0;
	while (px.map_y < map->height)
	{
		px.map_x = 0;
		while (px.map_x < map->width)
		{
			if (map->grid[px.map_y][px.map_x] != 0)
				px.color = WHITE;
			else
				px.color = CYAN;
			print_a_case(tile_size, displayer, &px);
			px.map_x++;
		}
		++px.map_y;
	}
}

void	minimap_player(t_mlx_displayer *displayer, const t_map *map,
			int tile_size, const t_player *player)
{
	int	px;
	int	py;
	int	dy;
	int	dx;

	px = player->pos_x / map->size_of_block * tile_size;
	py = player->pos_y / map->size_of_block * tile_size;
	dy = -2;
	dx = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			my_pixel_put(px + dx, py + dy, &displayer->minimap_img, RED);
			dx++;
		}
		dy++;
	}
}

int	init_tile_size(const t_map *map, int minimap_height, int minimap_width)
{
	int	size_img;
	int	map_x_tile;
	int	map_y_tile;

	if (minimap_height >= minimap_width)
		size_img = minimap_width;
	else
		size_img = minimap_height;
	map_x_tile = size_img / map->width; 
	map_y_tile = size_img / map->height;
	if (map_x_tile > map_y_tile)
	{
		return (map_y_tile);
	}
	return (map_x_tile);
}

void	mlx_display_minimap(t_i_displayer *self,
			const t_map *map, const t_player *player)
{
	t_mlx_displayer	*disp;
	int				tile_size;

	disp = (t_mlx_displayer *)self;
	tile_size = init_tile_size(map, disp->minimap_img.height,
			disp->minimap_img.width);
	minimap_background(disp, map, tile_size);
	minimap_player(disp, map, tile_size, player);
	mlx_put_image_to_window(disp->mlx->mlx_ptr,
		disp->mlx->win_ptr, disp->minimap_img.img_ptr, 0, 0);
}
