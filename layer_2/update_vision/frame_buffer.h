/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:17:11 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:56:23 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_BUFFER_H
# define FRAME_BUFFER_H
# include "raycaster.h"

typedef struct s_ray_hit
{
	double	distance;
	int		side;
	double	hit_x;
	double	hit_y;
	char	face;
	double	dir_x;
	double	dir_y;
	double	distance_brut;
}	t_ray_hit;

typedef struct s_framebuffer
{
	t_ray_hit	rays[NBR_RAY];
}	t_framebuffer;

#endif