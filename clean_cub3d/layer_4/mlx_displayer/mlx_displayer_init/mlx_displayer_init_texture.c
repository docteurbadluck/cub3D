/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 08:21:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_init.h"

int		load_all_texture(t_mlx_displayer *displayer, char **filepath, int i);
void	dispatch_displayer_texture(t_mlx_displayer *displayer);

//!should be nulltermnated ! 
void	init_displayer_texture(t_mlx_displayer	*my_dipslayer, char **filepath)
{
	int	i;

	i = 0;
	while (filepath[i])
		i++;
	my_dipslayer->nbr_textures = i;
	my_dipslayer->textures = malloc(sizeof(t_img) * my_dipslayer->nbr_textures);
	i = 0;
	while (i < my_dipslayer->nbr_textures)
	{
		if (load_all_texture(my_dipslayer, filepath, i))
			printf("error texture\n");
		i++;
	}
	dispatch_displayer_texture(my_dipslayer);
}

int	load_all_texture(t_mlx_displayer *displayer, char **filepath, int i)
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

void	dispatch_displayer_texture(t_mlx_displayer *displayer)
{
	displayer->wall_textures[0] = &displayer->textures[0];
	displayer->wall_textures[1] = &displayer->textures[1];
	displayer->wall_textures[2] = &displayer->textures[2];
	displayer->wall_textures[3] = &displayer->textures[3];
}
