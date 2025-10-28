/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:49:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 17:10:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "game.h"
#include "mlx_displayer.h"

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

void	destroy_sprite(t_mlx_displayer *ptr_displayer)
{
	int	i;
	int	y;

	i = 0;
	while (i < ptr_displayer->nbr_sprite)
	{
		y = 0;
		while (y < ptr_displayer->sprites[i].nbr_texture)
		{
			mlx_destroy_image(ptr_displayer->mlx->mlx_ptr,
				ptr_displayer->sprites[i].textures_sprite[y].img_ptr);
			y++;
		}
		free(ptr_displayer->sprites[i].textures_sprite);
		i++;
	}
	free(ptr_displayer->sprites);
}

void	free_initial_data(t_init_data *init_data)
{
	int	i;

	if (!init_data)
		return ;
	i = 0;
	while (i < 4)
	{
		if (init_data->wall_textures_paths[i])
			free(init_data->wall_textures_paths[i]);
		i++;
	}
	free(init_data);
}

void	free_map_grid_mlx(t_map *map)
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
