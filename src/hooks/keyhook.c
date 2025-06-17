/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:01:23 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 16:00:11 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_forward(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_backward(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate_left(game);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		rotate_right(game);
	if (DEBUG)
		print_game(game);
}
