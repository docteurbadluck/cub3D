/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 13:58:57 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "raycaster.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#include "game.h"
#include "update_position.h"
#include "update_vision.h"

void	start_game(t_mlx_game	*GAME, t_init_data *init)
{
	game_initialisation(GAME, init);
	start_game_loop(GAME);
}
