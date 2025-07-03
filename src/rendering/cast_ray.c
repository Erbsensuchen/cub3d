/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:03:56 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/03 12:02:08 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_wall_dir	resolve_diagonal_hit(t_game *game, t_ray *ray, int dx,
		int dy)
{
	if (dx != 0 && game->grid[(int)ray->prev_y][(int)ray->prev_x + dx] == '1')
	{
		if (dx > 0)
			return (WALL_EAST);
		else
			return (WALL_WEST);
	}
	if (dy != 0 && game->grid[(int)ray->prev_y + dy][(int)ray->prev_x] == '1')
	{
		if (dy > 0)
			return (WALL_SOUTH);
		else
			return (WALL_NORTH);
	}
	if (ray->angle > M_PI)
		return (WALL_NORTH);
	else
		return (WALL_SOUTH);
}

static t_wall_dir	get_direction(t_ray *ray, t_game *game)
{
	int	dx;
	int	dy;

	dx = (int)ray->hit_x - (int)ray->prev_x;
	dy = (int)ray->hit_y - (int)ray->prev_y;
	if (dx > 0 && dy == 0)
		return (WALL_EAST);
	if (dx < 0 && dy == 0)
		return (WALL_WEST);
	if (dy > 0 && dx == 0)
		return (WALL_SOUTH);
	if (dy < 0 && dx == 0)
		return (WALL_NORTH);
	return (resolve_diagonal_hit(game, ray, dx, dy));
}

t_ray	cast_ray(double ray_angle, t_game *game)
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
	// ray.distance = distance;
	ray.distance = distance * cos(mod_angle(ray_angle - game->player_rotation));
	ray.hit_x = x;
	ray.hit_y = y;
	ray.hit_dir = get_direction(&ray, game);
	return (ray);
}
