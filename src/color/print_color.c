/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:53:03 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/17 15:04:04 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_color(t_color *color)
{
	if (color == NULL)
	{
		printf("Color is NULL\n");
		return ;
	}
	printf("(%d | %d | %d)\n", color->r, color->g, color->b);
}
