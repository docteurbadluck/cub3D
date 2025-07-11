/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/11 14:08:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"

void init_mlx(t_mlx_data *my_mlx)
{
	my_mlx->mlx_ptr = mlx_init();
	if (!my_mlx->mlx_ptr)
		exit(1);

	my_mlx->win_ptr = mlx_new_window(my_mlx->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!my_mlx->win_ptr)
	{
		mlx_destroy_display(my_mlx->mlx_ptr);
		exit(1);
	}

	my_mlx->img.img_ptr = mlx_new_image(my_mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!my_mlx->img.img_ptr)
	{
		mlx_destroy_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
		mlx_destroy_display(my_mlx->mlx_ptr);
		exit(1);
	}

	// 💥 C’est ici que tu récupères le pointeur vers les pixels :
	my_mlx->img.img_pixels_ptr = mlx_get_data_addr(
		my_mlx->img.img_ptr,
		&my_mlx->img.bits_per_pixel,
		&my_mlx->img.line_len,
		&my_mlx->img.endian
	);
	if (!my_mlx->img.img_pixels_ptr)
	{
		mlx_destroy_image(my_mlx->mlx_ptr, my_mlx->img.img_ptr);
		mlx_destroy_window(my_mlx->mlx_ptr, my_mlx->win_ptr);
		mlx_destroy_display(my_mlx->mlx_ptr);
		exit(1);
	}
	my_mlx->keys.w = 0;
	my_mlx->keys.s = 0;
	my_mlx->keys.left = 0;
	my_mlx->keys.right = 0;
}