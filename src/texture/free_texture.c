/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 13:54:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_texture(t_texture *texture)
{
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
