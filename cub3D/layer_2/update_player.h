/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/07 14:22:23 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MOVE_PLAYER_H
#define MOVE_PLAYER_H

#include "../layer_1/player.h"
#include "../layer_1/map.h"

#include "../layer_3/controller.h" 
//the idea here is to only have a dependency on the 3 layer and not on the fourth layer
// cause the 3rd layer is an interface layer 

void update_player(t_player *player, const t_controller *input, const t_map *map);




#endif