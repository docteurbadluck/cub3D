/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 17:40:06 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "interface_controller.h"
#include <stdio.h>

typedef struct s_key_state
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_key_state;

typedef struct s_mouse_state
{
	int		last_mouse_x;
	float	mouse_delta_x;
}	t_mouse_state;

typedef struct s_mlx_controller
{
	t_i_controller	interface;
	t_key_state		keys;
	t_mlx_data		*mlx;
	t_mouse_state	mouse;
}	t_mlx_controller;

//	***MLX_MOOVE***
int				mlx_is_move_forward(void *self);
int				mlx_is_move_backward(void *self);
int				mlx_is_move_left(void *self);
int				mlx_is_move_right(void *self);

//	***MLX_ROTATE***
int				mlx_is_turn_left(void *self);
int				mlx_is_turn_right(void *self);
float			mlx_get_mouse_delta_x(void *my_controller);

//	***MLX_INPUT***
int				on_key_press(int keycode, void *param);
int				on_key_release(int keycode, void *param);
int				mouse_move_handler(int x, int y, void *my_controller);

//	***MLX_INIT_CONTROLLER***
t_i_controller	*create_controller(t_mlx_data *my_mlx);