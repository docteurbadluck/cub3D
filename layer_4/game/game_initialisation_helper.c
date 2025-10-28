/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialisation_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 16:47:25 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "raycaster.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#include "game.h"
#include "update_position.h"
#include "update_vision.h"

void	sprite_initialisation(t_mlx_game *GAME)
{
	GAME->game_context->sprites = create_sprite_from_map(
			GAME->game_context->map, GAME->game_context->player);
}

void	mouse_initialisation(t_mlx_game *GAME)
{
	mlx_hook(GAME->my_mlx->win_ptr, 6, 1L << 6,
		&mouse_move_handler, GAME->game_context->controller->context);
}
