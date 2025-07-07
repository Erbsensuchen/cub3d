/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 12:13:08 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_texture(t_texture *texture)
{
	if (ft_strcmp(texture->path, OPEN_DOOR_PATH) && ft_strcmp(texture->path, CLOSE_DOOR_PATH))
		free(texture->path);
	texture->path = NULL;
	if (texture->xpmt)
	{
		mlx_delete_xpm42(texture->xpmt);
		texture->xpmt = NULL;
	}
	else if (texture->tex)
	{
		mlx_delete_texture(texture->tex);
		texture->tex = NULL;
	}
}
