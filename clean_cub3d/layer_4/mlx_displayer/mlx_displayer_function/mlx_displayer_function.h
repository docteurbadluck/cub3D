/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_function.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:04:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 18:09:05 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"

void mlx_display_minimap(const t_i_displayer *self, const t_map *map, const t_player *player);
void mlx_display_env(const t_i_displayer *self, const t_framebuffer *frame_buff);
