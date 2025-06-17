/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:47:02 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/17 15:06:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_textures(t_game *game)
{
	printf("Textures:\n");
	printf("North: ");
	print_texture(&game->north);
	printf("South: ");
	print_texture(&game->south);
	printf("East: ");
	print_texture(&game->east);
	printf("West: ");
	print_texture(&game->west);
}

void	print_game(t_game *game)
{
	printf("Game\n");
	printf("MLX: %p\n", game->mlx);
	printf("Window: %p\n", game->win);
	print_textures(game);
	printf("Floor Color: ");
	print_color(&game->floor);
	printf("Ceiling Color: ");
	print_color(&game->ceiling);
	print_grid(game);
	printf("Player Position: (%.2f | %.2f)\n", game->player_x, game->player_y);
	printf("Player Rotation: (%.2f | %.2f)\n", game->player_x_rotation,
		game->player_y_rotation);
	printf("Movement: (%.2f | %.2f)\n", game->x_movement, game->y_movement);
	printf("Rotation: (%.2f | %.2f)\n", game->x_rotation, game->y_rotation);
	if (game->scene_path)
		printf("Scene Path: %s\n", game->scene_path);
	else
		printf("Scene Path: NULL\n");
}

void	print_grid(t_game *game)
{
	printf("Map Grid:\n");
	(void)game;
}
