/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:56:15 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_VISION_H
# define UPDATE_VISION_H
# include "player.h"
# include "map.h"
# include "raycaster.h"
# include "interface_displayer.h"
# include "sprite.h"

//	***UPDATE_VISION***
void	update_vision(const t_player *player,
			const t_map *map, t_i_displayer *displayer, t_sprite *sprites);

//helper
void	framebuffer_init_face(int i,
			t_raycast *raycast, t_framebuffer *frame_buffer);
void	transform_raycast_into_framebuffer(t_raycast *raycast,
			t_framebuffer *frame_buffer);
void	update_raycast(const t_player *player, const t_map *map,
			t_raycast **raycast, t_framebuffer *frame_buffer);

#endif