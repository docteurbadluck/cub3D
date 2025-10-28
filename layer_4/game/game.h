/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:38:03 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 12:26:30 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "init_data.h"

struct						s_player;
struct						s_map;
struct						s_i_controller;
struct						s_i_displayer;
struct						s_sprite;
struct						s_mlx_game;
typedef struct s_mlx_game	t_mlx_game;

typedef struct s_game_context
{
	struct s_player			*player;
	struct s_map			*map;
	struct s_i_controller	*controller;
	struct s_i_displayer	*displayer;
	struct s_sprite			*sprites;
}	t_game_context;

//	***START_GAME***
void	start_game(t_mlx_game	*GAME, t_init_data *init);

//	***START_GAME_LOOP***
void	start_game_loop(t_mlx_game *GAME);

//	***GAME_INITIALISATION***
void	game_initialisation(t_mlx_game	*GAME, t_init_data *init);

//helper
void	allocate_game_memory(t_mlx_game *GAME);
void	controller_initialisation(t_mlx_game	*GAME);
void	displayer_initialisation(t_mlx_game	*GAME, t_init_data *init);
void	sprite_initialisation(t_mlx_game *GAME);
void	mouse_initialisation(t_mlx_game *GAME);
void	init_mlx_hook(t_mlx_game *GAME);
void	player_initialisation(t_mlx_game	*GAME, t_init_data *init);
void	map_initialisation(t_mlx_game	*GAME, t_init_data *init);
void	erase_player_spawn_position_on_grid(t_init_data *init);
void	give_world_position_to_player(t_init_data *init);

#endif