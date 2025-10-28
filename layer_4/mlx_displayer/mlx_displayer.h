/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:06:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAYER_H
# define MLX_DISPLAYER_H

# include "interface_displayer.h"
# include "mlx_context.h"

typedef struct s_sprite_info
{
	t_img	*textures_sprite;
	int		nbr_texture;
	int		tick;
	int		current_texture;
	int		frame_by_texture;
}	t_sprite_info;

typedef struct s_mlx_displayer
{
	t_i_displayer	interface;
	t_mlx_data		*mlx;
	t_img			minimap_img;
	t_img			*textures;
	t_img			*wall_textures[4];
	t_sprite_info	*sprites;
	int				nbr_sprite;
	int				nbr_textures;
	int				sky_color;
	int				ground_color;
}	t_mlx_displayer;

//	***MLX_CREATE_DISPLAYER***
t_i_displayer	*create_displayer(t_mlx_data *mlx, t_init_data *data);

//	***MLX_DISPLAY_ENV***
void			mlx_display_env(const t_i_displayer *self,
					const t_framebuffer *frame_buff);

//	***MLX_SPRITE***
void			mlx_display_sprites(const t_i_displayer *self,
					t_spritebuffer *sprite_buff,
					const t_framebuffer *frame_buff);

//	***MLX_MINIMAP***
void			mlx_display_minimap(t_i_displayer *self,
					const t_map *map, const t_player *player);

#endif