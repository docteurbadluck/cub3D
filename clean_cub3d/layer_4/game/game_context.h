/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:38:03 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 14:50:08 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CONTEXT_H
# define GAME_CONTEXT_H

struct	s_player;
struct	s_map;
struct	s_i_controller;
struct	s_i_displayer;

typedef struct s_game_context
{
	struct s_player			*player;
	struct s_map			*map;
	struct s_i_controller	*controller;
	struct s_i_displayer	*displayer;
} t_game_context;

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

struct s_mlx_game;
typedef struct s_mlx_game t_mlx_game;

void	start_game(t_mlx_game	*GAME, t_init_data *init);

#endif