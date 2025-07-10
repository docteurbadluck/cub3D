/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:38:03 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 13:27:53 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTEXT_H
# define GAME_CONTEXT_H
# include "update_vision.h"
# include "update_position.h"
# include "mlx_context.h"

typedef struct s_game_context
{
	t_player		player;
	t_map			*map;
	t_i_controller	*controller;
	t_i_displayer	*displayer;
}	t_game_context;

//textures_paths :
//should be nullterminated AND THE first four represente respectively N S E W
//map heigh nbr of case of grid
typedef struct s_init_data
{
	char	**textures_paths; 
	int		sky_color;
	int		ground_color;

	int		player_pos_x;
	int		player_pos_y;
	double	camera_direction;

	int		map_height;
	int		map_width;
	int		**grid;
}	t_init_data;

void	start_game(t_mlx_game	*GAME, t_init_data *init);

#endif