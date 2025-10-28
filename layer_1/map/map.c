/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:37:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 13:26:39 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "sprite.h"
#include <stdio.h> 

int	map_is_wall(const t_map *map, double pos_x, double pos_y)
{
	int		index_x;
	int		index_y;
	float	case_pos_x;
	float	case_pos_y;

	index_x = (int) pos_x / map->size_of_block ;
	index_y = (int)pos_y / map->size_of_block ;
	case_pos_x = pos_x / map->size_of_block;
	case_pos_y = pos_y / map->size_of_block;
	if (index_x < 0 || index_y < 0
		|| index_x >= map->width
		|| index_y >= map->height)
		return (1);
	if (map->grid[index_y][index_x] == 1)
		return (1);
	if (map->grid[index_y][index_x] != 0)
	{
		if (fabs(case_pos_x - index_x - 0.5) < 0.2 && 
			fabs(case_pos_y - index_y - 0.5) < 0.2)
			return (1);
	}
	return (0);
}

t_map	*init_map(int height, int width, int size_of_block, int **grid)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	m->height = height;
	m->width = width;
	printf("height map : %d width map : %d\n", m->height, m->width);
	m->size_of_block = size_of_block;
	m->grid = grid;
	m->sprite_count = count_sprite_on_map((const t_map *) m);
	return (m);
}

int	count_sprite_on_map(const t_map *map)
{
	int			i;
	int			y;
	int			count;

	count = 0;
	i = 0;
	while (i < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->grid[y][i] == 3 || 
				map->grid[y][i] == 4 || map->grid[y][i] == 5)
				count++;
			y++;
		}
		i++;
	}
	return (count);
}
