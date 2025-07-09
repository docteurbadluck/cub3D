/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 15:27:02 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_POSITION_H
# define UPDATE_POSITION_H

# include "../../layer_1/player/player.h"
# include "../../layer_1/map/map.h"
# include "../../layer_3/interface_controller.h" 

// The idea here is to connect the use case to entyties in a side,
// and on the other side, connect to an interface.
// this process allow to separate the logic, from the implementation.
void	update_position(t_player *player,
			const t_i_controller *input, const t_map *map);

#endif