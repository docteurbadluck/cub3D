/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 11:43:07 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAYER_INIT_H
# define MLX_DISPLAYER_INIT_H
# include "../mlx_displayer.h"

# define MINIMAP_WIDTH	150
# define MINIMAP_HEIGHT	150

void	init_displayer_texture(t_mlx_displayer	*my_dipslayer, char **filepath);
void	init_displayer_color(t_mlx_displayer *my_displayer,
			int sky_color, int ground_color);
void	init_displayer_minimap(t_mlx_displayer *my_displayer);

#endif