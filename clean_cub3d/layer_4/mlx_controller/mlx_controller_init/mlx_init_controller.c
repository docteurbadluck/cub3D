/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 14:16:37 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_controller.h"

void	link_interface_to_mlx_function(t_mlx_controller *controller);

//here we create link the context of the interface on t_mlx controller
// it allow us to keep the all the data from t_mlx_controler,
// even if we use a pointer from t_controler, cause we stored this pointer
// in this case it allow me to pass my mlx into the interface function.
// i can access this way to the pressed key.
// we also link the function from the interface to their implementation.
// we return a controller wich respect the interface.
t_i_controller	*create_controller(t_mlx_data *my_mlx)
{
	t_mlx_controller	*controller;

	controller = malloc(sizeof(t_mlx_controller));
	controller->mlx = my_mlx;
	controller->interface.context = controller;
	link_interface_to_mlx_function(controller);
	
	controller->keys.w = 0;
	controller->keys.s = 0;
	controller->keys.a = 0;
	controller->keys.d = 0;
	controller->keys.left = 0;
	controller->keys.right = 0;
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
}
