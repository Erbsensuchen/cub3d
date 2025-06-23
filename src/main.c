/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 16:51:13 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Usage: ./cub3d <scene_file.cub>\n", STDERR_FILENO);
		return (free_game(&game), EXIT_FAILURE);
	}
	if (!parse_game(&game, argv[1]) == EXIT_FAILURE)
		return (free_game(&game), EXIT_FAILURE);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, TITLE, true);
	if (!game.mlx)
		return (free_game(&game), EXIT_FAILURE);
	// if (!load_game_textures(&game))
	// 	return (free_game(&game), EXIT_FAILURE);
	if (DEBUG)
		print_game(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop_hook(game.mlx, loophook, &game);
	mlx_cursor_hook(game.mlx, cursorhook, &game);
	mlx_loop(game.mlx);
	if (game.img)
		mlx_delete_image(game.mlx, game.img);
	return (free_game(&game), EXIT_SUCCESS);
}
