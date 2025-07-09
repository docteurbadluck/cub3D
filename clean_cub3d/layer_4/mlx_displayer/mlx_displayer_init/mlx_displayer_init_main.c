/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 18:15:54 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "mlx_displayer_init.h"
#include "../mlx_displayer_function/mlx_displayer_function.h"

void	link_displayer_interface_to_mlx_function(t_mlx_displayer *displayer)
{
	displayer->interface.display = mlx_display_env;
	displayer->interface.display_minimap = mlx_display_minimap;
}

t_i_displayer	*create_displayer(t_mlx_data *mlx, char **texture_filepath, int sky_color, int ground_color)
{
	t_mlx_displayer *displayer = malloc(sizeof(t_mlx_displayer));
	if (!displayer)
		return NULL;
	displayer->mlx = mlx;
	link_displayer_interface_to_mlx_function(displayer);
	init_displayer_texture(displayer, texture_filepath);
	init_displayer_color(displayer, sky_color, ground_color);
	init_displayer_minimap(displayer);
	return (t_i_displayer *)displayer;
}


