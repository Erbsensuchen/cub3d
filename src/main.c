/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 11:22:11 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_img(t_game *game)
{
	game->door_open_text = mlx_put_string(game->mlx, "Press E to open door", 10,
			10);
	game->door_close_text = mlx_put_string(game->mlx, "Press E to close door",
			10, 10);
	mlx_set_instance_depth(game->door_open_text->instances, 0);
	mlx_set_instance_depth(game->door_close_text->instances, 0);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_set_instance_depth(game->img->instances, 1);
}

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
