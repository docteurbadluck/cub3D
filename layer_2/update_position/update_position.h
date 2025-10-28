/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 10:57:44 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_POSITION_H
# define UPDATE_POSITION_H

# include "player.h"
# include "map.h"
# include "interface_controller.h" 
# define ROTATION_SPEED_MOUSE 0.003

//	***UPDATE_POSITION***
void	update_position(t_player *player,
			const t_i_controller *input, const t_map *map);

//helpers
void	key_action(t_player *player,
			const t_i_controller *i_controller, const t_map *map);
void	mouse_action(t_player *player, const t_i_controller *i_controller);

#endif