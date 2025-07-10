/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_function.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:04:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 08:02:07 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"

//	***mlx_mininap***
void mlx_display_minimap(const t_i_displayer *self, const t_map *map, const t_player *player);

//	***mlx_display_env***
void mlx_display_env(const t_i_displayer *self, const t_framebuffer *frame_buff);

//	***mlx_displayer_tool***
void	my_pixel_put(int x, int y, t_img *img, int color);
void	background_render(int color_sky, int color_ground, t_mlx_data *my_mlx);
