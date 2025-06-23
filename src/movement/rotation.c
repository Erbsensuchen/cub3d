/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:42:44 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 11:42:45 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	rotate_left(t_game *game)
{
	game->player_rotation -= ROTATION_SPEED;
	if (game->player_rotation < 0)
		game->player_rotation += 2 * M_PI;
	return (0);
}

int	rotate_right(t_game *game)
{
	game->player_rotation += ROTATION_SPEED;
	if (game->player_rotation >= 2 * M_PI)
		game->player_rotation -= 2 * M_PI;
	return (0);
}
