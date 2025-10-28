/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:13 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 16:37:20 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_H
# define INIT_DATA_H

typedef struct s_init_data
{
	char	*wall_textures_paths[4]; 
	char	***sprite_textures_paths_all;
	int		sky_color;
	int		ground_color;

	int		player_pos_x;
	int		player_pos_y;
	double	camera_direction;

	int		map_height;
	int		map_width;
	int		**grid;
}	t_init_data;

#endif