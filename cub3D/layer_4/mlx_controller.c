/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 11:23:12 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_controller.h"


int mlx_is_move_forward(void *self)
{
	t_mlx_controller	*my_controler = self;
	return my_controler->mlx->keys.w;
}

int mlx_is_move_backward(void *self)
{
	t_mlx_controller	*my_controler = self;
	return my_controler->mlx->keys.s;
}

int	mlx_is_turn_left(void *self)
{
	t_mlx_controller	*my_controler = self;
	return my_controler->mlx->keys.left;
}

int	mlx_is_turn_right(void *self)
{
	t_mlx_controller *my_controler = self;
	return my_controler->mlx->keys.right;
}


t_controller *create_controller(t_mlx_data *my_mlx)
{
	t_mlx_controller	*controller = malloc(sizeof(t_mlx_controller));
	controller->mlx = my_mlx;
	
	controller->base.context = controller;
	controller->base.is_move_forward_pressed = mlx_is_move_forward;
	controller->base.is_move_backward_pressed = mlx_is_move_backward;
	controller->base.is_turn_left_pressed = mlx_is_turn_left;
	controller->base.is_turn_right_pressed = mlx_is_turn_right;
		// Set keys to zero if not already done in `mlx_init`
	my_mlx->keys.left = 0;
	my_mlx->keys.right = 0;
	my_mlx->keys.w = 0;
	my_mlx->keys.s = 0;

	
	return (t_controller *)controller;
}