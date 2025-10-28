/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:06:55 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:07:08 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_controller.h"

void	link_interface_to_mlx_function(t_mlx_controller *controller);
void	init_controller_value(t_mlx_controller *controller);

t_i_controller	*create_controller(t_mlx_data *my_mlx)
{
	t_mlx_controller	*controller;

	controller = malloc(sizeof(t_mlx_controller));
	controller->mlx = my_mlx;
	controller->interface.context = controller;
	link_interface_to_mlx_function(controller);
	init_controller_value(controller);
	return ((t_i_controller *)controller);
}

void	link_interface_to_mlx_function(t_mlx_controller *controller)
{
	controller->interface.is_move_forward_pressed = mlx_is_move_forward;
	controller->interface.is_move_backward_pressed = mlx_is_move_backward;
	controller->interface.is_move_left_pressed = mlx_is_move_left;
	controller->interface.is_move_right_pressed = mlx_is_move_right;
	controller->interface.is_turn_left_pressed = mlx_is_turn_left;
	controller->interface.is_turn_right_pressed = mlx_is_turn_right;
	controller->interface.get_mouse_delta_x = mlx_get_mouse_delta_x;
}

void	init_controller_value(t_mlx_controller *controller)
{
	controller->keys.w = 0;
	controller->keys.s = 0;
	controller->keys.a = 0;
	controller->keys.d = 0;
	controller->keys.left = 0;
	controller->keys.right = 0;
	controller->mouse.last_mouse_x = 0;
	controller->mouse.mouse_delta_x = 0;
}
