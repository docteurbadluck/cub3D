/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_displayer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:48:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/07/08 09:17:08 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../layer_3/displayer.h"
#include "mlx_context.h"


# define CYAN        0x00FFFF
# define YELLOW      0xFFFF00

typedef struct s_mlx_displayer
{
	t_displayer		base;
	t_mlx_data		*mlx;
}	t_mlx_displayer;


t_displayer	*create_displayer(t_mlx_data *mlx);
