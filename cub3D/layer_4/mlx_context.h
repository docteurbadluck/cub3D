/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_context.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:28:12 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONTEXT_H
#define MLX_CONTEXT_H

#include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>
#include <stdlib.h>


# define HEIGHT 800
# define WIDTH 800

typedef struct s_key_state {
	int	w;
	int	s;
	int	left;
	int right;
}	t_key_state;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_key_state keys;
}	t_mlx_data;

int		close_window(t_mlx_data *screen);
void	close_clean(t_mlx_data *screen);

int on_key_press(int keycode, void *param);
int on_key_release(int keycode, void *param);

void init_mlx(t_mlx_data *my_mlx);


#endif