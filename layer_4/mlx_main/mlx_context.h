/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_context.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 17:13:04 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONTEXT_H
# define MLX_CONTEXT_H
# include "mlx.h"
# include "game.h"
# include "init_data.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdlib.h>
# define HEIGHT 800
# define WIDTH 800
# define SIZE_OF_BLOCK 10

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx_data;

typedef struct s_mlx_game
{
	t_mlx_data		*my_mlx;
	t_game_context	*game_context;
	t_init_data		**init_data;
}	t_mlx_game;

typedef struct s_mlx_controller	t_mlx_controller;
typedef struct s_mlx_displayer	t_mlx_displayer;
typedef struct s_init_data		t_init_data;
typedef struct s_map			t_map;

//	***MLX_CLOSE***
int		close_window(t_mlx_game *screen);
void	close_clean(t_mlx_game *GAME);

//	***MLX_MAIN_INIT***
void	init_mlx(t_mlx_data *my_mlx);

//helper
void	free_displayer(t_mlx_game *GAME);
void	free_game_context(t_mlx_game *GAME);
void	free_mlx(t_mlx_game *GAME);
void	init_mlx_pixel_ptr(t_mlx_data *my_mlx);
void	destroy_texture(t_mlx_displayer *ptr_displayer);
void	destroy_sprite(t_mlx_displayer *ptr_displayer);
void	free_initial_data(t_init_data *init_data);
void	free_map_grid_mlx(t_map *map);

#endif