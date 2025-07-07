/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:05:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 18:40:38 by lseeger          ###   ########.fr       */
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

static uint32_t	get_cell_minimap_color(t_game *game, int x, int y)
{
	char	cell;

	cell = game->grid[y][x];
	if (cell == 'D')
		return (MINIMAP_DOOR_CLOSE_COLOR);
	else if (cell == 'd')
		return (MINIMAP_DOOR_OPEN_COLOR);
	else
		return (MINIMAP_WALL_COLOR);
}

static void	print_cell(t_game *game, int x, int y)
{
	int			pixel_x;
	int			pixel_y;
	int			x_res;
	int			y_res;
	uint32_t	color;

	x_res = x + (int)game->player_x;
	y_res = y + (int)game->player_y;
	if (x_res < 0 || y_res < 0 || x_res >= game->width || y_res >= game->height
		|| game->grid[y_res][x_res] == '0' || game->grid[y_res][x_res] == ' ')
		return ;
	color = get_cell_minimap_color(game, x_res, y_res);
	pixel_y = 0;
	while (pixel_y < game->mi_cell_size)
	{
		pixel_x = 0;
		while (pixel_x < game->mi_cell_size)
		{
			put_pixel(game, get_pixel_pos_x(game, x, pixel_x),
				get_pixel_pos_y(game, y, pixel_y), color);
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
	draw_player_triangle(game, center_x, center_y, game->player_rotation);
}
