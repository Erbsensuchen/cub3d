/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 12:19:21 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_texture(mlx_t *mlx, t_texture *texture)
{
	(void)mlx;
	free(texture->path);
	texture->path = NULL;
	mlx_delete_texture(texture->tex);
	texture->tex = NULL;
	if (texture->xpmt)
	{
		mlx_delete_xpm42(texture->xpmt);
		texture->xpmt = NULL;
	}
}
