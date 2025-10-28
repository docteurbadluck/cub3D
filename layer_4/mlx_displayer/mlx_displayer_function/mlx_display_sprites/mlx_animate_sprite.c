/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animate_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:43:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:02:11 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_function.h"

void	animate_sprite(t_sprite_view *sprite,
			t_mlx_displayer *mlx_displayer)
{
	update_texture_type(sprite);
	change_texture_sprite(sprite, mlx_displayer);
}

void	update_texture_type(t_sprite_view *sprite)
{
	if (sprite->type == 3)
		sprite->tex_type = 0;
	else if (sprite->type == 4)
		sprite->tex_type = 1;
	else if (sprite->type == 5)
		sprite->tex_type = 2;
}

void	change_texture_sprite(
			t_sprite_view *sprite, t_mlx_displayer *mlx_displayer)
{
	mlx_displayer->sprites[sprite->tex_type].tick++;
	if (mlx_displayer->sprites[sprite->tex_type].tick >= 
		mlx_displayer->sprites[sprite->tex_type].frame_by_texture)
	{
		mlx_displayer->sprites[sprite->tex_type].tick = 0;
		mlx_displayer->sprites[sprite->tex_type].current_texture++;
		if (mlx_displayer->sprites[sprite->tex_type].current_texture >= 
			mlx_displayer->sprites[sprite->tex_type].nbr_texture)
			mlx_displayer->sprites[sprite->tex_type].current_texture = 0;
	}
}
