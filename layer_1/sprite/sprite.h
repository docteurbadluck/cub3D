/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:11:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:10:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "raycaster.h"

typedef struct s_sprite
{
	double		sprite_pos_x;
	double		sprite_pos_y;
	int			case_x;
	int			case_y;

	double		player_pos_x;
	double		player_pos_y;
	double		player_direction;
	double		player_fov;
	int			size_of_block;

	double		vector_player_to_sprite_x;
	double		vector_player_to_sprite_y;
	double		vector_p_to_s_x_normalise;
	double		vector_p_to_s_y_normalise;

	double		vector_player_direction_x;
	double		vector_player_direction_y; 
	double		vector_p_d_x_normalise;
	double		vector_p_d_y_normalise;

	double		lenght_player;
	double		lenght_sprite_v;

	double		scalar_factor;
	int			flag_in_fov;

	t_raycast	*the_walls;

	int			flag_move;
	int			type;
}	t_sprite;

//	***CREATE_SPRITE_FROM_MAP***
t_sprite	*create_sprite_from_map(const t_map *map, t_player *player);

//	***UPDATES_SPRITES_DATA
void		update_sprites_data(t_sprite *my_sprite,
				const t_player *player, const t_map *map);

//helper
void		init_sprite_pos(t_sprite *my_sprite, double sprite_pos_x,
				double sprite_pos_y);
void		update_sprite_data(t_sprite *my_sprite,
				const t_player *player, const t_map *map);
int			is_sprite_in_fov(t_sprite *my_sprite);
void		init_sprite_info_player(t_sprite *my_sprite,
				const t_player *player, const t_map *map);
void		init_sprite_vector_game_unit(t_sprite *my_sprite);
void		init_position_sprite_from_map(const t_map *map,
				t_sprite *my_sprites);
void		init_sprite_normalisation_vector(t_sprite *my_sprite);
void		init_sprite_scalar_factor(t_sprite *my_sprite);
int			is_sprite_in_fov(t_sprite *my_sprite);

#endif