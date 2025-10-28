/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 16:07:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "mlx_controller.h"

void	on_moove_key_press(int keycode, t_mlx_controller *controller_ctx);
void	on_rotate_key_press(int keycode, t_mlx_controller *controller_ctx);

int	on_key_press(int keycode, void *param)
{
	t_mlx_game			*mlx_game_ctx;
	t_mlx_controller	*controller_ctx;

	mlx_game_ctx = (t_mlx_game *)param;
	controller_ctx = 
		(t_mlx_controller *)mlx_game_ctx->game_context->controller->context;
	on_moove_key_press(keycode, controller_ctx);
	on_rotate_key_press(keycode, controller_ctx);
	if (keycode == XK_Escape)
		close_clean(mlx_game_ctx);
	return (0);
}

void	on_moove_key_press(int keycode, t_mlx_controller *controller_ctx)
{
	if (keycode == XK_w)
	{
		controller_ctx->keys.w = 1;
	}
	else if (keycode == XK_s)
	{
		controller_ctx->keys.s = 1;
	}
	else if (keycode == XK_a)
	{
		controller_ctx->keys.a = 1;
	}
	else if (keycode == XK_d)
	{
		controller_ctx->keys.d = 1;
	}
}

void	on_rotate_key_press(int keycode, t_mlx_controller *controller_ctx)
{
	if (keycode == XK_Left)
	{
		controller_ctx->keys.left = 1;
	}
	else if (keycode == XK_Right)
	{
		controller_ctx->keys.right = 1;
	}
}
