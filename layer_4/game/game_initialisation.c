/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 16:47:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "raycaster.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#include "game.h"
#include "update_position.h"
#include "update_vision.h"

void	game_initialisation(t_mlx_game	*GAME, t_init_data *init)
{
	allocate_game_memory(GAME);
	init_mlx(GAME->my_mlx);
	init_mlx_hook(GAME);
	controller_initialisation(GAME);
	displayer_initialisation(GAME, init);
	player_initialisation(GAME, init);
	map_initialisation(GAME, init);
	sprite_initialisation(GAME);
	mouse_initialisation(GAME);
}

void	allocate_game_memory(t_mlx_game *GAME)
{
	GAME->my_mlx = malloc(sizeof(t_mlx_data));
	GAME->game_context = malloc(sizeof(t_game_context));
	if (!GAME->game_context)
		exit(1);
}

void	init_mlx_hook(t_mlx_game *GAME)
{
	mlx_hook(GAME->my_mlx->win_ptr, 2, 1L << 0, on_key_press, GAME);
	mlx_hook(GAME->my_mlx->win_ptr, 3, 1L << 1, on_key_release, GAME);
	mlx_hook(GAME->my_mlx->win_ptr, 17, 0, close_window, GAME);
}

void	controller_initialisation(t_mlx_game	*GAME)
{
	GAME->game_context->controller = create_controller(GAME->my_mlx);
}

void	displayer_initialisation(t_mlx_game	*GAME, t_init_data *init)
{
	GAME->game_context->displayer = create_displayer(GAME->my_mlx, init);
}
