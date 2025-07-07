/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:39 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 18:45:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_movement_values(t_game *game)
{
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceiling.r = 255;
	game->ceiling.g = 255;
	game->ceiling.b = 255;
	game->grid = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0.0;
	game->player_y = 0.0;
	game->player_rotation = 0.0;
	game->forward = false;
	game->backward = false;
	game->left = false;
	game->right = false;
	game->rotation_left = false;
	game->rotation_right = false;
	game->mouse_delta_x = 0;
	game->capture_mouse = true;
}

static void	init_minimap(t_game *game)
{
	game->mi_size = WIN_WIDTH * MINIMAP_SIZE;
	game->mi_cell_size = game->mi_size / MINIMAP_CELLS_COUNT;
	game->mi_player_size = WIN_WIDTH * MINIMAP_PLAYER_SIZE;
	game->mi_player_width = WIN_WIDTH * MINIMAP_PLAYER_WIDTH;
}

static bool	init_goos(t_game *game)
{
	game->goose_pos_x = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_pos_x)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_pos_y = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_pos_y)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_target_x = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_target_x)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_target_y = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_target_y)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_states = malloc(sizeof(t_goose_state) * GOOSE_COUNT);
	if (!game->goose_states)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_times = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_times)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_anim_frame = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_anim_frame)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goose_anim_count = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_anim_count)
		return (print_parsing_error("Memory allocation failed!"), false);
	return (true);
}

static bool	init_goose_values(t_game *game)
{
	int	i;

	game->goose_anim_wait = malloc(sizeof(int) * GOOSE_COUNT);
	if (!game->goose_anim_wait)
		return (print_parsing_error("Memory allocation failed!"), false);
	i = 0;
	while (i < GOOSE_COUNT)
	{
		game->goose_pos_x[i] = WIN_WIDTH / 2;
		game->goose_pos_y[i] = WIN_HEIGHT / 2;
		game->goose_target_x[i] = WIN_WIDTH / 2;
		game->goose_target_y[i] = WIN_HEIGHT / 2;
		game->goose_states[i] = GOOSE_SIT;
		game->goose_times[i] = 0;
		game->goose_anim_wait[i] = GOOSE_ANIM_WAIT_SIT;
		game->goose_anim_frame[i] = 0;
		game->goose_anim_count[i] = GOOSE_SIT_ANIM;
		i++;
	}
	return (true);
}

bool	init_game(t_game *game)
{
	game->mlx = NULL;
	game->delta_time = 0.0;
	game->old_time = 0.0;
	init_texture(&game->north);
	init_texture(&game->south);
	init_texture(&game->east);
	init_texture(&game->west);
	init_texture(&game->goose);
	init_texture(&game->door_open_texture);
	init_texture(&game->door_close_texture);
	game->door_open_texture.path = ft_strdup(OPEN_DOOR_PATH);
	if (!game->door_open_texture.path)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->door_close_texture.path = ft_strdup(CLOSE_DOOR_PATH);
	if (!game->door_close_texture.path)
		return (print_parsing_error("Memory allocation failed!"), false);
	init_movement_values(game);
	init_minimap(game);
	if (!init_goos(game))
		return (false);
	if (!init_goose_values(game))
		return (false);
	return (true);
}
