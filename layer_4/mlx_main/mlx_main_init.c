/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:08:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include <stdio.h>

//init the mlx (screen image, window...)
void	init_mlx(t_mlx_data *my_mlx)
{
	my_mlx->mlx_ptr = mlx_init();
	if (!my_mlx->mlx_ptr)
	{
		printf("fail mlx_ptr\n");
		exit(1);
	}
	my_mlx->win_ptr = mlx_new_window(my_mlx->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!my_mlx->win_ptr)
	{
		mlx_destroy_display(my_mlx->mlx_ptr);
		printf("fail window\n");
		exit(1);
	}
	my_mlx->img.img_ptr = mlx_new_image(my_mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!my_mlx->img.img_ptr)
	{
		mlx_destroy_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
		mlx_destroy_display(my_mlx->mlx_ptr);
		printf("fail image\n");
		exit(1);
	}
	init_mlx_pixel_ptr(my_mlx);
}

void	init_mlx_pixel_ptr(t_mlx_data *my_mlx)
{
	my_mlx->img.img_pixels_ptr = mlx_get_data_addr(
			my_mlx->img.img_ptr,
			&my_mlx->img.bits_per_pixel,
			&my_mlx->img.line_len,
			&my_mlx->img.endian);
	if (!my_mlx->img.img_pixels_ptr)
	{
		mlx_destroy_image(my_mlx->mlx_ptr, my_mlx->img.img_ptr);
		mlx_destroy_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
		mlx_destroy_display(my_mlx->mlx_ptr);
		exit(1);
	}
}
