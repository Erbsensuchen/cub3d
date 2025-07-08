/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:24:28 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/08 13:46:16 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_movement_values(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0.0;
	game->player_y = 0.0;
	game->player_rotation = 0.0;
	game->forward = false;
	game->backward = false;
	game->left = false;
	game->right = false;
}

static void	free_grid(t_game *game)
{
	int	i;

	if (game->grid)
	{
		i = 0;
		while (i < game->height)
		{
			free(game->grid[i]);
			game->grid[i] = NULL;
			i++;
		}
		free(game->grid);
		game->grid = NULL;
	}
}

static void	free_goos_data(t_game *game)
{
	free(game->goose_pos_x);
	game->goose_pos_x = NULL;
	free(game->goose_pos_y);
	game->goose_pos_y = NULL;
	free(game->goose_target_x);
	game->goose_target_x = NULL;
	free(game->goose_target_y);
	game->goose_target_y = NULL;
	free(game->goose_states);
	game->goose_states = NULL;
	free(game->goose_times);
	game->goose_times = NULL;
	free(game->goose_anim_wait);
	game->goose_anim_wait = NULL;
	free(game->goose_anim_frame);
	game->goose_anim_frame = NULL;
	free(game->goose_anim_count);
	game->goose_anim_count = NULL;
}

void	free_game(t_game *game)
{
	free_texture(&game->north);
	free_texture(&game->south);
	free_texture(&game->east);
	free_texture(&game->west);
	free_texture(&game->goose);
	free_texture(&game->door_close_texture);
	free_texture(&game->door_open_texture);
	free_grid(game);
	reset_movement_values(game);
	if (game->img && game->mlx)
	{
		mlx_delete_image(game->mlx, game->img);
		game->img = NULL;
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_goos_data(game);
}
