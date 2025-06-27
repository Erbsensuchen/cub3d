/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:05:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/27 14:12:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_cell(t_game *game, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	if (x < 0 || y < 0 || x >= game->width || y >= game->height
		|| game->grid[y][x] != '1')
		return ;
	pixel_y = 0;
	while (pixel_y < game->mi_cell_size)
	{
		pixel_x = 0;
		while (pixel_x < game->mi_cell_size)
		{
			mlx_put_pixel(game->img, pixel_x + x * game->mi_cell_size, pixel_y
				+ y * game->mi_cell_size, game->floor.rgb);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	print_minimap(t_game *game)
{
	int	y;
	int	x;

	y = -MINIMAP_CELLS_COUNT / 2;
	while (y < MINIMAP_CELLS_COUNT / 2 + 1)
	{
		x = -MINIMAP_CELLS_COUNT / 2;
		while (x < MINIMAP_CELLS_COUNT / 2 + 1)
		{
			print_cell(game, (int)(game->player_x) + x, (int)(game->player_y)
				+ y);
			x++;
		}
		y++;
	}
}
