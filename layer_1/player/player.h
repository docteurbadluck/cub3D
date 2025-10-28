/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:55:51 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 17:34:39 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdio.h>
# include <math.h>
# include "map.h"
# define SPEED 0.4
# define ROTATION_SPEED 0.0174532925
# define FOV 1.570796326794897

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	speed;

	double	camera_direction;
	double	rotation_speed;
	double	fov;
}	t_player;

//	***PLAYER_MOOVE***
void	player_move_forward(t_player *player, const t_map *map);
void	player_move_backward(t_player *player, const t_map *map);
void	player_move_left(t_player *player, const t_map *map);
void	player_move_right(t_player *player, const t_map *map);

//	***PLAYER_ROTATE***
void	player_rotate(t_player *player, double angle);

//	***PLAYER_HELPER***
void	player_print_state(const t_player *player);
void	init_player(t_player *A, int pos_x, int pos_y, double camera_direction);

#endif
