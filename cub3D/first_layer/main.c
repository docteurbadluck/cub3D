#include "player.h"
#include "map.h"
#include "raycaster.h"
#include <stdio.h>


int main()
{
	t_player A;
	t_map m;
	
	m.height = 10;
	m.width = 10;
	m.size_of_block = 10;
	m.grid = malloc(sizeof(int *) * m.height);
	for (int y = 0; y < m.height; y++)
	{
		m.grid[y] = malloc(sizeof(int) * m.width);
    		for (int x = 0; x < m.width; x++)
		{
			if (y == 0 || y == m.height - 1 || x == 0 || x == m.width - 1)
				m.grid[y][x] = 1;
			else
				m.grid[y][x] = 0;
    		}
	}
	m.grid[5][8] = 1;
	A.pos_x = 50;
	A.pos_y = 50;
	A.camera_direction = 0;

	A.speed = 10;
	A.rotation_speed = 0.01;
	map_print_with_player(&m, A.pos_x, A.pos_y);	
	for (double angle = 0; angle < 2 * M_PI; angle += M_PI / 16)
	{
    		A.camera_direction = angle;
    		double dist = raycasting(&A, &m);
   		printf("angle = %.2f rad → distance = %.2f\n", angle, dist);
	}	
	return 0;
}
