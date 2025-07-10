/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 14:10:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "game_context.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#define SIZE_OF_BLOCK 10

int	game_loop(void *param)
{
	t_game_context	*ctx;

	ctx = (t_game_context *)param;
	
	update_position(&ctx->player, ctx->controller, ctx->map);
	//update_vision(&ctx->player, ctx->map, ctx->displayer);
	return (0);
}

void	start_game(t_mlx_game	*GAME, t_init_data *init)
{
	GAME->my_mlx = malloc(sizeof(t_mlx_data));
	GAME->game_context = malloc(sizeof(t_game_context));
	if (!GAME->game_context)
	{
		perror("malloc");
		exit(1);
	}
	init_mlx(GAME->my_mlx);
	mlx_hook(GAME->my_mlx->win_ptr, 2, 1L << 0, on_key_press, &GAME);
	mlx_hook(GAME->my_mlx->win_ptr, 3, 1L << 1, on_key_release, &GAME);
	mlx_hook(GAME->my_mlx->win_ptr, 17, 0, close_window, &GAME);
	
	GAME->game_context->controller = create_controller(GAME->my_mlx);
	GAME->game_context->displayer = 
		create_displayer(GAME->my_mlx,
			init->textures_paths,
			init->sky_color,
			init->ground_color);
	
	init_player(&GAME->game_context->player,
		init->player_pos_x, init->player_pos_y, init->camera_direction);
	init_map(init->map_height, init->map_width, SIZE_OF_BLOCK, init->grid);/*
	mlx_loop_hook(GAME->my_mlx->mlx_ptr, game_loop, GAME->game_context);
	mlx_loop(GAME->my_mlx->mlx_ptr);*/
}
