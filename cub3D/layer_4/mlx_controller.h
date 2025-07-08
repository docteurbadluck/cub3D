/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controller.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:12:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:28:08 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "../layer_3/controller.h"

typedef struct s_mlx_controller
{
	t_controller	base;
	t_mlx_data		*mlx;
}	t_mlx_controller;

t_controller *create_controller(t_mlx_data *my_mlx);

t_controller init_controller(t_mlx_data *my_mlx);
