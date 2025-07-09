/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 16:04:18 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_controller.h"

int	mlx_is_move_forward(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = self;
	return (my_controler->keys.w);
}

int	mlx_is_move_backward(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = self;
	return (my_controler->keys.s);
}

int	mlx_is_move_left(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = self;
	return (my_controler->keys.a);
}

int	mlx_is_move_right(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = self;
	return (my_controler->keys.d);
}