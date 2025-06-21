/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:27:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 18:32:52 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_texture(mlx_t *mlx, t_texture *texture)
{
	free(texture->path);
	texture->path = NULL;
	if (texture->img)
	{
		mlx_delete_image(mlx, texture->img);
		texture->img = NULL;
	}
}
