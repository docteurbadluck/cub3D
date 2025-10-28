/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:49:55 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:51:08 by tdeliot          ###   ########.fr       */
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

//	***RAYCASTER_INIT***
void		raycast_init(const t_player *player,
				const t_map *map, t_raycast *r, double angle);

//	***RAYCASTER***
t_raycast	raycasting(const t_player *player, const t_map *map, double angle);

//	***RAYCASTER_PLAYER_VIEW***
t_raycast	*raycasting_player_view(const t_player *player, const t_map *map);

//helper
void		raycasting_send_a_ray(t_raycast *r, const t_map *map);
void		raycasting_find_distance_and_hit_point(
				t_raycast *r, int size_of_block);
void		raycast_init_pos_and_direction_in_radian(t_raycast *r, double pos_x,
				double pos_y, double direction);
void		raycast_init_vector_and_grid_pos(t_raycast *r, int size_of_block);
void		raycast_init_delta(t_raycast *r, int size_of_block);
void		raycast_init_step_direction_and_side_dist(t_raycast *r,
				int size_block);
void		modify_raycasting_angle(t_multiple_raycast *caster,
				const t_player *player, int i);
void		correct_fisheye(t_multiple_raycast *caster, const t_player *player,
				int i, t_raycast *rays);
void		step_in_x_direction(t_raycast *r);
void		step_in_y_direction(t_raycast *r);

#endif
