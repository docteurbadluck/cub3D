/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 10:11:52 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../layer_3/displayer.h"
#include "mlx_context.h"

# define MINIMAP_WIDTH 150
# define MINIMAP_HEIGHT 150
# define CYAN        0x00FFFF
# define YELLOW      0xFFFF00

typedef struct s_mlx_displayer
{
	t_displayer		base;
	t_mlx_data		*mlx;
	t_img			first_texture; // not usefull anymore
	t_img			minimap_img;
	t_img			*textures;
	int				nbr_textures;
	int				sky_color;
	int				ground_color;
}	t_mlx_displayer;


t_displayer	*create_displayer(t_mlx_data *mlx);
void		init_displayer_color(t_displayer *displayer, int sky_color, int ground_color);
void init_displayer_multiple_texture(t_displayer *displayer,char **filepath);
void mlx_display_minimap(const t_displayer *self, const t_map *map, const t_player *player);
