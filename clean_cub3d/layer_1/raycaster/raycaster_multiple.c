/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_multiple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:54:59 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 12:57:40 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

t_raycast	*raycasting_multiple(const t_player *player, const t_map *map)
{
	t_raycast			*rays;
	t_multiple_raycast	caster;
	int					i;

	i = 0;
	rays = malloc(sizeof(t_raycast) * NBR_RAY);:
	if (!rays)
		return (NULL);
	caster.angle_step = player->fov / NBR_RAY;
	while (i < NBR_RAY)
	{
		caster.angle_offset = (i - (NBR_RAY / 2.0)) * caster.angle_step;
		caster.angle_current = 
			normalize_angle(player->camera_direction + caster.angle_offset);
		rays[i] = raycasting(player, map, caster.angle_current);
		caster.angle_diff = 
			normalize_angle(caster.angle_current - player->camera_direction);
		rays[i].distance *= cos(caster.angle_diff);
		i++;
	}
	return (rays);
}
