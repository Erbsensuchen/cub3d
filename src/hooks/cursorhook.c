/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:44:18 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 16:48:58 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cursorhook(double x, double y, void *param)
{
	t_game	*game;
	double	delta_x;

	(void)y;
	game = (t_game *)param;
	if (!game->capture_mouse)
		return ;
	delta_x = x - (WIN_WIDTH / 2);
	if (delta_x > 0)
	{
		game->player_rotation += delta_x * MOUSE_SENSITIVITY;
		if (game->player_rotation >= 2 * M_PI)
			game->player_rotation -= 2 * M_PI;
	}
	else if (delta_x < 0)
	{
		game->player_rotation += delta_x * MOUSE_SENSITIVITY;
		if (game->player_rotation < 0)
			game->player_rotation += 2 * M_PI;
	}
	if (DEBUG)
		print_game(game);
}
