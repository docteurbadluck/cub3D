/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:14:26 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 13:26:30 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "raycaster.h"

void	init_sprite_info_player(t_sprite *my_sprite,
			const t_player *player, const t_map *map)
{
	my_sprite->player_direction = player->camera_direction;
	my_sprite->player_pos_x = player->pos_x / map->size_of_block;
	my_sprite->player_pos_y = player->pos_y / map->size_of_block;
	my_sprite->player_fov = player->fov;
	my_sprite->size_of_block = map->size_of_block;
}

void	init_sprite_vector_game_unit(t_sprite *my_sprite)
{
	my_sprite->vector_player_direction_x = cos(my_sprite->player_direction);
	my_sprite->vector_player_direction_y = sin(my_sprite->player_direction);
	my_sprite->vector_player_to_sprite_x = 
		my_sprite->sprite_pos_x - my_sprite->player_pos_x;
	my_sprite->vector_player_to_sprite_y = 
		my_sprite->sprite_pos_y - my_sprite->player_pos_y;
}
