/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:54:42 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 16:54:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel(t_game *game, int x, int y, uint32_t color)
{
	if (x < 0 || x >= game->mlx->width || y < 0 || y >= game->mlx->height)
		return ;
	mlx_put_pixel(game->img, x, y, color);
}
