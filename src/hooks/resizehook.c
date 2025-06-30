/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizehook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:40:44 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/30 15:20:04 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	resize(int width, int height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, width, height);
	if (!game->img)
	{
		ft_putstr_fd("Error: Could not create new image.\n", STDERR_FILENO);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	game->mlx->width = width;
	game->mlx->height = height;
	game->mi_size = width * MINIMAP_SIZE;
	game->mi_cell_size = game->mi_size / MINIMAP_CELLS_COUNT;
	game->mi_player_size = width * MINIMAP_PLAYER_SIZE;
	game->mi_player_width = width * MINIMAP_PLAYER_WIDTH;
}
