/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 11:57:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "../game_context.h"


void	free_map_grid(t_map *map)
{
	int y;

	if (!map || !map->grid)
		return;

	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
	map->grid = NULL;
}

// free the allocated space for the image, the screen and the display.
//(display is the connection beetween the server x and the program)
void	close_clean(t_mlx_game *screen)
{
	free(screen->ctx->controller);
	free(screen->ctx->displayer);
	free_map_grid(screen->ctx->map);
	free(screen->ctx->map);
	mlx_destroy_image(screen->my_mlx->mlx_ptr, screen->my_mlx->img.img_ptr);
	mlx_destroy_window(screen->my_mlx->mlx_ptr, screen->my_mlx->win_ptr);
	mlx_destroy_display(screen->my_mlx->mlx_ptr);
	free(screen->my_mlx->mlx_ptr);
	exit(0);
}

int	close_window(t_mlx_game *screen)
{
	close_clean(screen);
	return (0);
}

