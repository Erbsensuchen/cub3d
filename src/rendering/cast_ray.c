/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:03:56 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/08 12:01:13 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	is_end(t_game *game, double x, double y, t_ray *ray)
{
	bool	is_out_of_bounds;

	is_out_of_bounds = (x < 0 || x >= game->width || y < 0
			|| y >= game->height);
	if (is_out_of_bounds || game->grid[(int)y][(int)x] == ' '
		|| game->grid[(int)y][(int)x] == '1')
	{
		ray->hit_x = x;
		ray->hit_y = y;
		return (true);
	}
	return (false);
}

static bool	is_door(t_game *game, double x, double y, t_ray *ray)
{
	if (ray->door_d != 0.0)
		return (false);
	if (game->grid[(int)y][(int)x] == 'D' || game->grid[(int)y][(int)x] == 'd')
	{
		ray->door_hit_x = x;
		ray->door_hit_y = y;
		return (true);
	}
	else
		return (false);
}

t_ray	cast_ray(double ra, t_game *game)
{
	t_ray	ray;

	init_ray(&ray, game->player_x, game->player_y, ra);
	ray.c_d = 0.0;
	ray.door_d = 0.0;
	while (1)
	{
		ray.prev_x = ray.x;
		ray.prev_y = ray.y;
		ray.x += cos(ra) * RAY_STEP;
		ray.y += sin(ra) * RAY_STEP;
		ray.c_d += RAY_STEP;
		if (is_end(game, ray.x, ray.y, &ray))
			break ;
		if (is_door(game, ray.x, ray.y, &ray))
		{
			ray.door_d = ray.c_d * cos(mod_angle(ra - game->player_rotation));
			ray.door_open = (game->grid[(int)ray.y][(int)ray.x] == 'd');
			ray.door_dir = get_door_direction(&ray, game);
		}
	}
	ray.distance = ray.c_d * cos(mod_angle(ra - game->player_rotation));
	ray.hit_dir = get_direction(&ray, game);
	return (ray.hit_x = ray.x, ray.hit_y = ray.y, ray);
}
