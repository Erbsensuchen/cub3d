/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/08 10:23:34 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handle_door_opening(t_game *game, double x, double y,
		double *btn_delay)
{
	game->door_open_text->enabled = true;
	if (mlx_is_key_down(game->mlx, MLX_KEY_E) && *btn_delay < mlx_get_time())
	{
		*btn_delay = mlx_get_time() + 0.5;
		game->grid[(int)y][(int)x] = 'd';
		game->door_open_text->enabled = false;
	}
}

static void	handle_door_closing(t_game *game, double x, double y,
		double *btn_delay)
{
	game->door_close_text->enabled = true;
	if (mlx_is_key_down(game->mlx, MLX_KEY_E) && *btn_delay < mlx_get_time()
		&& ((int)y != (int)game->player_y || (int)x != (int)game->player_x))
	{
		*btn_delay = mlx_get_time() + 0.5;
		game->grid[(int)y][(int)x] = 'D';
		game->door_close_text->enabled = false;
	}
}

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
		handle_door_opening(game, door_x, door_y, &btn_delay);
	else if (game->grid[(int)door_y][(int)door_x] == 'd')
		handle_door_closing(game, door_x, door_y, &btn_delay);
	else
	{
		game->door_close_text->enabled = false;
		game->door_open_text->enabled = false;
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
	if (double_close(game->old_time, 0.0))
		game->delta_time = 0.0;
	else
		game->delta_time = mlx_get_time() - game->old_time;
	game->old_time = mlx_get_time();
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
