/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 08:04:05 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../layer_3/interface_displayer.h"
#include "mlx_context.h"

typedef struct s_mlx_displayer
{
	t_i_displayer		interface;
	t_mlx_data		*mlx;
	t_img			minimap_img;
	t_img			*textures;
	t_img			*wall_textures[4]; // 0N 1S 2W 3E
	int				nbr_textures;
	int				sky_color;
	int				ground_color;
}	t_mlx_displayer;


//	***mlx_displayer_init_main***
t_i_displayer	*create_displayer(t_mlx_data *mlx, char **texture_filepath, int sky_color, int ground_color);

//	***mlx_mininap***
void mlx_display_minimap(const t_i_displayer *self, const t_map *map, const t_player *player);

//	***mlx_display_env***
void mlx_display_env(const t_i_displayer *self, const t_framebuffer *frame_buff);
