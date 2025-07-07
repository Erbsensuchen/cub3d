/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:54:42 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 18:37:09 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel(t_game *game, int x, int y, uint32_t color)
{
	if (x < 0 || x >= game->mlx->width || y < 0 || y >= game->mlx->height)
		return ;
	mlx_put_pixel(game->img, x, y, color);
}

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

t_wall_dir	get_direction(t_ray *ray, t_game *game)
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

t_wall_dir	get_door_direction(t_ray *ray, t_game *game)
{
	int	dx;
	int	dy;

	dx = (int)ray->door_hit_x - (int)ray->prev_x;
	dy = (int)ray->door_hit_y - (int)ray->prev_y;
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

void	init_ray(t_ray *ray, double x, double y, double ra)
{
	ray->x = x;
	ray->y = y;
	ray->angle = ra;
}
