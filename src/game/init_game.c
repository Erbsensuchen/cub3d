/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:39 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/27 13:26:23 by lseeger          ###   ########.fr       */
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
	game->forward = 0;
	game->backward = 0;
	game->left = 0;
	game->right = 0;
	game->rotation_left = 0;
	game->rotation_right = 0;
	game->capture_mouse = true;
	game->img = NULL;
	game->old_img = NULL;
	game->mi_size = WIN_WIDTH * MINIMAP_SIZE;
	game->mi_cell_size = game->mi_size / MINIMAP_CELLS_COUNT;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	init_texture(&game->north);
	init_texture(&game->south);
	init_texture(&game->east);
	init_texture(&game->west);
	init_movement_values(game);
}
