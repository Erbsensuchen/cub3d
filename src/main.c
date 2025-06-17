/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 15:32:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	init_game(&game);
	if (DEBUG)
		print_game(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
