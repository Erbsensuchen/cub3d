/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizehook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:40:44 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/25 11:45:07 by mlendle          ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	game->mlx->width = width;
	game->mlx->height = height;
	if (DEBUG)
		print_game(game);
}
