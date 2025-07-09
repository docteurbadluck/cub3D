/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:48:52 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 10:59:16 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_rotate_step(t_player *player, int right)
{
	if (right)
		player->camera_direction += player->rotation_speed;
	else 
		player->camera_direction -= player->rotation_speed;
	if (player->camera_direction < 0)
		player->camera_direction += 2 * M_PI;
	if (player->camera_direction >= 2 * M_PI)
		player->camera_direction -= 2 * M_PI;
}

void	player_rotate(t_player *player, double angle)
{
	player->camera_direction += angle;
	if (player->camera_direction < 0)
		player->camera_direction += 2 * M_PI;
	if (player->camera_direction >= 2 * M_PI)
		player->camera_direction -= 2 * M_PI;
}
