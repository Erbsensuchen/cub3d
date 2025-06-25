/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/25 14:26:33 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_ray	ray_info(double ray_angle, t_game *game)
{
	double	distance;
	double	x;
	double	y;
	t_ray	ray;

	x = game->player_x;
	y = game->player_y;
	distance = 0.0;
	while (1)
	{
		x += cos(ray_angle) * RAY_STEP;
		y += sin(ray_angle) * RAY_STEP;
		distance += RAY_STEP;
		if (game->grid[(int)y][(int)x] == '1')
			break ;
	}
	distance = distance * cos(mod_angle(ray_angle - game->player_rotation));
	ray.angle = ray_angle;
	ray.distance = distance;
	ray.hit_x = x;
	ray.hit_y = y;
	return (ray);
}

void	draw_wall(t_game *game, int pixel_x, t_ray ray)
{
	double	height;
	int		start;
	int		end;
	int		color;

	height = (game->mlx->height / ray.distance);
	start = (game->mlx->height - (int)height) / 2;
	end = start + (int)height;
	if (end > game->mlx->height)
		end = game->mlx->height;
	if (start < 0)
		start = 0;
	color = 0x008080FF;
	while (start < end)
	{
		mlx_put_pixel(game->img, pixel_x, start, color);
		start++;
	}
}

void	cast_rays(t_game *game)
{
	double	ray_angle;
	int		pixel_x;

	pixel_x = 0;
	while (pixel_x < game->mlx->width)
	{
		ray_angle = game->player_rotation - FOV / 2 + (FOV * pixel_x
				/ game->mlx->width);
		ray_angle = mod_angle(ray_angle);
		draw_wall(game, pixel_x, ray_info(ray_angle, game));
		pixel_x++;
	}
}
