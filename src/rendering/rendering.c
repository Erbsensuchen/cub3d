/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/01 13:05:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static uint32_t	get_wall_color(t_ray *ray)
{
	if (ray->hit_dir == WALL_NORTH)
		return (0xFF4444FF);
	else if (ray->hit_dir == WALL_SOUTH)
		return (0x44FF44FF);
	else if (ray->hit_dir == WALL_EAST)
		return (0x4444FFFF);
	else if (ray->hit_dir == WALL_WEST)
		return (0xFFFF44FF);
	else
		return (0x888888FF);
}

void	draw_wall(t_game *game, int pixel_x, t_ray ray)
{
	double		height;
	int			start;
	int			end;
	uint32_t	color;

	height = (game->mlx->height / ray.distance);
	start = (game->mlx->height - (int)height) / 2;
	end = start + (int)height;
	if (end > game->mlx->height)
		end = game->mlx->height;
	if (start < 0)
		start = 0;
	color = get_wall_color(&ray);
	// insert textures here
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
		draw_wall(game, pixel_x, cast_ray(ray_angle, game));
		pixel_x++;
	}
}
