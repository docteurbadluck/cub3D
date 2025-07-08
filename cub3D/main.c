/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:46:50 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 14:09:20 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_context.h"


# define CYAN        0x00FFFF
# define YELLOW      0xFFFF00

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
int game_loop(void *param)
{
	t_game_context *ctx = (t_game_context *)param;

	update_player(&ctx->player, ctx->controller, ctx->map);
	player_print_state(&ctx->player);
	update_vision(&ctx->player, ctx->map, ctx->displayer);
	
	return (0);
}

int main()
{
	t_mlx_game		all;
	t_mlx_data		my_mlx;
	t_controller	*my_controller;
	t_displayer		*my_displayer;
	t_game_context	ctx;
	int				**grid;

	all.ctx = &ctx;
	all.my_mlx = &my_mlx;
	
	grid = create_grid(10,10);
	init_mlx(&my_mlx);
	mlx_hook(my_mlx.win_ptr, 2, 1L << 0, on_key_press, &all);   // KeyPress event
	mlx_hook(my_mlx.win_ptr, 3, 1L << 1, on_key_release, &all); // KeyRelease event
	mlx_hook(my_mlx.win_ptr, 17, 0, close_window, &all);

	my_controller = create_controller(&my_mlx);
	my_displayer = create_displayer(&my_mlx);
	init_player(&ctx.player, 15, 15, 0.0);
	ctx.map = init_map(10, 10, 10, grid);
	init_map_texture(ctx.map, CYAN, YELLOW);
	
	ctx.controller = my_controller;
	ctx.displayer = my_displayer;
	mlx_loop_hook(my_mlx.mlx_ptr, game_loop, &ctx);
	mlx_loop(my_mlx.mlx_ptr);
	return 0;
}