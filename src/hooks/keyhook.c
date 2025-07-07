/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:01:23 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 10:50:47 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	key_pressed(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		game->forward = true;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		game->backward = true;
	else if (keydata.key == MLX_KEY_A)
		game->left = true;
	else if (keydata.key == MLX_KEY_D)
		game->right = true;
	else if (keydata.key == MLX_KEY_LEFT)
		game->rotation_left = true;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->rotation_right = true;
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_C)
	{
		game->capture_mouse = !game->capture_mouse;
		if (game->capture_mouse)
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
		else
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
		mlx_set_mouse_pos(game->mlx, game->mlx->width / 2, game->mlx->height
			/ 2);
	}
}

void	key_released(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		game->forward = false;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		game->backward = false;
	else if (keydata.key == MLX_KEY_A)
		game->left = false;
	else if (keydata.key == MLX_KEY_D)
		game->right = false;
	else if (keydata.key == MLX_KEY_LEFT)
		game->rotation_left = false;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->rotation_right = false;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS)
		key_pressed(keydata, (t_game *)param);
	else if (keydata.action == MLX_RELEASE)
		key_released(keydata, (t_game *)param);
	if (DEBUG && keydata.action == MLX_PRESS && keydata.key == MLX_KEY_L)
		print_game((t_game *)param);
}
