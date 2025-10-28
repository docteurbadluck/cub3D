/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/25 15:49:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAYER_INIT_H
# define MLX_DISPLAYER_INIT_H
# include "../mlx_displayer.h"

# define MINIMAP_WIDTH	200
# define MINIMAP_HEIGHT	200

//public
void	init_displayer_color(t_mlx_displayer *my_displayer,
			int sky_color, int ground_color);
void	init_displayer_minimap(t_mlx_displayer *my_displayer);
void	displayer_init_sprites(t_mlx_displayer	*my_displayer,
			char ***all_filepaths);
void	init_displayer_texture(t_mlx_displayer	*my_displayer,
			char **filepath);

//helpers
void	displayer_allocate_sprites_memory(t_mlx_displayer	*my_displayer,
			char ***all_filepaths);
int		count_sprites(char ***all_philepaths);
void	displayer_init_sprite_data(t_mlx_displayer	*my_displayer,
			char ***filepath, int y);
int		load_sprite_texture(t_mlx_displayer *displayer,
			char **filepath, int y, int i);

#endif