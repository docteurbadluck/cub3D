/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_function.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:04:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/14 10:22:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_displayer.h"

//	***mlx_mininap***
void	mlx_display_minimap(t_i_displayer *self,
			const t_map *map, const t_player *player);

//	***mlx_display_env***
void	mlx_display_env(const t_i_displayer *self,
			const t_framebuffer *frame_buff);

//	***mlx_displayer_tool***
void	my_pixel_put(int x, int y, t_img *img, int color);
void	background_render(int color_sky,
			int color_ground, t_mlx_data *my_mlx);

typedef struct s_line_to_display
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		screen_x;

	t_img	*texture;
	int		texture_x;
	int		texture_y;

	char	*pixel;
	int		color;
}	t_line_to_display;

void	init_line_to_draw_boundary(t_line_to_display *line_to_display,
			const t_framebuffer *frame_buff, int i);
void	init_line_to_draw_texture(t_line_to_display *line_to_display,
			const t_framebuffer *frame_buff,
			const t_mlx_displayer *displayer, int i);
void	init_line_to_draw_x_texture(t_line_to_display *line_to_display,
			const t_framebuffer *frame_buff, int i);
void	init_line_to_draw_y_texture(t_line_to_display *line_to_display,
			int y);
void	init_line_to_draw_pixel_color(t_line_to_display *line_to_display);
