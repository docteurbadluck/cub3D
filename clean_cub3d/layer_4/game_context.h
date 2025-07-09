/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_context.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:38:03 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 15:52:57 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include "../layer_2/update_vision/update_vision.h"
#include "../layer_2/update_position/update_position.h"
#include "mlx_controller/mlx_controller.h"
//#include "layer_4/mlx_displayer.h"


typedef struct s_game_context
{
	t_player		player;
	t_map			*map;
	t_i_controller	*controller;
//	t_displayer		*displayer;
} t_game_context;

#endif