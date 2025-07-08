/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:05:11 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_VISION_H
#define UPDATE_VISION_H

#include "../layer_1/player.h"
#include "../layer_1/map.h"
#include "../layer_1/raycaster.h"
#include "../layer_3/displayer.h"


void update_vision(const t_player *player, const t_map *map, const t_displayer *display);

#endif