/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:50:04 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/11 12:16:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_print_state(const t_player *player)
{
	printf("pos_y : %f pos_x %f camera_direction : %f\n",
		player->pos_y,
		player->pos_x,
		player->camera_direction);
}

void	init_player(t_player *A, int pos_x, int pos_y, double camera_direction)
{
	A->pos_x = pos_x;
	A->pos_y = pos_y;
	A->camera_direction = camera_direction;
	A->rotation_speed = M_PI/90; // ROTATION_SPEED;
	A->speed = 0.4; // has been change to something little SPEED
	A->fov = FOV;
}
