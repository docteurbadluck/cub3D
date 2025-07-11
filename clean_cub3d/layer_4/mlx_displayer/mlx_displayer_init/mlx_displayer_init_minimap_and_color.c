/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init_minimap_and_color.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/11 11:19:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "mlx_displayer_init.h"

void	init_displayer_color(t_mlx_displayer *my_displayer,
			int sky_color, int ground_color)
{
	my_displayer->sky_color = sky_color;
	my_displayer->ground_color = ground_color;
}

void	init_displayer_minimap(t_mlx_displayer *my_displayer)
{
	my_displayer->minimap_img.img_ptr = 
		mlx_new_image(my_displayer->mlx->mlx_ptr,
			MINIMAP_WIDTH, MINIMAP_HEIGHT);
	my_displayer->minimap_img.height = MINIMAP_HEIGHT;
	my_displayer->minimap_img.width = MINIMAP_WIDTH;
	my_displayer->minimap_img.img_pixels_ptr = mlx_get_data_addr(
			my_displayer->minimap_img.img_ptr,
			&my_displayer->minimap_img.bits_per_pixel,
			&my_displayer->minimap_img.line_len,
			&my_displayer->minimap_img.endian);
}
