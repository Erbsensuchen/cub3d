/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:36:26 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/27 14:07:40 by lseeger          ###   ########.fr       */
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
				mlx_put_pixel(game->img, x, y, game->ceiling.rgb);
			else
				mlx_put_pixel(game->img, x, y, game->floor.rgb);
			x++;
		}
		y++;
	}
	return (game->img);
}
