/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 10:48:39 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_player.h"
#include "update_vision.h"

void update_player(t_player *player, const t_controller *input, const t_map *map)
{
	if (input->is_move_forward_pressed(input->context))
	{
		player_move_forward(player, map);
	}
	if (input->is_move_backward_pressed(input->context))
	{
		player_move_backward(player, map);
	}
	if (input->is_turn_left_pressed(input->context))
	{
		player_rotate(player, -player->rotation_speed);
	}
	else if (input->is_turn_right_pressed(input->context))
	{
		player_rotate(player, player->rotation_speed);
	}
}