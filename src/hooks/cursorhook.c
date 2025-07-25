/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursorhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:44:18 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/30 14:11:08 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cursorhook(double x, double y, void *param)
{
	t_game	*game;

	(void)y;
	game = (t_game *)param;
	if (!game->capture_mouse)
		return ;
	game->mouse_delta_x = x - (game->mlx->width / 2);
	game->player_rotation += game->mouse_delta_x * MOUSE_SENSITIVITY;
	game->player_rotation = mod_angle(game->player_rotation);
}
