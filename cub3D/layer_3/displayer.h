/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:22:53 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 09:34:46 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYER_H
#define DISPLAYER_H

#include "../layer_1/raycaster.h"

/*
 1. What must the core logic communicate to the outside world?
In this case, the core wants to display something on screen. So ask yourself:

What is the minimal data the core needs to send to the display?

Answer: a framebuffer — an array of pixels, plus its dimensions.

*/

typedef struct s_ray_hit
{
	double	distance;
	int		side;
	double	hit_x;
	double	hit_y;
	char	face;
} t_ray_hit;

typedef struct s_framebuffer
{
	t_ray_hit	rays[NBR_RAY];
} t_framebuffer;


typedef struct s_displayer {
	void (*clear_screen)(const struct s_displayer *self);
	void (*display)(const struct s_displayer *self, const t_framebuffer *frame_buff);
	void (*display_minimap)(const struct s_displayer *self, const t_map *map, const t_player *player);
} t_displayer;


#endif