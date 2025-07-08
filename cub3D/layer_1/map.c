#include "map.h"
#include <stdio.h> 

int map_is_wall(const t_map *map, double pos_x, double pos_y)
{
	int index_x =(int) pos_x / map->size_of_block ;
	int index_y = (int)pos_y / map->size_of_block ;

	if (index_x < 0 || index_y < 0 ||
			index_x >= map->width ||
			index_y >= map->height)
	{
		return 1;
	}
	if (map->grid[index_y][index_x] != 0)
	{
		return 1;
	}
	return 0;
}


void map_print(const t_map *m)
{
    for (int y = 0; y < m->height; y++) {
        for (int x = 0; x < m->width; x++) {
            if (m->grid[y][x] == 1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

void map_print_with_player(t_map *m, double px, double py)
{
    int player_x = px / m->size_of_block;
    int player_y = py / m->size_of_block;

    for (int y = 0; y < m->height; y++) {
        for (int x = 0; x < m->width; x++) {
            if (x == player_x && y == player_y)
                printf("P");
            else if (m->grid[y][x] == 1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

