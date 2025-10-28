/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:54:24 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 13:48:56 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_SPRITE_H
# define UPDATE_SPRITE_H
# include "sprite.h"
# include "sprite_buffer.h"

//	***UPDATE_SPRITE***
void	update_sprite(t_sprite *sprites, const t_player *player,
			const t_map *map, t_spritebuffer *buffer);

//helper
void	update_spriteview_data(t_sprite *sprites,
			const t_player *player, const t_map *map, t_spritebuffer *buffer);
void	copy_data_from_sprite(t_sprite_view *view, t_sprite *sprites, int i);
void	update_spritebuffer_info(t_sprite *sprites,
			const t_player *player, t_spritebuffer *buffer);
void	update_world_to_camera_space_data(t_sprite *sprites,
			const t_player *player, t_spritebuffer *buffer);
#endif