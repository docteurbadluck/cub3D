/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_init_sprites.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:04:14 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:04:25 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_displayer.h"
#include "mlx_displayer_init.h"

void	displayer_init_sprites(t_mlx_displayer	*my_displayer,
			char ***all_filepaths)
{
	int	sprite_index;

	if (!all_filepaths)
	{
		my_displayer->nbr_sprite = 0;
		my_displayer->sprites = NULL;
		return ;
	}
	displayer_allocate_sprites_memory(my_displayer, all_filepaths);
	sprite_index = 0;
	while (sprite_index < my_displayer->nbr_sprite)
	{
		displayer_init_sprite_data(my_displayer, all_filepaths, sprite_index);
		sprite_index++;
	}
}

void	displayer_allocate_sprites_memory(t_mlx_displayer	*my_displayer,
			char ***all_filepaths)
{
	my_displayer->nbr_sprite = count_sprites(all_filepaths);
	my_displayer->sprites = 
		malloc(sizeof(t_sprite_info) * my_displayer->nbr_sprite);
}

int	count_sprites(char ***all_philepaths)
{
	int	i;

	i = 0;
	while (all_philepaths[i])
		i++;
	return (i);
}

void	displayer_init_sprite_data(t_mlx_displayer	*my_displayer,
			char ***filepath, int y)
{
	int	i;

	i = 0;
	my_displayer->sprites[y].current_texture = 0;
	my_displayer->sprites[y].frame_by_texture = 25;
	my_displayer->sprites[y].tick = 0;
	while (filepath[y][i])
		i++;
	my_displayer->sprites[y].nbr_texture = i;
	my_displayer->sprites[y].textures_sprite = 
		malloc(sizeof(t_img) * my_displayer->sprites[y].nbr_texture);
	i = 0;
	while (i < my_displayer->sprites[y].nbr_texture)
	{
		if (load_sprite_texture(my_displayer, filepath[y], y, i))
			printf("error texture\n");
		i++;
	}
}

int	load_sprite_texture(t_mlx_displayer *displayer,
		char **filepath, int y, int i)
{
	if (!displayer || !filepath[i])
		return (-1);
	displayer->sprites[y].textures_sprite[i].img_ptr = mlx_xpm_file_to_image(
			displayer->mlx->mlx_ptr, filepath[i],
			&displayer->sprites[y].textures_sprite[i].width,
			&displayer->sprites[y].textures_sprite[i].height);
	if (!displayer->sprites[y].textures_sprite[i].img_ptr)
	{
		fprintf(stderr, "Failed to load texture image: %s\n", filepath[i]);
		return (-1);
	}
	displayer->sprites[y].textures_sprite[i].img_pixels_ptr = mlx_get_data_addr(
			displayer->sprites[y].textures_sprite[i].img_ptr,
			&displayer->sprites[y].textures_sprite[i].bits_per_pixel,
			&displayer->sprites[y].textures_sprite[i].line_len,
			&displayer->sprites[y].textures_sprite[i].endian);
	if (!displayer->sprites[y].textures_sprite[i].img_pixels_ptr)
	{
		mlx_destroy_image(displayer->mlx->mlx_ptr,
			displayer->sprites[y].textures_sprite[i].img_ptr);
		displayer->sprites[y].textures_sprite[i].img_ptr = NULL;
		return (-1);
	}
	printf("load texture success\n");
	return (0);
}
