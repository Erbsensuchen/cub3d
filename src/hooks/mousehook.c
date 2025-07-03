/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:53:40 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/03 12:34:47 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mousehook(mouse_key_t keydata, action_t action, modifier_key_t mods,
		void *param)
{
	t_game	*game;

	(void)mods;
	game = (t_game *)param;
	if (keydata == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (game->capture_mouse)
		{
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
			game->capture_mouse = !game->capture_mouse;
		}
		else if (!game->capture_mouse)
		{
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
			game->capture_mouse = !game->capture_mouse;
		}
	}
}
