/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite_from_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:54:42 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 16:59:03 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "raycaster.h"

//create the sprite type 3 or 4 writen on the map.
t_sprite	*create_sprite_from_map(const t_map *map, t_player *player)
{
	t_sprite	*my_sprites;

	if (!map->sprite_count)
		return (NULL);
	my_sprites = malloc(sizeof(t_sprite) * map->sprite_count);
	if (!my_sprites)
		return (NULL);
	init_position_sprite_from_map(map, my_sprites);
	update_sprites_data(my_sprites, player, map);
	return (my_sprites);
}

void	init_position_sprite_from_map(const t_map *map, t_sprite *my_sprites)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 3 || 
				map->grid[y][x] == 4 || map->grid[y][x] == 5)
			{
				init_sprite_pos(&my_sprites[z], x + 0.5, y + 0.5);
				my_sprites[z].type = map->grid[y][x];
				z++;
			}
			x++;
		}
		y++;
	}
}

void	init_sprite_pos(t_sprite *my_sprite, double sprite_pos_x,
			double sprite_pos_y)
{
	my_sprite->sprite_pos_x = sprite_pos_x;
	my_sprite->sprite_pos_y = sprite_pos_y; 
	my_sprite->case_x = (int)sprite_pos_x;
	my_sprite->case_y = (int)sprite_pos_y;
}
