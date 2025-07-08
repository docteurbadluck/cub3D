/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 10:53:49 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"

int on_key_press(int keycode, void *param)
{
	t_mlx_data *my_mlx = param;
	
	if (keycode == XK_Left)
	{
		my_mlx->keys.left = 1;
	}
	else if (keycode == XK_Right)
	{
		my_mlx->keys.right = 1;
	}
	else if (keycode == XK_w)
	{
		my_mlx->keys.w = 1;
	}
	else if (keycode == XK_s)
	{
		my_mlx->keys.s = 1;
	}
	if (keycode == XK_Escape)
		close_clean(my_mlx);
	return 0;
}


int on_key_release(int keycode, void *param)
{
	t_mlx_data *my_mlx = param;

	if (keycode == XK_Left)
	{
		my_mlx->keys.left = 0;
	}
	else if (keycode == XK_Right)
	{
		my_mlx->keys.right = 0;
	}
	else if (keycode == XK_w)
	{
		my_mlx->keys.w = 0;
	}
	else if (keycode == XK_s)
	{
		my_mlx->keys.s = 0;
	}
	return 0;
}
