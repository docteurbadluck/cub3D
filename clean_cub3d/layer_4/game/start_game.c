/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 11:37:39 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_main/mlx_context.h"
#include "game_context.h"
#include "mlx_controller/mlx_controller.h"
#include "mlx_displayer/mlx_displayer.h"
#define SIZE_OF_BLOCK 10


int game_loop(void *param)
{
	t_game_context *ctx = (t_game_context *)param;

	update_player(&ctx->player, ctx->controller, ctx->map);
	update_vision(&ctx->player, ctx->map, ctx->displayer);
	return (0);
}


void	START_GAME(t_mlx_game	*GAME, t_init_data *init)
{
	init_mlx(GAME->my_mlx);
	mlx_hook(GAME->my_mlx->win_ptr, 2, 1L << 0, on_key_press, &GAME);   // KeyPress event
	mlx_hook(GAME->my_mlx->win_ptr, 3, 1L << 1, on_key_release, &GAME); // KeyRelease event
	mlx_hook(GAME->my_mlx->win_ptr, 17, 0, close_window, &GAME);
	
	GAME->game_context->controller = create_controller(GAME->my_mlx);
	GAME->game_context->displayer = create_displayer(GAME->my_mlx, init->textures_pathfiles,init->sky_color,init->ground_color);
	init_player(&GAME->game_context->player, init->player_pos_x, init->player_pos_y, init->camera_direction);
	init_map(init->height, init->width, SIZE_OF_BLOCK, init->grid);
	
	mlx_loop_hook(GAME->my_mlx->mlx_ptr, game_loop, GAME->game_context);
	mlx_loop(GAME->my_mlx->mlx_ptr);
}
