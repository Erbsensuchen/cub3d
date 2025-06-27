/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:24:14 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/27 17:16:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	test_movement(t_game *game, double new_x, double new_y)
{
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
	if (game->grid[(int)game->player_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		return (0);
	}
	if (game->grid[(int)new_y][(int)game->player_x] != '1')
	{
		game->player_y = new_y;
		return (0);
	}
	return (1);
}
