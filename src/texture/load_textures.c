/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:11:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 19:33:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	process_texture(t_texture *texture, const char *texture_name)
{
	int	len;

	if (!texture->path)
		return (print_parsing_error_line("Missing texture path: ",
				texture_name), false);
	len = ft_strlen(texture->path);
	if (len > 5 && ft_strcmp(texture->path + len - 4, ".png") == 0)
	{
		texture->tex = mlx_load_png(texture->path);
		if (!texture->tex)
			return (print_parsing_error_line("Failed to load texture: ",
					texture_name), false);
	}
	else if (len > 7 && ft_strcmp(texture->path + len - 6, ".xpm42") == 0)
	{
		texture->xpmt = mlx_load_xpm42(texture->path);
		if (!texture->xpmt)
			return (print_parsing_error_line("Failed to load texture: ",
					texture_name), false);
		texture->tex = &texture->xpmt->texture;
	}
	else
		return (print_parsing_error_line("invalid texture path: ",
				texture_name), false);
	return (true);
}

static bool	get_has_door(t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->height)
	{
		if (ft_strchr(game->grid[y], 'D') || ft_strchr(game->grid[y], 'd'))
			return (true);
	}
	return (false);
}

bool	load_game_textures(t_game *game)
{
	bool	has_door;

	has_door = get_has_door(game);
	if (!process_texture(&game->north, "North"))
		return (false);
	if (!process_texture(&game->south, "South"))
		return (false);
	if (!process_texture(&game->east, "East"))
		return (false);
	if (!process_texture(&game->west, "West"))
		return (false);
	if (GOOSE_COUNT > 0 && !process_texture(&game->goose, "Goose"))
		return (false);
	if (has_door && !process_texture(&game->door_open_texture, "Door Open"))
		return (false);
	if (has_door && !process_texture(&game->door_close_texture, "Door Close"))
		return (false);
	return (true);
}
