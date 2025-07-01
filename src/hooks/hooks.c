/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:34:19 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/01 14:37:47 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hooks(t_game *game)
{
	mlx_resize_hook(game->mlx, resize, &game);
	mlx_key_hook(game->mlx, keyhook, &game);
	mlx_loop_hook(game->mlx, loophook, &game);
	mlx_cursor_hook(game->mlx, cursorhook, &game);
	mlx_mouse_hook(game->mlx, mousehook, &game);
}
