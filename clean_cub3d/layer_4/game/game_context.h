/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:38:03 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 11:53:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include "../../layer_2/update_vision/update_vision.h"
#include "../../layer_2/update_position/update_position.h"
#include "../mlx_main/mlx_context.h"

typedef struct s_game_context
{
	t_player		player;
	t_map			*map;
	t_i_controller	*controller;
	t_i_displayer	*displayer;
} t_game_context;


typedef struct s_init_data
{
	//displayer
	char	**textures_paths; //should be nullterminated AND THE first four represente respectively N S E W
	int		sky_color;
	int		ground_color;

	//player
	int		player_pos_x;
	int		player_pos_y;
	double	camera_direction;

	//map
	int map_height; //number of case in grid
	int map_width;
	int	**grid;
	
} t_init_data;

void	START_GAME(t_mlx_game	*GAME, t_init_data *init);

#endif