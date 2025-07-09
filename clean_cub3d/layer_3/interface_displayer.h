/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_displayer.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:22:53 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 17:11:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_DISPLAYER_H
# define INTERFACE_DISPLAYER_H

# include "../layer_1/raycaster/raycaster.h"

typedef struct s_ray_hit
{
	double	distance;
	int		side;
	double	hit_x;
	double	hit_y;
	char	face;
}	t_ray_hit;

typedef struct s_framebuffer
{
	t_ray_hit	rays[NBR_RAY];
}	t_framebuffer;

typedef struct s_i_displayer
{
	void	(*display)(const struct s_displayer *self,
			const t_framebuffer *frame_buff);
	void	(*display_minimap)(const struct s_i_displayer *self,
			const t_map *map, const t_player *player);
}	t_i_displayer;

#endif