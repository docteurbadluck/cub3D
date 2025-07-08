#ifndef MAP_H
#define MAP_H

#include <stdlib.h>



typedef struct s_map
{
	int	height;
	int	width;
	int	**grid;
	int	size_of_block;
} t_map;

int		map_is_wall(const t_map *map, double pos_x, double pos_y);
t_map	*init_map(int height, int width, int size_of_block, int **grid);
/*
void	map_print(const t_map *m);
void	map_print_with_player(t_map *m, double px, double py);*/

#endif
