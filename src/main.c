/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 18:46:24 by lseeger          ###   ########.fr       */
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
	if (game.img)
		mlx_delete_image(game.mlx, game.img);
	return (free_game(&game), EXIT_SUCCESS);
}
