/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:55:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:55:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "raycaster.h"

void	update_sprites_data(t_sprite *my_sprite,
			const t_player *player, const t_map *map)
{
	int	i;

	i = 0;
	while (i < map->sprite_count)
	{
		update_sprite_data(&my_sprite[i], player, map);
		i++;
	}
}

void	update_sprite_data(t_sprite *my_sprite,
			const t_player *player, const t_map *map)
{
	init_sprite_info_player(my_sprite, player, map);
	init_sprite_vector_game_unit(my_sprite);
	init_sprite_normalisation_vector(my_sprite);
	init_sprite_scalar_factor(my_sprite);
	my_sprite->flag_in_fov = is_sprite_in_fov(my_sprite);
	if (my_sprite->type == 3)
		my_sprite->flag_move = 0;
	else 
		my_sprite->flag_move = 1;
}

// lenght 			 :: theorem of pythagorus
// normalised vector :: usefull for scalar type 
void	init_sprite_normalisation_vector(t_sprite *my_sprite)
{
	my_sprite->lenght_sprite_v = 
		sqrt(my_sprite->vector_player_to_sprite_x * 
			my_sprite->vector_player_to_sprite_x + 
			my_sprite->vector_player_to_sprite_y * 
			my_sprite->vector_player_to_sprite_y);
	my_sprite->vector_p_to_s_x_normalise = 
		my_sprite->vector_player_to_sprite_x / my_sprite->lenght_sprite_v;
	my_sprite->vector_p_to_s_y_normalise = 
		my_sprite->vector_player_to_sprite_y / my_sprite->lenght_sprite_v;
}

void	init_sprite_scalar_factor(t_sprite *my_sprite)
{
	my_sprite->scalar_factor = my_sprite->vector_player_direction_x * 
		my_sprite->vector_p_to_s_x_normalise + 
		my_sprite->vector_player_direction_y * 
		my_sprite->vector_p_to_s_y_normalise;
}

int	is_sprite_in_fov(t_sprite *my_sprite)
{
	double	margin;

	margin = 0.2;
	if (my_sprite->scalar_factor > cos(my_sprite->player_fov / 2 + margin))
	{
		return (1);
	}
	return (0);
}
