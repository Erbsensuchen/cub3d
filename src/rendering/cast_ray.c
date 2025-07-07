/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:03:56 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 18:12:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	is_end(t_game *game, double x, double y)
{
	bool	is_out_of_bounds;

	is_out_of_bounds = (x < 0 || x >= game->width || y < 0
			|| y >= game->height);
	return (is_out_of_bounds || game->grid[(int)y][(int)x] == ' '
		|| game->grid[(int)y][(int)x] == '1');
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
	ray.door_distance = 0.0;
	while (1)
	{
		ray.prev_x = x;
		ray.prev_y = y;
		x += cos(ray_angle) * RAY_STEP;
		y += sin(ray_angle) * RAY_STEP;
		distance += RAY_STEP;
		if (is_end(game, x, y))
			break ;
		if ((game->grid[(int)y][(int)x] == 'D'
				|| game->grid[(int)y][(int)x] == 'd')
			&& ray.door_distance == 0.0)
		{
			ray.door_hit_x = x;
			ray.door_hit_y = y;
			ray.door_distance = distance * cos(mod_angle(ray_angle
						- game->player_rotation));
			ray.door_open = (game->grid[(int)y][(int)x] == 'd');
			ray.door_dir = get_door_direction(&ray, game);
		}
	}
	ray.distance = distance * cos(mod_angle(ray_angle - game->player_rotation));
	ray.hit_dir = get_direction(&ray, game);
	return (ray.hit_x = x, ray.hit_y = y, ray);
}
