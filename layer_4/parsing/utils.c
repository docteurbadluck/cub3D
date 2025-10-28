/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:17:04 by jholterh          #+#    #+#             */
/*   Updated: 2025/09/02 16:05:57 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	print_error(const char *error_msg, int return_code)
{
	printf(COLOR_RED "ERROR: %s\n" COLOR_RESET, error_msg);
	return (return_code);
}

// Frees everything in init_data at the very end
void	free_init_data(t_init_data *init_data)
{
	int	i;

	if (!init_data)
		return ;
	i = 0;
	while (i < 4)
	{
		if (init_data->wall_textures_paths[i])
			free(init_data->wall_textures_paths[i]);
		i++;
	}
	if (init_data->grid)
		free_int_grid(init_data->grid, init_data->map_height);
	free(init_data);
}
