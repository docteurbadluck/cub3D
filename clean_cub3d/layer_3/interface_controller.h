/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_controller.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:28:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 15:25:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_CONTROLLER_H
# define INTERFACE_CONTROLLER_H

// Abstracts user input handling behind an interface.
// This allows the logic layer to remain independent
// of system-specific implementations (e.g., which input library is used),
// supporting clean architecture and testability.
typedef struct s_i_controller
{
	void	*context;
	int		(*is_move_forward_pressed)(void *ctx);
	int		(*is_move_backward_pressed)(void *ctx);
	int		(*is_move_left_pressed)(void *ctx);
	int		(*is_move_right_pressed)(void *ctx);
	int		(*is_turn_left_pressed)(void *ctx);
	int		(*is_turn_right_pressed)(void *ctx);
}	t_i_controller;

#endif