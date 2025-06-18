/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:24:28 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/18 13:29:28 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_movement_values(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_x = 0.0;
	game->player_y = 0.0;
	// game->player_x_rotation = 0.0;
	game->player_rotation = 0.0;
	game->forward = 0;
	game->sideways = 0;
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
