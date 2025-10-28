/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_and_map_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:40:59 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 16:47:13 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "raycaster.h"
#include "mlx_controller.h"
#include "mlx_displayer.h"
#include "game.h"
#include "update_position.h"
#include "update_vision.h"

void	player_initialisation(t_mlx_game	*GAME, t_init_data *init)
{
	erase_player_spawn_position_on_grid(init);
	give_world_position_to_player(init);
	GAME->game_context->player = malloc(sizeof(t_player));
	init_player(GAME->game_context->player,
		init->player_pos_x, init->player_pos_y, init->camera_direction);
}

void	erase_player_spawn_position_on_grid(t_init_data *init)
{
	init->grid[init->player_pos_y][init->player_pos_x] = 0;
}

void	give_world_position_to_player(t_init_data *init)
{
	init->player_pos_x *= SIZE_OF_BLOCK;
	init->player_pos_y *= SIZE_OF_BLOCK;
	init->player_pos_x += SIZE_OF_BLOCK / 2;
	init->player_pos_y += SIZE_OF_BLOCK / 2;
}

void	map_initialisation(t_mlx_game	*GAME, t_init_data *init)
{
	GAME->game_context->map = 
		init_map(init->map_height, init->map_width, SIZE_OF_BLOCK, init->grid);
}
