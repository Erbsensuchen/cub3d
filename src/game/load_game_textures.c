/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:11:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 18:27:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	process_texture(t_game *game, t_texture *texture,
		const char *texture_name)
{
	xpm_t	*xpmt;

	if (!texture->path)
		return (print_parsing_error_line("Missing texture path: ",
				texture_name), false);
	xpmt = mlx_load_xpm42(texture->path);
	if (!xpmt)
		return (print_parsing_error_line("Failed to load texture: ",
				texture_name), false);
	texture->img = mlx_texture_to_image(game->mlx, &xpmt->texture);
	mlx_delete_xpm42(xpmt);
	if (!texture->img)
		return (print_parsing_error_line("Failed to convert texture to image: ",
				texture_name), false);
	return (true);
}

bool	load_game_textures(t_game *game)
{
	if (!process_texture(game, &game->north, "North"))
		return (false);
	if (!process_texture(game, &game->south, "South"))
		return (false);
	if (!process_texture(game, &game->east, "East"))
		return (false);
	if (!process_texture(game, &game->west, "West"))
		return (false);
	return (true);
}
