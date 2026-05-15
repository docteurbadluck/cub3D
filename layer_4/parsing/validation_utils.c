/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:01:07 by jholterh          #+#    #+#             */
/*   Updated: 2025/09/02 16:34:29 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Validates that all sprite texture files exist and are readable
static int	check_sprite_texture_paths(char ***paths)
{
	int	i;
	int	j;

	i = 0;
	while (paths[i])
	{
		j = 0;
		while (paths[i][j])
		{
			if (access(paths[i][j], F_OK) == -1)
				return (print_error("Sprite texture file does not exist.", 1));
			if (access(paths[i][j], R_OK) == -1)
				return (print_error("Sprite texture file is not readable.", 1));
			j++;
		}
		i++;
	}
	return (0);
}

// Builds init_data->sprite_textures_paths_all from parsing_help->sprite_paths.
// Transfers ownership: parsing_help->sprite_paths[i] become NULL after transfer.
int	build_sprite_paths(t_init_data *init_data, t_parsing_help *parsing_help)
{
	int		count;
	int		i;

	count = 0;
	while (count < 3 && parsing_help->sprite_paths[count])
		count++;
	if (count == 0)
		return (0);
	init_data->sprite_textures_paths_all = malloc(sizeof(char **) * (count + 1));
	if (!init_data->sprite_textures_paths_all)
		return (print_error("Memory error for sprite paths", 1));
	i = 0;
	while (i < count)
	{
		init_data->sprite_textures_paths_all[i] = parsing_help->sprite_paths[i];
		parsing_help->sprite_paths[i] = NULL;
		i++;
	}
	init_data->sprite_textures_paths_all[count] = NULL;
	return (check_sprite_texture_paths(init_data->sprite_textures_paths_all));
}

// Checks if the texture files exist and are readable
int	check_texture_paths(char **textures_paths)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (access(textures_paths[i], F_OK) == -1)
			return (print_error("Texture file does not exist.", 1));
		if (access(textures_paths[i], R_OK) == -1)
			return (print_error("Texture file is not readable.", 1));
	}
	return (0);
}

// Pads all map rows to ensure they have the same width
void	pad_map_rows(char **char_grid, int map_height, int map_width)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		pad_row_if_needed(&char_grid[i], map_width);
		i++;
	}
}

// Validates and extracts ground and sky colors from parsing_help
static int	validate_colors(t_parsing_help *parsing_help)
{
	if (extract_colors(parsing_help->ground_color_str,
			parsing_help->ground_color)
		|| extract_colors(parsing_help->sky_color_str,
			parsing_help->sky_color))
		return (1);
	return (0);
}

// Allocates and initializes the map grid, pads map rows as needed
static int	validate_and_init_grid(t_init_data *init_data,
		t_parsing_help *parsing_help)
{
	init_data->grid = allocate_int_grid(init_data->map_height,
			init_data->map_width);
	if (!init_data->grid)
		return (print_error("Grid allocation failed", 1));
	pad_map_rows(parsing_help->grid, init_data->map_height,
		init_data->map_width);
	return (0);
}

// Validates textures, colors, initializes grid, and checks map validity
int	validate_textures_parse(t_init_data *init_data,
		t_parsing_help *parsing_help)
{
	if (get_textures(init_data, parsing_help))
		return (1);
	if (check_texture_paths(init_data->wall_textures_paths))
		return (1);
	if (validate_colors(parsing_help))
		return (1);
	put_colors_in_int(parsing_help->ground_color, &init_data->ground_color);
	put_colors_in_int(parsing_help->sky_color, &init_data->sky_color);
	if (validate_and_init_grid(init_data, parsing_help))
		return (1);
	if (create_map(parsing_help->grid, init_data->grid, init_data))
		return (1);
	if (flood_it_all(init_data->grid, init_data->map_height,
			init_data->map_width))
		return (1);
	if (build_sprite_paths(init_data, parsing_help))
		return (1);
	return (0);
}
