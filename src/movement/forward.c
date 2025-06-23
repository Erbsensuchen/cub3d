/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:54:19 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 14:31:47 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + cos(game->player_rotation) * MOVEMENT_SPEED;
	new_y = game->player_y + sin(game->player_rotation) * MOVEMENT_SPEED;
	return (test_movement(game, new_x, new_y));
}
