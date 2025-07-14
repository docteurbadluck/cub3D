/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 13:11:02 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "game_context.h"
#include "mlx_displayer.h"

void	free_map_grid(t_map *map)
{
	int	y;

	if (!map || !map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
}

void	destroy_texture(t_mlx_displayer *ptr_displayer)
{
	int	i;

	i = 0;
	while (i < ptr_displayer->nbr_textures)
	{
		mlx_destroy_image(ptr_displayer->mlx->mlx_ptr,
			ptr_displayer->textures[i].img_ptr);
		i++;
	}
}

// free the allocated space for the image, the screen and the display.
//(display is the connection beetween the server x and the program)
void	close_clean(t_mlx_game *GAME)
{
	t_mlx_displayer	*ptr_displayer;

	free(GAME->game_context->player);
	ptr_displayer = (t_mlx_displayer *)GAME->game_context->displayer;
	destroy_texture(ptr_displayer);
	free(ptr_displayer->textures);
	mlx_destroy_image(GAME->my_mlx->mlx_ptr, ptr_displayer->minimap_img.img_ptr);
	free(GAME->game_context->controller);
	free(GAME->game_context->displayer);
	free_map_grid(GAME->game_context->map);
	free(GAME->game_context->map);
	mlx_destroy_image(GAME->my_mlx->mlx_ptr, GAME->my_mlx->img.img_ptr);
	mlx_destroy_window(GAME->my_mlx->mlx_ptr, GAME->my_mlx->win_ptr);
	mlx_destroy_display(GAME->my_mlx->mlx_ptr);
	free(GAME->my_mlx->mlx_ptr);
	free(GAME->game_context);
	free(GAME->my_mlx);
	exit(0);
}

int	close_window(t_mlx_game *GAME)
{
	close_clean(GAME);
	return (0);
}
