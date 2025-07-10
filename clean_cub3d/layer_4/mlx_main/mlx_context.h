/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_context.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/10 14:44:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONTEXT_H
#define MLX_CONTEXT_H

#include "mlx.h"
#include "game_context.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>
#include <stdlib.h>


# define HEIGHT 800
# define WIDTH 800

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
}t_mlx_game;

int		close_window(t_mlx_game *screen);
void	close_clean(t_mlx_game *screen);

void	init_mlx(t_mlx_data *my_mlx);

#endif