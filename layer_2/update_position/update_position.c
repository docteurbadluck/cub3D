/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:57:22 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_position.h"
#include "update_vision.h"

void	update_position(t_player *player,
	const t_i_controller *i_controller, const t_map *map)
{
	key_action(player, i_controller, map);
	mouse_action(player, i_controller);
}

void	key_action(t_player *player,
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

void	mouse_action(t_player *player, const t_i_controller *i_controller)
{
	float	dx_mouse;

	dx_mouse = 0;
	dx_mouse = i_controller->get_mouse_delta_x(i_controller->context);
	if (dx_mouse != 0)
		player_rotate(player, dx_mouse * ROTATION_SPEED_MOUSE);
}
