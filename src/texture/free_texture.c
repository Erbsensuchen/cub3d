/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/03 12:36:09 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_texture(mlx_t *mlx, t_texture *texture)
{
	(void)mlx;
	free(texture->path);
	texture->path = NULL;
	if (texture->xpmt)
	{
		mlx_delete_xpm42(texture->xpmt);
		texture->xpmt = NULL;
	}
}
