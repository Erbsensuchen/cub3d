/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:44:02 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 16:50:42 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	double_close(double x, double y)
{
	return (fabs(x - y) <= DOUBLE_EPSILON);
}

void	normalize_doubles(double *x, double *y)
{
	double	length;

	length = sqrt((*x) * (*x) + (*y) * (*y));
	if (length != 0.0)
	{
		*x /= length;
		*y /= length;
	}
}

double	ft_distance(int x, int y, int px, int py)
{
	double	dx;
	double	dy;

	dx = (double)(px - x);
	dy = (double)(py - y);
	return (sqrt(dx * dx + dy * dy));
}
