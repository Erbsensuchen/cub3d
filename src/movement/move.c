/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:10:36 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 16:34:44 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define COLLISION_RADIUS 0.1

static bool	is_walkable(char tile)
{
	return (tile == '0' || tile == 'd');
}

static bool	is_position_safe(t_game *game, double x, double y)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;

	min_x = (int)(x - COLLISION_RADIUS);
	max_x = (int)(x + COLLISION_RADIUS);
	min_y = (int)(y - COLLISION_RADIUS);
	max_y = (int)(y + COLLISION_RADIUS);
	for (int i = min_y; i <= max_y; i++)
	{
		for (int j = min_x; j <= max_x; j++)
		{
			if (i < 0 || j < 0 || i >= game->height || j >= game->width)
				return (false);
			if (!is_walkable(game->grid[i][j]))
				return (false);
		}
	}
	return (true);
}

static bool	test_movement(t_game *game, double x_move, double y_move)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + x_move * MOVEMENT_SPEED;
	new_y = game->player_y + y_move * MOVEMENT_SPEED;
	if (double_close(x_move, 0) && double_close(y_move, 0))
		return (false);
	if (is_position_safe(game, new_x, new_y))
	{
		game->player_x = new_x;
		game->player_y = new_y;
		return (true);
	}
	return (false);
}

bool	move(t_game *game)
{
	double	x_move;
	double	y_move;

	normalize_doubles(&game->move_x, &game->move_y);
	x_move = game->move_x * cos(game->player_rotation) - game->move_y
		* sin(game->player_rotation);
	y_move = game->move_x * sin(game->player_rotation) + game->move_y
		* cos(game->player_rotation);
	if (test_movement(game, x_move, y_move))
		return (true);
	else if (test_movement(game, x_move, 0))
		return (true);
	else if (test_movement(game, 0, y_move))
		return (true);
	return (false);
}
