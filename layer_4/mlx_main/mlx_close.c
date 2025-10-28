/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/09/02 17:12:19 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_context.h"
#include "game.h"
#include "mlx_displayer.h"

int	close_window(t_mlx_game *GAME)
{
	close_clean(GAME);
	return (0);
}

void	close_clean(t_mlx_game *GAME)
{
	free_displayer(GAME);
	free_game_context(GAME);
	free_mlx(GAME);
	free_initial_data(*GAME->init_data);
	exit(0);
}

void	free_displayer(t_mlx_game *GAME)
{
	t_mlx_displayer	*ptr_displayer;

	ptr_displayer = (t_mlx_displayer *)GAME->game_context->displayer;
	destroy_texture(ptr_displayer);
	free(ptr_displayer->textures);
	destroy_sprite(ptr_displayer);
	mlx_destroy_image(GAME->my_mlx->mlx_ptr,
		ptr_displayer->minimap_img.img_ptr);
}

void	free_game_context(t_mlx_game *GAME)
{
	free(GAME->game_context->player);
	free(GAME->game_context->controller);
	free(GAME->game_context->displayer);
	free_map_grid_mlx(GAME->game_context->map);
	free(GAME->game_context->map);
	free(GAME->game_context->sprites);
	free(GAME->game_context);
}

void	free_mlx(t_mlx_game *GAME)
{
	mlx_destroy_image(GAME->my_mlx->mlx_ptr, GAME->my_mlx->img.img_ptr);
	mlx_destroy_window(GAME->my_mlx->mlx_ptr, GAME->my_mlx->win_ptr);
	mlx_destroy_display(GAME->my_mlx->mlx_ptr);
	free(GAME->my_mlx->mlx_ptr);
	free(GAME->my_mlx);
}
