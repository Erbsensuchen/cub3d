/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:09 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/01 13:49:10 by lseeger          ###   ########.fr       */
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

static uint32_t	get_wall_pixel_color(t_game *game, t_ray *ray, int start,
		int end)
{
	mlx_texture_t	*texture;
	double			wall_hit_pos;
	double			height;
	int				tex_x;
	int				tex_y;

	texture = get_texture(game, ray);
	if (!texture)
		return (RENDERING_ERROR);
	height = end - start;
	// Select the texture based on wall direction
	// Calculate horizontal coordinate on texture (wall hit position)
	if (ray->hit_dir == WALL_EAST || ray->hit_dir == WALL_WEST)
		wall_hit_pos = ray->hit_y - (int)ray->hit_y;
	else
		wall_hit_pos = ray->hit_x - (int)ray->hit_x;
	// Map wall_hit_pos (0.0 to 1.0) to texture width coordinate
	tex_x = (int)(wall_hit_pos * texture->width);
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= (int)texture->width)
		tex_x = texture->width - 1;
	// Map vertical screen coordinate (start to end) to texture height
	tex_y = (int)(((double)(start) / height) * texture->height);
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= (int)texture->height)
		tex_y = texture->height - 1;
	// Use the helper to get the pixel color from the texture
	return (get_pixel_color(texture, tex_x, tex_y));
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
	while (start < end)
	{
		color = get_wall_pixel_color(game, &ray, start, end);
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
