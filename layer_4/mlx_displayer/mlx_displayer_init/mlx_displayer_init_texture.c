/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:03:49 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_init.h"

int		load_a_texture(t_mlx_displayer *displayer, char **filepath, int i);
void	displayer_dispatch_texture(t_mlx_displayer *displayer);
void	allocate_memory_for_texture(
			t_mlx_displayer *my_displayer, char **filepaths);

//! texture should be nulltermnated ! 
void	init_displayer_texture(
			t_mlx_displayer	*my_displayer, char **filepaths)
{
	int	i;

	allocate_memory_for_texture(my_displayer, filepaths);
	i = 0;
	while (i < my_displayer->nbr_textures)
	{
		if (load_a_texture(my_displayer, filepaths, i))
			printf("error texture\n");
		i++;
	}
	displayer_dispatch_texture(my_displayer);
}

void	allocate_memory_for_texture(
			t_mlx_displayer *my_displayer, char **filepaths)
{
	int	i;

	i = 0;
	while (filepaths[i])
		i++;
	my_displayer->nbr_textures = i;
	my_displayer->textures = malloc(sizeof(t_img) * my_displayer->nbr_textures);
}

int	load_a_texture(t_mlx_displayer *displayer, char **filepath, int i)
{
	if (!displayer || !filepath[i])
		return (-1);
	displayer->textures[i].img_ptr = mlx_xpm_file_to_image(
			displayer->mlx->mlx_ptr, filepath[i],
			&displayer->textures[i].width,
			&displayer->textures[i].height);
	if (!displayer->textures[i].img_ptr)
	{
		fprintf(stderr, "Failed to load texture image: %s\n", filepath[i]);
		return (-1);
	}
	displayer->textures[i].img_pixels_ptr = mlx_get_data_addr(
			displayer->textures[i].img_ptr,
			&displayer->textures[i].bits_per_pixel,
			&displayer->textures[i].line_len,
			&displayer->textures[i].endian);
	if (!displayer->textures[i].img_pixels_ptr)
	{
		mlx_destroy_image(displayer->mlx->mlx_ptr,
			displayer->textures[i].img_ptr);
		displayer->textures[i].img_ptr = NULL;
		return (-1);
	}
	printf("load texture success\n");
	return (0);
}

void	displayer_dispatch_texture(t_mlx_displayer *displayer)
{
	displayer->wall_textures[0] = &displayer->textures[0];
	displayer->wall_textures[1] = &displayer->textures[1];
	displayer->wall_textures[2] = &displayer->textures[2];
	displayer->wall_textures[3] = &displayer->textures[3];
}
