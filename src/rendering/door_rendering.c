/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:00:15 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 17:01:08 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_door(t_game *game, int pixel_x, t_ray ray)
{
	double		height;
	int			start;
	int			end;
	uint32_t	color;
	int			pixel_y;

	height = (game->mlx->height / ray.door_distance);
	start = (game->mlx->height - (int)height) / 2;
	end = start + (int)height;
	if (end > game->mlx->height)
		end = game->mlx->height;
	if (start < 0)
		start = 0;
	pixel_y = start;
	while (pixel_y < end)
	{
		color = get_door_pixel_color(game, &ray, pixel_y);
		if ((color & 0xff) != 0)
			mlx_put_pixel(game->img, pixel_x, pixel_y, color);
		pixel_y++;
	}
}

uint32_t	get_door_pixel_color(t_game *game, t_ray *ray, int pixel_y)
{
	mlx_texture_t	*texture;
	double			wall_hit_pos;
	int				height;
	int				tex_x;
	int				tex_y;

	texture = game->door_close_texture.tex;
	if (ray->door_open)
		texture = game->door_open_texture.tex;
	height = game->mlx->height / ray->door_distance;
	if (ray->door_dir == WALL_EAST || ray->door_dir == WALL_WEST)
		wall_hit_pos = ray->door_hit_y - (int)ray->door_hit_y;
	else
		wall_hit_pos = ray->door_hit_x - (int)ray->door_hit_x;
	if (ray->door_dir == WALL_WEST || ray->door_dir == WALL_SOUTH)
		wall_hit_pos = 1.0 - wall_hit_pos;
	tex_x = (int)(wall_hit_pos * texture->width);
	tex_y = (int)(((double)(pixel_y - (game->mlx->height - height) / 2)
				/ height) * texture->height);
	return (get_pixel_color(texture, tex_x, tex_y));
}
