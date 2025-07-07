/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 16:46:24 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	door(t_game *game)
{
	double			door_x;
	double			door_y;
	static double	btn_delay = 0;

	door_x = game->player_x + cos(game->player_rotation)
		* DOOR_REACHABLE_DISTANCE;
	door_y = game->player_y + sin(game->player_rotation)
		* DOOR_REACHABLE_DISTANCE;
	if (door_x < 0 || door_x >= game->width || door_y < 0
		|| door_y >= game->height)
		return ;
	if (game->grid[(int)door_y][(int)door_x] == 'D')
	{
		mlx_set_instance_depth(game->door_open_text->instances, 2);
		if (mlx_is_key_down(game->mlx, MLX_KEY_E) && btn_delay < mlx_get_time())
		{
			btn_delay = mlx_get_time() + 0.5;
			game->grid[(int)door_y][(int)door_x] = 'd';
			mlx_set_instance_depth(game->door_open_text->instances, 0);
		}
	}
	else if (game->grid[(int)door_y][(int)door_x] == 'd')
	{
		mlx_set_instance_depth(game->door_close_text->instances, 2);
		if (mlx_is_key_down(game->mlx, MLX_KEY_E) && btn_delay < mlx_get_time()
			&& ((int)door_y != (int)game->player_y
				|| (int)door_x != (int)game->player_x))
		{
			btn_delay = mlx_get_time() + 0.5;
			game->grid[(int)door_y][(int)door_x] = 'D';
			mlx_set_instance_depth(game->door_close_text->instances, 0);
		}
	}
	else
	{
		mlx_set_instance_depth(game->door_open_text->instances, 0);
		mlx_set_instance_depth(game->door_close_text->instances, 0);
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
	pre_render(game);
	cast_rays(game);
	print_minimap(game);
	door(game);
	update_goose(game);
	render_goose(game);
}
