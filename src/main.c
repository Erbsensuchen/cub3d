/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 15:52:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Usage: ./cub3d <scene_file>\n", STDERR_FILENO);
		return (free_game(&game), EXIT_FAILURE);
	}
	if (!scene_valid(argv[1]))
		return (free_game(&game), EXIT_FAILURE);
	if (parse_game(&game, argv[1]))
		return (free_game(&game), EXIT_FAILURE);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!game.mlx)
		return (free_game(&game), EXIT_FAILURE);
	if (DEBUG)
		print_game(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	return (free_game(&game), EXIT_SUCCESS);
}
