/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vision.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:43:06 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/09 15:27:09 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_VISION_H
# define UPDATE_VISION_H

# include "../../layer_1/player/player.h"
# include "../../layer_1/map/map.h"
# include "../../layer_1/raycaster/raycaster.h"
# include "../../layer_3/interface_displayer.h"

void	update_vision(const t_player *player,
			const t_map *map, t_i_displayer *display);

#endif