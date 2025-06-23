/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 16:50:43 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	ray_lengh(double ray_angle, t_game *game)
{
	double	distance;
	double	x;
	double	y;

	x = game->player_x;
	y = game->player_y;
	distance = 0.0;
	while (1)
	{
		x += cos(ray_angle);
		y += sin(ray_angle);
		distance += 0.05;
		if (game->grid[(int)y][(int)x] == '1')
			break ;
	}
	return (distance);
}

void	draw_wall(t_game *game, int x, double distance)
{
	double	height;
	int		start;
	int		end;
	int		color;

	height = (WIN_HEIGHT / ((distance * distance) * 10));
	start = (WIN_HEIGHT - (int)height) / 2;
	end = start + (int)height;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;
	if (start < 0)
		start = 0;
	color = 0x008080FF;
	while (start < end)
	{
		mlx_put_pixel(game->img, x, start, color);
		start++;
	}
}

void	cast_rays(t_game *game)
{
	double	ray_angle;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_angle = game->player_rotation - FOV / 2 + (FOV * x / WIN_WIDTH);
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		if (ray_angle > 2 * M_PI)
			ray_angle -= 2 * M_PI;
		draw_wall(game, x, ray_lengh(ray_angle, game));
		x++;
	}
}
