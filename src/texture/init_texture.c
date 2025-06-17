/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:28:42 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/17 14:35:44 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_texture(t_texture *texture)
{
	texture->path = NULL;
	texture->img = NULL;
	texture->width = 0;
	texture->height = 0;
}
