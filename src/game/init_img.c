/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:56:01 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 14:56:13 by mlendle          ###   ########.fr       */
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
