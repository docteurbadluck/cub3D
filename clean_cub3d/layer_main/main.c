/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:34:40 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 14:48:31 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"

# define CYAN			0x00FFFF
# define YELLOW			0xFFFF00

int **create_grid(int height, int width)
{
	int	**grid;

		grid = malloc(sizeof(int *) * height);
		for (int y = 0; y < height; y++)
	{
		grid[y] = malloc(sizeof(int) * width);
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
				grid[y][x] = 1;
			else
				grid[y][x] = 0;
		}
	}
	return grid;
}
int main()
{
	t_mlx_game	game;
	t_init_data	init_data;
	
	int **grid;
	char *pathnames[] =
	{
	"/home/tdeliot/Desktop/cub3D/clean_cub3d/layer_5/texture/stone_wall.xpm",
	"/home/tdeliot/Desktop/cub3D/clean_cub3d/layer_5/texture/planks.xpm",
	"/home/tdeliot/Desktop/cub3D/clean_cub3d/layer_5/texture/paving.xpm",
	"/home/tdeliot/Desktop/cub3D/clean_cub3d/layer_5/texture/stone.xpm",
	NULL
	};


	init_data.player_pos_x = 15;
	init_data.player_pos_y = 15;
	init_data.camera_direction = 0.0;
	
	init_data.map_height = 10;
	init_data.map_width = 10;
	grid = create_grid(init_data.map_height, init_data.map_width); // to replace by the reel map
	init_data.grid = grid;

	init_data.sky_color = CYAN;
	init_data.ground_color = YELLOW;
	init_data.textures_paths = pathnames;
	
	start_game(&game, &init_data);
	return 0;
}