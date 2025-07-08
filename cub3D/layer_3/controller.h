/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:28:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:57:52 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef struct s_controller
{
	void *context;
	int	(*is_move_forward_pressed)(void *ctx);
	int	(*is_turn_left_pressed)(void *ctx);
	int	(*is_turn_right_pressed)(void *ctx);
	int	(*is_move_backward_pressed)(void *ctx);
}	t_controller;

#endif