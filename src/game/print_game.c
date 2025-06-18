/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:47:02 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/18 13:51:59 by mlendle          ###   ########.fr       */
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
	print_textures(game);
	printf("Floor Color: ");
	print_color(&game->floor);
	printf("Ceiling Color: ");
	print_color(&game->ceiling);
	print_grid(game);
	printf("Player Position: (%.2f | %.2f)\n", game->player_x, game->player_y);
	printf("Player Rotation: %.2f\n", game->player_rotation);
	printf("\n");
}

void	print_grid(t_game *game)
{
	printf("Map Grid:\n");
	(void)game;
}
