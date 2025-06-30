/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/30 14:14:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	movement_handler(t_game *game)
{
	int	moved;

	game->move_x = 0;
	game->move_y = 0;
	if (game->forward)
		game->move_x = -1;
	if (game->backward)
		game->move_x += 1;
	if (game->left)
		game->move_y = -1;
	if (game->right)
		game->move_y += 1;
	if (game->rotation_left && !game->mouse_delta_x)
		game->player_rotation = mod_angle(game->player_rotation
				- ROTATION_SPEED);
	if (game->rotation_right && !game->mouse_delta_x)
		game->player_rotation = mod_angle(game->player_rotation
				+ ROTATION_SPEED);
	moved = move(game);
	return (moved || (game->rotation_left ^ game->rotation_right)
		|| game->mouse_delta_x);
}

void	loophook(void *param)
{
	t_game	*game;
	bool	moved;

	game = (t_game *)param;
	if (game->capture_mouse)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
		mlx_set_mouse_pos(game->mlx, game->mlx->width / 2, game->mlx->height
			/ 2);
	}
	moved = movement_handler(game);
	game->mouse_delta_x = 0;
	if (DEBUG && moved)
		print_movement(game);
	game->old_img = game->img;
	game->img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	pre_render(game);
	cast_rays(game);
	print_minimap(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	if (game->old_img)
		mlx_delete_image(game->mlx, game->old_img);
}
