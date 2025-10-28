/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:03:04 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:10:44 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "mlx_controller.h"

int	mouse_move_handler(int x, int y, void *my_controller)
{
	t_mlx_controller	*mlx_controller;
	int					center_x;
	int					center_y;

	(void)y;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	mlx_controller = my_controller;
	mlx_controller->mouse.mouse_delta_x = 
		x - mlx_controller->mouse.last_mouse_x;
	mlx_controller->mouse.last_mouse_x = x;
	mlx_mouse_move(mlx_controller->mlx->mlx_ptr,
		mlx_controller->mlx->win_ptr, center_x, center_y);
	return (0);
}
