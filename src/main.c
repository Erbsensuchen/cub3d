/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/20 17:31:08 by lseeger          ###   ########.fr       */
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
	if (DEBUG)
		print_game(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop_hook(game.mlx, loophook, &game);
	mlx_cursor_hook(game.mlx, mouse_rotation, &game);
	mlx_loop(game.mlx);
	return (free_game(&game), EXIT_SUCCESS);
}
