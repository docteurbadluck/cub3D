/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:48:44 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 13:20:47 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_move_forward(t_player *player, const t_map *map)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	dx = cos(player->camera_direction) * player->speed;
	dy = sin(player->camera_direction) * player->speed;
	new_x = player->pos_x + dx;
	new_y = player->pos_y + dy;
	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}

void	player_move_backward(t_player *player, const t_map *map)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	dx = cos(player->camera_direction) * player->speed;
	dy = sin(player->camera_direction) * player->speed;
	new_x = player->pos_x - dx;
	new_y = player->pos_y - dy;
	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}

void	player_move_left(t_player *player, const t_map *map)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	dx = cos(player->camera_direction + M_PI / 2) * player->speed;
	dy = sin(player->camera_direction + M_PI / 2) * player->speed;
	new_x = player->pos_x + dx;
	new_y = player->pos_y + dy;
	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}

void	player_move_right(t_player *player, const t_map *map)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	dx = cos(player->camera_direction + M_PI / 2) * player->speed;
	dy = sin(player->camera_direction + M_PI / 2) * player->speed;
	new_x = player->pos_x - dx;
	new_y = player->pos_y - dy;
	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}
