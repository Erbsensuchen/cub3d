/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/01 12:35:49 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_wall_dir	get_direction(t_ray *ray, t_game *game)
{
	int	prev_x;
	int	prev_y;
	int	hit_x;
	int	hit_y;
	int	dx;
	int	dy;

	prev_x = (int)ray->prev_x;
	prev_y = (int)ray->prev_y;
	hit_x = (int)ray->hit_x;
	hit_y = (int)ray->hit_y;
	dx = hit_x - prev_x;
	dy = hit_y - prev_y;
	if (dx > 0 && dy == 0)
		return (WALL_EAST);
	if (dx < 0 && dy == 0)
		return (WALL_WEST);
	if (dy > 0 && dx == 0)
		return (WALL_SOUTH);
	if (dy < 0 && dx == 0)
		return (WALL_NORTH);
	if (dx != 0 && game->grid[prev_y][prev_x + dx] == '1')
		return ((dx > 0) ? WALL_EAST : WALL_WEST);
	if (dy != 0 && game->grid[prev_y + dy][prev_x] == '1')
		return ((dy > 0) ? WALL_SOUTH : WALL_NORTH);
	return (WALL_UNKNOWN);
}

static t_ray	ray_info(double ray_angle, t_game *game)
{
	double	x;
	double	y;
	double	distance;
	t_ray	ray;

	x = game->player_x;
	y = game->player_y;
	distance = 0.0;
	ray.angle = ray_angle;
	while (1)
	{
		ray.prev_x = x;
		ray.prev_y = y;
		x += cos(ray_angle) * RAY_STEP;
		y += sin(ray_angle) * RAY_STEP;
		distance += RAY_STEP;
		if (game->grid[(int)y][(int)x] == '1')
			break ;
	}
	ray.distance = distance * cos(mod_angle(ray_angle - game->player_rotation));
	ray.hit_x = x;
	ray.hit_y = y;
	ray.hit_dir = get_direction(&ray, game);
	return (ray);
}

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
		draw_wall(game, pixel_x, ray_info(ray_angle, game));
		pixel_x++;
	}
}
