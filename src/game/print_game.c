/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:47:02 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 16:40:06 by lseeger          ###   ########.fr       */
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
	printf("Goose: ");
	print_texture(&game->goose);
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
	print_movement(game);
	printf("mi_size: %i mi_cell_size: %i\n", game->mi_size, game->mi_cell_size);
	printf("\n");
}

void	print_grid(t_game *game)
{
	int	i;

	printf("Map Grid:\n");
	printf("Width: %d, Height: %d\n", game->width, game->height);
	i = 0;
	while (i < game->height)
	{
		if (game->grid[i])
			printf("%s\n", game->grid[i]);
		else
			printf("NULL\n");
		i++;
	}
}

void	print_movement(t_game *game)
{
	printf("Player Movement: (%.2f | %.2f)\n", game->move_x, game->move_y);
	printf("Player Position: (%.2f | %.2f)\n", game->player_x, game->player_y);
	printf("Player Rotation: %.2f\n", game->player_rotation);
}
