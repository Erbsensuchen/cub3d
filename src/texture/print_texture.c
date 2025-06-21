/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:49:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 18:33:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_texture(t_texture *texture)
{
	if (texture == NULL)
	{
		printf("Texture is NULL\n");
		return ;
	}
	if (texture->path)
		printf("Path: %s | ", texture->path);
	else
		printf("Path: NULL | ");
	printf("Image: %p | ", texture->img);
}
