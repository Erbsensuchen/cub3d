/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:01:23 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/18 13:54:16 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	key_pressed(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W)
		game->forward = -1;
	else if (keydata.key == MLX_KEY_S)
		game->forward = 1;
	else if (keydata.key == MLX_KEY_A)
		game->sideways = -1;
	else if (keydata.key == MLX_KEY_D)
		game->sideways = 1;
	else if (keydata.key == MLX_KEY_LEFT)
		game->rotation = -1;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->rotation = 1;
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

void	key_released(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		game->forward = 0;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		game->sideways = 0;
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		game->rotation = 0;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS)
		key_pressed(keydata, (t_game *)param);
	else if (keydata.action == MLX_RELEASE)
		key_released(keydata, (t_game *)param);
	if (DEBUG)
		print_game((t_game *)param);
}
