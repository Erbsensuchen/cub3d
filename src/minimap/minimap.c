/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:05:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/27 16:09:28 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_pixel_pos_x(t_game *game, int x, int pixel_x)
{
	int	rest_x;
	int	res;

	rest_x = (game->player_x - (int)game->player_x) * game->mi_cell_size;
	res = pixel_x + (MINIMAP_CELLS_COUNT / 2 + x) * game->mi_cell_size - rest_x;
	if (res < 0 || res > game->mi_size)
		return (0);
	else
		return (res);
}

static int	get_pixel_pos_y(t_game *game, int y, int pixel_y)
{
	int	rest_y;
	int	res;

	rest_y = (game->player_y - (int)game->player_y) * game->mi_cell_size;
	res = pixel_y + (MINIMAP_CELLS_COUNT / 2 + y) * game->mi_cell_size - rest_y;
	if (res < 0 || res > game->mi_size)
		return (0);
	else
		return (res);
}

static void	print_cell(t_game *game, int x, int y)
{
	int	pixel_x;
	int	pixel_y;
	int	x_res;
	int	y_res;

	x_res = x + (int)game->player_x;
	y_res = y + (int)game->player_y;
	if (x_res < 0 || y_res < 0 || x_res >= game->width || y_res >= game->height
		|| game->grid[y_res][x_res] != '1')
		return ;
	pixel_y = 0;
	while (pixel_y < game->mi_cell_size)
	{
		pixel_x = 0;
		while (pixel_x < game->mi_cell_size)
		{
			mlx_put_pixel(game->img, get_pixel_pos_x(game, x, pixel_x),
				get_pixel_pos_y(game, y, pixel_y), game->floor.rgb);
			pixel_x++;
		}
		pixel_y++;
	}
}

void	print_minimap(t_game *game)
{
	int	y;
	int	x;
	int	center_x;
	int	center_y;

	y = -MINIMAP_CELLS_COUNT / 2;
	while (y < MINIMAP_CELLS_COUNT / 2 + 2)
	{
		x = -MINIMAP_CELLS_COUNT / 2;
		while (x < MINIMAP_CELLS_COUNT / 2 + 2)
		{
			print_cell(game, x, y);
			x++;
		}
		y++;
	}
	center_x = (MINIMAP_CELLS_COUNT * game->mi_cell_size) / 2;
	center_y = (MINIMAP_CELLS_COUNT * game->mi_cell_size) / 2;
	draw_player_triangle(game, center_x, center_y, fmod(game->player_rotation
			+ M_PI, 2 * M_PI));
}
