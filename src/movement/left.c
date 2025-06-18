/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:55:30 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/18 14:02:16 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - cos(game->player_rotation + M_PI_2)
		* MOVEMENT_SPEED;
	new_y = game->player_y - sin(game->player_rotation + M_PI_2)
		* MOVEMENT_SPEED;
	if (game->grid[(int)new_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
		return (1);
	}
	return (0);
}
