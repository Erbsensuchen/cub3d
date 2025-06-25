/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:44:18 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/25 14:26:33 by mlendle          ###   ########.fr       */
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
	delta_x = x - (game->mlx->width / 2);
	game->player_rotation += delta_x * MOUSE_SENSITIVITY;
	game->player_rotation = mod_angle(game->player_rotation);
	if (DEBUG)
		print_game(game);
}
