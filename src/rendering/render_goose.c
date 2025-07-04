/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_goose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 16:42:07 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	render(t_game *game, int i)
{
	int	gx;
	int	gy;
	int	px;
	int	py;

	int x, y;
	gx = game->goose_pos_x[i];
	gy = game->goose_pos_y[i];
	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 18; x++)
		{
			px = gx + x;
			py = gy + y;
			// Bounds check (optional but safer)
			if (px >= 0 && (uint32_t)px < game->img->width && py >= 0
				&& (uint32_t)py < game->img->height)
			{
				mlx_put_pixel(game->img, px, py, 0xFF00FFFF);
			}
		}
	}
}

void	render_goose(t_game *game)
{
	int	i;

	i = 0;
	while (i < GOOSE_COUNT)
	{
		render(game, i);
		i++;
	}
}
