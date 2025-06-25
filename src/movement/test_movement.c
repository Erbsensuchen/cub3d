/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:24:14 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/25 11:45:00 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	test_movement(t_game *game, double new_x, double new_y)
{
	// normalize te player movement
	if ((game->forward || game->backward) && (game->right || game->left))
	{
		new_x = (new_x - game->player_x) / M_SQRT2 + game->player_x;
		new_y = (new_y - game->player_y) / M_SQRT2 + game->player_y;
	}
	if (game->grid[(int)new_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
		return (0);
	}
	// else if (game->grid[(int)new_y][(int)game->player_x] != '1')
	// {
	// 	game->player_y = new_y;
	// 	return (0);
	// }
	// else if (game->grid[(int)new_x][(int)game->player_y] != '1')
	// {
	// 	game->player_x = new_x;
	// 	return (0);
	// }
	return (1);
}
