/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 18:14:18 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"

# define MINIMAP_WIDTH 150
# define MINIMAP_HEIGHT 150
# define CYAN        0x00FFFF
# define YELLOW      0xFFFF00

void	init_displayer_texture(t_mlx_displayer	*my_dipslayer,char **filepath);
void	init_displayer_color(t_mlx_displayer *my_displayer, int sky_color, int ground_color);
void	init_displayer_minimap(t_mlx_displayer *my_displayer);

