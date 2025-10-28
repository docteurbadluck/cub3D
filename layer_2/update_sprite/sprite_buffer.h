/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:27:50 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/27 13:46:54 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BUFFER_H
# define SPRITE_BUFFER_H
# define MAX_SPRITES 128

typedef struct s_sprite_view
{
	double	distance;
	int		screen_x;
	int		texture_index;
	int		type;
	double	vector_player_to_sprite_x;
	double	vector_player_to_sprite_y;
	double	transform_x;
	double	transform_y;
	int		sprite_size;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		texture_x;
	int		texture_y;
	int		tex_type;
}	t_sprite_view;

typedef struct s_spritebuffer
{
	t_sprite_view	sprites[MAX_SPRITES];
	int				count;
	double			player_fov;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
	double			inv_det;
	int				size_of_block;
}	t_spritebuffer;

#endif