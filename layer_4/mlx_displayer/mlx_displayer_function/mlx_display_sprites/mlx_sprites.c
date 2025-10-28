/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:43:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:11:47 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_function.h"

void	mlx_display_sprites(const t_i_displayer *self,
			t_spritebuffer *sprite_buff, const t_framebuffer *frame_buff)
{
	t_sprite_view	*sprite;
	int				i;

	i = 0;
	if (sprite_buff->count == 0)
		return ;
	sort_sprite_by_distance(sprite_buff);
	while (i < sprite_buff->count)
	{
		sprite = &sprite_buff->sprites[i];
		if (transform_world_pos_to_camera_space(sprite_buff, sprite))
			continue ;
		set_position_and_size_on_screen(sprite);
		set_draw_boundaries(sprite);
		draw_sprite(sprite_buff, sprite, self, frame_buff);
		i++;
	}
}

void	sort_sprite_by_distance(t_spritebuffer *s_buff)
{
	int				i;
	int				j;
	t_sprite_view	tmp;

	i = 0;
	while (i < s_buff->count -1)
	{
		j = i + 1;
		while (j < s_buff->count)
		{
			if (s_buff->sprites[i].distance < s_buff->sprites[j].distance)
			{
				tmp = s_buff->sprites[i];
				s_buff->sprites[i] = s_buff->sprites[j];
				s_buff->sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
