/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 15:35:01 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_main/mlx_context.h"
#include "../../layer_3/interface_controller.h"

typedef struct s_key_state {
	int	w;
	int	s;
	int a;
	int d;
	int	left;
	int right;
}	t_key_state;

typedef struct s_mlx_controller
{
	t_i_controller	interface;
	t_key_state		keys;
	t_mlx_data		*mlx;
}	t_mlx_controller;

//	***mlx_move***
int				mlx_is_move_forward(void *self);
int				mlx_is_move_backward(void *self);
int				mlx_is_move_left(void *self);
int				mlx_is_move_right(void *self);

//	***mlx_rotate***
int				mlx_is_turn_left(void *self);
int				mlx_is_turn_right(void *self);

//	***mlx_init_controller***
t_i_controller	*create_controller(t_mlx_data *my_mlx);