
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 17:13:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	char *dst = img->img_pixels_ptr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	background_render(int color_sky, int color_ground, t_mlx_data *my_mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y, &my_mlx->img, color_sky);
			x++;
		}
		y++;
	}
	while (y < HEIGHT )
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y,  &my_mlx->img, color_ground);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
		my_mlx->img.img_ptr, 0, 0);
}