/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:59:18 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "raycaster.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#include "game.h"
#include "update_position.h"
#include "update_vision.h"

int	game_loop(void *param)
{
	t_game_context	*ctx;

	ctx = (t_game_context *)param;
	update_position(ctx->player, ctx->controller, ctx->map);
	update_vision(ctx->player, ctx->map, ctx->displayer, ctx->sprites);
	return (0);
}

void	start_game_loop(t_mlx_game *GAME)
{
	mlx_loop_hook(GAME->my_mlx->mlx_ptr, game_loop, GAME->game_context);
	mlx_loop(GAME->my_mlx->mlx_ptr);
}
