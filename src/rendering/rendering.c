/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/03 11:31:26 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <inttypes.h>

static mlx_texture_t	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_dir == WALL_NORTH)
		return (game->north.tex);
	else if (ray->hit_dir == WALL_SOUTH)
		return (game->south.tex);
	else if (ray->hit_dir == WALL_EAST)
		return (game->east.tex);
	else if (ray->hit_dir == WALL_WEST)
		return (game->west.tex);
	else
		return (NULL);
}

static uint32_t	get_wall_pixel_color(t_game *game, t_ray *ray, int pixel_y)
{
	mlx_texture_t	*texture;
	double			wall_hit_pos;
	double			height;
	int				tex_x;
	int				tex_y;

	texture = get_texture(game, ray);
	if (!texture)
		return (RENDERING_ERROR);
	height = game->mlx->height / ray->distance;
	if (ray->hit_dir == WALL_EAST || ray->hit_dir == WALL_WEST)
		wall_hit_pos = ray->hit_y - (int)ray->hit_y;
	else
		wall_hit_pos = ray->hit_x - (int)ray->hit_x;
    if(ray->hit_dir == WALL_WEST || ray->hit_dir == WALL_SOUTH)
        wall_hit_pos = 1.0 - wall_hit_pos;
	tex_x = (int)(wall_hit_pos * texture->width);
	// if (tex_x < 0)
	// 	tex_x = 0;
	// else if (tex_x >= (int)texture->width)
	// 	tex_x = texture->width - 1;
	tex_y =  (int)(((double)(pixel_y - (game->mlx->height - height) / 2)
			/ height) * texture->height);
	// we shouldn't get any out of bounds values
	// if (tex_y < 0)
	// 	tex_y = 0;
	// else if (tex_y >= (int)texture->height)
	// 	tex_y = texture->height - 1;
	return (get_pixel_color(texture, tex_x, tex_y));
}

void	draw_wall(t_game *game, int pixel_x, t_ray ray)
{
	double		height;
	int			start;
	int			end;
	uint32_t	color;
	int			pixel_y;

	height = (game->mlx->height / ray.distance);
	start = (game->mlx->height - (int)height) / 2;
	end = start + (int)height;
	if (end > game->mlx->height)
		end = game->mlx->height;
	if (start < 0)
		start = 0;
	pixel_y = start;
	while (pixel_y < end)
	{
		color = get_wall_pixel_color(game, &ray, pixel_y);
		mlx_put_pixel(game->img, pixel_x, pixel_y, color);
		pixel_y++;
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
