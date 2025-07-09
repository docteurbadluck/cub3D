/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:49:55 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 12:52:07 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
# include "player.h"
# include "map.h"
# define NBR_RAY 800

typedef struct s_raycast
{
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	direction;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		case_x;
	int		case_y;
	int		step_x;
	int		step_y;
	int		side;
	double	distance;
	double	hit_x;
	double	hit_y;
}	t_raycast;

typedef struct s_multiple_raycast
{
	double		angle_step;
	double		angle_offset;
	double		angle_current;
	double		angle_diff;
	double		ray_angle;

}	t_multiple_raycast;

void		raycast_init(const t_player *player,
				const t_map *map, t_raycast *r, double angle);
t_raycast	raycasting(const t_player *player, const t_map *map, double angle);
t_raycast	*raycasting_multiple(const t_player *player, const t_map *map);

#endif
