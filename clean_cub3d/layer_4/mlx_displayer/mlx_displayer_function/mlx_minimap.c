/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 17:41:31 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"


void mlx_display_minimap(const t_i_displayer *self, const t_map *map, const t_player *player)
{
	t_mlx_displayer *disp = (t_mlx_displayer *)self;
	int tile_size = 10; // pixels per tile

	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			int color = (map->grid[y][x] != 0) ? 0xFFFFFF : 0x000000;

			for (int dy = 0; dy < tile_size; dy++)
			{
				for (int dx = 0; dx < tile_size; dx++)
				{
					my_pixel_put(x * tile_size + dx, y * tile_size + dy, &disp->minimap_img, color);
				}
			}
		}
	}
	// Draw player on top (as a red square)
	int px = player->pos_x / map->size_of_block * tile_size;
	int py = player->pos_y / map->size_of_block * tile_size;
	for (int dy = -2; dy <= 2; dy++)
		for (int dx = -2; dx <= 2; dx++)
			my_pixel_put(px + dx, py + dy, &disp->minimap_img, 0xFF0000);
	// Draw the minimap image to the screen at top-left corner
	mlx_put_image_to_window(disp->mlx->mlx_ptr, disp->mlx->win_ptr, disp->minimap_img.img_ptr, 0, 0);
}