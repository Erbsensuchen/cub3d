/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:39 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 15:39:55 by lseeger          ###   ########.fr       */
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
	game->img = NULL;
	game->old_img = NULL;
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
	int	i;

	game->goos_pos_x = malloc(sizeof(int) * GOOS_COUNT);
	if (!game->goos_pos_x)
		return (print_parsing_error("Memory allocation failed!"), false);
	game->goos_pos_y = malloc(sizeof(int) * GOOS_COUNT);
	if (!game->goos_pos_y)
	{
		free(game->goos_pos_x);
		game->goos_pos_x = NULL;
		return (print_parsing_error("Memory allocation failed!"), false);
	}
	i = 0;
	while (i < GOOS_COUNT)
	{
		game->goos_pos_x[i] = i * 100; // Example initialization
		game->goos_pos_y[i] = i * 100; // Example initialization
		i++;
	}
	return (true);
}

bool	init_game(t_game *game)
{
	game->mlx = NULL;
	init_texture(&game->north);
	init_texture(&game->south);
	init_texture(&game->east);
	init_texture(&game->west);
	init_texture(&game->goos);
	init_movement_values(game);
	init_minimap(game);
	return (init_goos(game));
}
