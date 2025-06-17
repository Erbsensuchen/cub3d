/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 15:18:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	init_game(&game);
	print_game(&game);
	game.mlx = mlx_init(800, 600, "cub3d", true);
	if (!game.mlx)
	{
		return (1);
	}
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
