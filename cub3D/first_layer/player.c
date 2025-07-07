#include "player.h"
#include <math.h>
#include <stdio.h>


void player_move_backward(t_player *player, const t_map *map)
{
	double dx = cos(player->camera_direction) * player->speed;
	double dy = sin(player->camera_direction) * player->speed;

	double new_x = player->pos_x - dx;
	double new_y = player->pos_y - dy;

	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}


void player_move_forward(t_player *player, const t_map *map)
{
	double dx = cos(player->camera_direction) * player->speed;
	double dy = sin(player->camera_direction) * player->speed;

	double new_x = player->pos_x + dx;
	double new_y = player->pos_y + dy;
	if (!map_is_wall(map, new_x, player->pos_y))
		player->pos_x = new_x;
	if (!map_is_wall(map, player->pos_x, new_y))
		player->pos_y = new_y;
}

void player_rotate_step(t_player *player, int right)
{
	if (right)
	{
		player->camera_direction += player->rotation_speed;
	}
	else 
	{
		player->camera_direction -= player->rotation_speed;
	}
	if(player->camera_direction < 0)
		player->camera_direction+= 2* M_PI;
	if(player->camera_direction >= 2 * M_PI)
		player->camera_direction -= 2* M_PI;
}

void player_rotate(t_player *player, double angle)
{
    player->camera_direction += angle;
    if (player->camera_direction < 0)
        player->camera_direction += 2 * M_PI;
    if (player->camera_direction >= 2 * M_PI)
        player->camera_direction -= 2 * M_PI;
}

void player_print_state(const t_player *player)
{
	printf("pos_y : %f pos_x %f camera_direction : %f\n",
		       	player->pos_y,
			player->pos_x,
			player->camera_direction);
}
