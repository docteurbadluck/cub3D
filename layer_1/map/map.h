/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:36:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:53:11 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>

typedef struct s_map
{
	int	height;
	int	width;
	int	**grid;
	int	size_of_block;
	int	sprite_count;
}	t_map;

//	***MAP***
int		map_is_wall(const t_map *map, double pos_x, double pos_y);

//	***MAP***
t_map	*init_map(int height, int width, int size_of_block, int **grid);

//	***MAP***
void	print_grid(int **grid, int rows, int cols);

//helper
int		count_sprite_on_map(const t_map *map);

#endif
