/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:34:40 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/15 11:43:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "sprite.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_mlx_game	game;
	t_init_data	*init_data;

	init_data = NULL;
	game.init_data = &init_data;
	if (parsing(argc, argv, &init_data))
		return (1);
	init_data->sprite_textures_paths_all = NULL;
	start_game(&game, init_data);
	return (0);
}
