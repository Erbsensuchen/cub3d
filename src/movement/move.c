/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:10:36 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 18:50:56 by lseeger          ###   ########.fr       */
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
	t_box	box;
	t_iter	iter;

	box.min_x = (int)(x - COLLISION_RADIUS);
	box.max_x = (int)(x + COLLISION_RADIUS);
	box.min_y = (int)(y - COLLISION_RADIUS);
	box.max_y = (int)(y + COLLISION_RADIUS);
	iter.i = box.min_y;
	while (iter.i <= box.max_y)
	{
		iter.j = box.min_x;
		while (iter.j <= box.max_x)
		{
			if (iter.i < 0 || iter.j < 0 || iter.i >= game->height
				|| iter.j >= game->width)
				return (false);
			if (!is_walkable(game->grid[iter.i][iter.j]))
				return (false);
			iter.j++;
		}
		iter.i++;
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
	game->move_x *= game->delta_time;
	game->move_y *= game->delta_time;
	if (game->move_x > 0.9)
		game->move_x = 0.9;
	else if (game->move_x < -0.9)
		game->move_x = -0.9;
	if (game->move_y > 0.9)
		game->move_y = 0.9;
	else if (game->move_y < -0.9)
		game->move_y = -0.9;
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
