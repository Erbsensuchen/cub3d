/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:24:28 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/17 15:56:53 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_movement_values(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0.0;
	game->player_y = 0.0;
	game->player_x_rotation = 0.0;
	game->player_y_rotation = 0.0;
	game->x_movement = 0.0;
	game->y_movement = 0.0;
	game->x_rotation = 0.0;
	game->y_rotation = 0.0;
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

void	free_game(t_game *game)
{
	free_texture(game->mlx, &game->north);
	free_texture(game->mlx, &game->south);
	free_texture(game->mlx, &game->east);
	free_texture(game->mlx, &game->west);
	free_grid(game);
	reset_movement_values(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
