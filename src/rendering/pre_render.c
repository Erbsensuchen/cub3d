/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:36:26 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 16:50:58 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

mlx_image_t	*pre_render(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_put_pixel(game->img, x, y,
					game->ceiling.r << 24 | game->ceiling.g << 16 | game->ceiling.b << 8 | 0xFF);
			else
				mlx_put_pixel(game->img, x, y,
					game->floor.r << 24 | game->floor.g << 16 | game->floor.b << 8 | 0xFF);
			x++;
		}
		y++;
		x = 0;
	}
	return (game->img);
}
