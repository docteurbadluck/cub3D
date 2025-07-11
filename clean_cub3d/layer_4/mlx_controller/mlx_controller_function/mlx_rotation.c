/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 15:30:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_controller.h"

int	mlx_is_turn_left(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = (t_mlx_controller *)self;
	return (my_controler->keys.left);
}

int	mlx_is_turn_right(void *self)
{
	t_mlx_controller	*my_controler;

	my_controler = (t_mlx_controller *)self;;
	return (my_controler->keys.right);
}
