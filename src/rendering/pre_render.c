/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:36:26 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/25 14:06:39 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

mlx_image_t	*pre_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mlx->height)
	{
        x = 0;
		while (x < game->mlx->width)
		{
			if (y < game->mlx->height / 2)
				mlx_put_pixel(game->img, x, y,
					game->ceiling.r << 24 | game->ceiling.g << 16 | game->ceiling.b << 8 | 0xFF);
			else
				mlx_put_pixel(game->img, x, y,
					game->floor.r << 24 | game->floor.g << 16 | game->floor.b << 8 | 0xFF);
			x++;
		}
		y++;
	}
	return (game->img);
}
