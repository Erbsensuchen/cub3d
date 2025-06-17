/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:54:16 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 14:54:23 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - game->x_movement * cos(game->player_y_rotation);
	new_y = game->player_y - game->y_movement * sin(game->player_y_rotation);
	if (game->grid[(int)new_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
	}
}
