/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:56:43 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 15:00:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window((mlx_t *)param);
	}
}

int	main(void)
{
	t_game	game;
	mlx_t	*mlx;

	init_game(&game);
	print_game(&game);
	mlx = mlx_init(800, 600, "cub3d", true);
	if (!mlx)
	{
		return (1);
	}
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
	free_game(&game);
	return (0);
}
