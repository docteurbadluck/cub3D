/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/11 08:27:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_position.h"
#include "update_vision.h"

// connect player moove with, controler input.
void	update_position(t_player *player,
	const t_i_controller *i_controller, const t_map *map)
{
	if (i_controller->is_move_forward_pressed(i_controller->context))
		player_move_forward(player, map);
	if (i_controller->is_move_backward_pressed(i_controller->context))
		player_move_backward(player, map);
	if (i_controller->is_move_left_pressed(i_controller->context))
		player_move_left(player, map);
	if (i_controller->is_move_right_pressed(i_controller->context))
		player_move_right(player, map);
	if (i_controller->is_turn_left_pressed(i_controller->context))
		player_rotate(player, -player->rotation_speed);
	else if (i_controller->is_turn_right_pressed(i_controller->context))
		player_rotate(player, player->rotation_speed);
}
