/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/08 14:07:55 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!init_game(&game))
		return (EXIT_FAILURE);
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Usage: ./cub3d <scene_file.cub>\n", STDERR_FILENO);
		return (free_game(&game), EXIT_FAILURE);
	}
	if (!parse_game(&game, argv[1]) == EXIT_FAILURE)
		return (free_game(&game), EXIT_FAILURE);
	if (!load_game_textures(&game))
		return (free_game(&game), EXIT_FAILURE);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!game.mlx)
		return (free_game(&game), EXIT_FAILURE);
	init_img(&game);
	if (DEBUG)
		print_game(&game);
	hooks(&game);
	mlx_loop(game.mlx);
	return (free_game(&game), EXIT_SUCCESS);
}
