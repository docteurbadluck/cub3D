/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:37:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 15:24:08 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h> 

//return 1 if the position given is in a block or outside the map.
int	map_is_wall(const t_map *map, double pos_x, double pos_y)
{
	int	index_x;
	int	index_y;

	index_x = (int) pos_x / map->size_of_block ;
	index_y = (int)pos_y / map->size_of_block ;
	if (index_x < 0 || index_y < 0
		|| index_x >= map->width
		|| index_y >= map->height)
	{
		return (1);
	}
	if (map->grid[index_y][index_x] == 1)
	{
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
	m->size_of_block = size_of_block;
	m->grid = grid;
	return (m);
}
