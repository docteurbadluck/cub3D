/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 10:47:42 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../layer_3/displayer.h"
#include "mlx_displayer.h"


void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img ->img_pixels_ptr + offset) = color;
}

void	background_render(int color_sky, int color_ground, t_mlx_data *my_mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y, &my_mlx->img, color_sky);
			x++;
		}
		y++;
	}
	while (y < HEIGHT )
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y,  &my_mlx->img, color_ground);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr,
		my_mlx->img.img_ptr, 0, 0);
}



void mlx_display(const t_displayer *self, const t_framebuffer *frame_buff)
{
	const t_mlx_displayer *displayer = (const t_mlx_displayer *)self;

	// Clear the image buffer
	background_render(CYAN, YELLOW, displayer->mlx); 
	
	// Example render loop: just vertical lines for each ray
for (int i = 0; i < NBR_RAY; i++)
{
    double distance = frame_buff->rays[i].distance;
    if (distance < 0.0001)
        distance = 0.0001;

    int line_height = (int)(HEIGHT / distance);

    int start = (HEIGHT / 2) - (line_height / 2);
    int end = (HEIGHT / 2) + (line_height / 2);

    int x = (i * WIDTH) / NBR_RAY;  // map ray to screen column

    for (int y = start; y < end; y++)
    {
        my_pixel_put(x, y, &displayer->mlx->img, 0xFFFFFF);
    }
}	
}

void mlx_clear_screen(const t_displayer *self)
{
	t_mlx_displayer *d = (t_mlx_displayer *)self;
	mlx_clear_window(d->mlx->mlx_ptr, d->mlx->win_ptr);
}

t_displayer *create_displayer(t_mlx_data *mlx)
{
	t_mlx_displayer *displayer = malloc(sizeof(t_mlx_displayer));
	if (!displayer)
		return NULL;

	displayer->mlx = mlx;

	displayer->base.display = mlx_display;
	displayer->base.clear_screen = mlx_clear_screen; // optional

	return (t_displayer *)displayer;
}