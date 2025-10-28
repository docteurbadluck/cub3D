/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_displayer.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:22:53 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 16:25:26 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_DISPLAYER_H
# define INTERFACE_DISPLAYER_H

# include "raycaster.h"
# include "frame_buffer.h"
# include "sprite_buffer.h"

typedef struct s_i_displayer
{
	void	(*display_wall)(const struct s_i_displayer *self,
			const t_framebuffer *frame_buff);
	void	(*display_minimap)(struct s_i_displayer *self,
			const t_map *map, const t_player *player);
	void	(*display_sprites)(const struct s_i_displayer *self,
			t_spritebuffer *sprite_buff, const t_framebuffer *frame_buff);
}	t_i_displayer;

#endif