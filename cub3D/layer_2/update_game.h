/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:43:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:27:15 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_vision.h"
#include "update_player.h"


void	update_game(t_player *player, const t_map *map,
	const t_displayer *display, t_controller *controller);
