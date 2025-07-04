/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/04 15:42:16 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	door(t_game *game)
{
	double	door_x;
	double	door_y;

	door_x = game->player_x + cos(game->player_rotation)
		* DOOR_REACHABLE_DISTANCE;
	door_y = game->player_y + sin(game->player_rotation)
		* DOOR_REACHABLE_DISTANCE;
	if (door_x < 0 || door_y < 0 || door_x >= game->width
		|| door_y >= game->height)
		if (game->grid[(int)door_y][(int)door_x] == 'D')
		{
			mlx_put_string(game->mlx, "Press 'E' to open the door", 10, 10);
		}
}

bool	movement_handler(t_game *game)
{
	int	moved;

	game->move_x = 0;
	game->move_y = 0;
	if (game->forward)
		game->move_x += 1;
	if (game->backward)
		game->move_x += -1;
	if (game->left)
		game->move_y += -1;
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
	door(game);
	if (game->old_img)
		mlx_delete_image(game->mlx, game->old_img);
	render_goos(game);
}
