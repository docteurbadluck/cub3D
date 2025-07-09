/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:36:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 10:37:13 by tdeliot          ###   ########.fr       */
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
}	t_map;

int		map_is_wall(const t_map *map, double pos_x, double pos_y);
t_map	*init_map(int height, int width, int size_of_block, int **grid);

#endif
