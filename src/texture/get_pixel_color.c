/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:21:32 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/03 11:59:43 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uint32_t	get_pixel_color(mlx_texture_t *texture, int x, int y)
{
	uint8_t		*pixels;
	int			index;
	uint32_t	color;

	if (!texture || !texture->pixels)
		return (RENDERING_ERROR);
	if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
		return (RENDERING_OUT_OF_BOUNDS);
	pixels = texture->pixels;
	index = (y * texture->width + x) * texture->bytes_per_pixel;
	color = (pixels[index + 0] << 24) | (pixels[index
			+ 1] << 16) | (pixels[index + 2] << 8) | pixels[index + 3];
	return (color);
}
