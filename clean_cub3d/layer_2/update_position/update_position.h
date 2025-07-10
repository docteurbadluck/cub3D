/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 13:24:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_POSITION_H
# define UPDATE_POSITION_H

# include "player.h"
# include "map.h"
# include "interface_controller.h" 

// The idea here is to connect the use case to entyties in a side,
// and on the other side, connect to an interface.
// this process allow to separate the logic, from the implementation.
void	update_position(t_player *player,
			const t_i_controller *input, const t_map *map);

#endif