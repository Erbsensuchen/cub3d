/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:10:36 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 14:51:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	test_movement(t_game *game, double x_move, double y_move)
{
	double	new_x;
	double	new_y;

	if (double_close(x_move, 0) && double_close(y_move, 0))
		return (false);
	x_move *= MOVEMENT_SPEED;
	y_move *= MOVEMENT_SPEED;
	new_x = game->player_x + x_move;
	new_y = game->player_y + y_move;
	if (game->grid[(int)new_y][(int)new_x] == '0'
		&& (game->grid[(int)game->player_y][(int)new_x] == '0'
			|| game->grid[(int)new_y][(int)game->player_x] == '0'))
		return (game->player_x = new_x, game->player_y = new_y, true);
	else
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
