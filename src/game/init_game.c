/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:39 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/17 16:00:04 by mlendle          ###   ########.fr       */
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
	// game->player_x_rotation = 0.0;
	game->player_rotation = 0.0;
	game->x_movement = 0.0;
	game->y_movement = 0.0;
	game->x_rotation = 0.0;
	game->y_rotation = 0.0;
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
