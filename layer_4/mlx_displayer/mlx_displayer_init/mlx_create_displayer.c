/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_displayer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 16:25:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"
#include "mlx_displayer_init.h"
#include "../mlx_displayer_function/mlx_displayer_function.h"

void	link_displayer_interface_to_mlx_function(t_mlx_displayer *displayer);

t_i_displayer	*create_displayer(t_mlx_data *mlx, t_init_data *init)
{
	t_mlx_displayer	*displayer;

	displayer = malloc(sizeof(t_mlx_displayer));
	if (!displayer)
		return (NULL);
	displayer->mlx = mlx;
	link_displayer_interface_to_mlx_function(displayer);
	init_displayer_texture(displayer, init->wall_textures_paths);
	displayer_init_sprites(displayer, init->sprite_textures_paths_all);
	init_displayer_color(displayer, init->sky_color, init->ground_color);
	init_displayer_minimap(displayer);
	return ((t_i_displayer *)displayer);
}

void	link_displayer_interface_to_mlx_function(t_mlx_displayer *displayer)
{
	displayer->interface.display_wall = mlx_display_env;
	displayer->interface.display_minimap = mlx_display_minimap;
	displayer->interface.display_sprites = mlx_display_sprites;
}
