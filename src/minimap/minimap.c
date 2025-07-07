/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:05:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 14:41:52 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_pixel_pos_x(t_game *game, int x, int pixel_x)
{
	int	rest_x;
	int	res;

	rest_x = (game->player_x - (int)game->player_x) * game->mi_cell_size;
	res = pixel_x + (MINIMAP_CELLS_COUNT / 2 + x) * game->mi_cell_size - rest_x;
	return (res);
}

static int	get_pixel_pos_y(t_game *game, int y, int pixel_y)
{
	int	rest_y;
	int	res;

	rest_y = (game->player_y - (int)game->player_y) * game->mi_cell_size;
	res = pixel_y + (MINIMAP_CELLS_COUNT / 2 + y) * game->mi_cell_size - rest_y;
	return (res);
}

static void	print_cell(t_game *game, int x, int y)
{
	int	pixel_x;
	int	pixel_y;
	int	x_res;
	int	y_res;
	int	color;

	x_res = x + (int)game->player_x;
	y_res = y + (int)game->player_y;
	if (x_res < 0 || y_res < 0 || x_res >= game->width || y_res >= game->height
		|| game->grid[y_res][x_res] == '0' || game->grid[y_res][x_res] == ' ')
		return ;
	color = MINIMAP_WALL_COLOR;
	if (game->grid[y_res][x_res] == 'D')
		color = MINIMAP_DOOR_CLOSE_COLOR;
	else if (game->grid[y_res][x_res] == 'd')
		color = MINIMAP_DOOR_OPEN_COLOR;
	pixel_y = 0;
	while (pixel_y < game->mi_cell_size)
	{
		pixel_x = 0;
		while (pixel_x < game->mi_cell_size)
		{
			x_res = get_pixel_pos_x(game, x, pixel_x);
			y_res = get_pixel_pos_y(game, y, pixel_y);
			if (x_res >= 0 && x_res < game->mi_size && y_res >= 0
				&& y_res < game->mi_size)
				mlx_put_pixel(game->img, x_res, y_res, color);
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
