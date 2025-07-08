/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 10:54:15 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"

// free the allocated space for the image, the screen and the display.
//(display is the connection beetween the server x and the program)
void	close_clean(t_mlx_data *screen)
{
	mlx_destroy_image(screen->mlx_ptr, screen->img.img_ptr);
	mlx_destroy_window(screen->mlx_ptr, screen->win_ptr);
	mlx_destroy_display(screen->mlx_ptr);
	free(screen->mlx_ptr);
	exit(0);
}

int	close_window(t_mlx_data *screen)
{
	close_clean(screen);
	return (0);
}

