/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer_function.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:04:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/28 11:11:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DISPLAYER_FUNCTION_H
# define MLX_DISPLAYER_FUNCTION_H
# include "../mlx_displayer.h"

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

//	***MLX_DISPLAY_ENV***
void			mlx_display_env(const t_i_displayer *self,
					const t_framebuffer *frame_buff);

//	***MLX_SPRITE***
void			mlx_display_sprites(const t_i_displayer *self,
					t_spritebuffer *sprite_buff,
					const t_framebuffer *frame_buff);

//	***MLX_MINIMAP***
void			mlx_display_minimap(t_i_displayer *self,
					const t_map *map, const t_player *player);

//helper
void			init_line_to_draw_boundary(t_line_to_display *line_to_display,
					const t_framebuffer *frame_buff, int i);
void			init_line_to_draw_texture(t_line_to_display *line_to_display,
					const t_framebuffer *frame_buff,
					const t_mlx_displayer *displayer, int i);
void			init_line_to_draw_x_texture(t_line_to_display *line_to_display,
					const t_framebuffer *frame_buff, int i);
void			init_line_to_draw_y_texture(t_line_to_display *line_to_display,
					int y);
void			init_line_to_draw_pixel_color(t_line_to_display *line);
void			sort_sprite_by_distance(t_spritebuffer *s_buff);
int				transform_world_pos_to_camera_space(t_spritebuffer *s_buff,
					t_sprite_view *sprite);
void			set_position_and_size_on_screen(t_sprite_view *sprite);
void			set_draw_boundaries(t_sprite_view *sprite);
int				is_line_not_visible(int line, t_spritebuffer *sprite_buff,
					t_sprite_view *sprite, const t_framebuffer *frame_buff);
void			init_sprite_texture_coords(t_sprite_view *sprite, int x,
					int y, t_img *out_coords);
unsigned int	get_sprite_pixel_color(t_sprite_view *sprite, 
					t_img *coords);
void			animate_sprite(t_sprite_view *sprite,
					t_mlx_displayer *mlx_d);
void			update_texture_type(t_sprite_view *sprite);
void			change_texture_sprite(t_sprite_view *sprite,
					t_mlx_displayer *mlx_displayer);
void			draw_sprite(t_spritebuffer *sprite_buff,
					t_sprite_view *s, const t_i_displayer *self,
					const t_framebuffer *frame_buff);
void			my_pixel_put(int x, int y, t_img *img, int color);
void			background_render(int color_sky,
					int color_ground, t_mlx_data *my_mlx);

#endif