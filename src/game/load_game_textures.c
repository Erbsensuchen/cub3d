/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:11:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/01 13:55:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	process_texture(t_texture *texture, const char *texture_name)
{
	if (!texture->path)
		return (print_parsing_error_line("Missing texture path: ",
				texture_name), false);
	texture->xpmt = mlx_load_xpm42(texture->path);
	if (!texture->xpmt)
		return (print_parsing_error_line("Failed to load texture: ",
				texture_name), false);
	texture->tex = &texture->xpmt->texture;
	return (true);
}

bool	load_game_textures(t_game *game)
{
	if (!process_texture(&game->north, "North"))
		return (false);
	if (!process_texture(&game->south, "South"))
		return (false);
	if (!process_texture(&game->east, "East"))
		return (false);
	if (!process_texture(&game->west, "West"))
		return (false);
	return (true);
}
