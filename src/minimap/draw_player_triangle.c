/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_triangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:37:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/27 15:39:51 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	fill_triangle(t_game *game, t_triangle *t, uint32_t color)
{
	t->py = t->min_y;
	while (t->py <= t->max_y)
	{
		t->px = t->min_x;
		while (t->px <= t->max_x)
		{
			t->a = ((t->left_y - t->right_y) * (t->px - t->right_x)
					+ (t->right_x - t->left_x) * (t->py - t->right_y))
				/ t->denom;
			t->b = ((t->right_y - t->tip_y) * (t->px - t->right_x) + (t->tip_x
						- t->right_x) * (t->py - t->right_y)) / t->denom;
			t->c = 1.0 - t->a - t->b;
			if (t->a >= 0 && t->b >= 0 && t->c >= 0)
			{
				if (t->px >= 0 && t->px < (int)game->img->width && t->py >= 0
					&& t->py < (int)game->img->height)
					mlx_put_pixel(game->img, t->px, t->py, color);
			}
			t->px++;
		}
		t->py++;
	}
}

void	draw_player_triangle(t_game *game, int x, int y, double angle_rad)
{
	t_triangle	t;

	t.tip_x = x;
	t.tip_y = y;
	t.base_x = t.tip_x - cos(angle_rad) * game->mi_player_size;
	t.base_y = t.tip_y - sin(angle_rad) * game->mi_player_size;
	t.left_x = t.base_x + cos(angle_rad + M_PI_2) * game->mi_player_width;
	t.left_y = t.base_y + sin(angle_rad + M_PI_2) * game->mi_player_width;
	t.right_x = t.base_x + cos(angle_rad - M_PI_2) * game->mi_player_width;
	t.right_y = t.base_y + sin(angle_rad - M_PI_2) * game->mi_player_width;
	t.min_x = fmin(t.tip_x, fmin(t.left_x, t.right_x));
	t.max_x = fmax(t.tip_x, fmax(t.left_x, t.right_x));
	t.min_y = fmin(t.tip_y, fmin(t.left_y, t.right_y));
	t.max_y = fmax(t.tip_y, fmax(t.left_y, t.right_y));
	t.denom = ((t.left_y - t.right_y) * (t.tip_x - t.right_x) + (t.right_x
				- t.left_x) * (t.tip_y - t.right_y));
	fill_triangle(game, &t, PLAYER_COLOR);
}
