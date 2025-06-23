/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:55:30 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 14:31:42 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + cos(game->player_rotation + M_PI_2)
		* MOVEMENT_SPEED;
	new_y = game->player_y + sin(game->player_rotation + M_PI_2)
		* MOVEMENT_SPEED;
	return (test_movement(game, new_x, new_y));
}
