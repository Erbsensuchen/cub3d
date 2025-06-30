/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:44:02 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/30 15:05:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

void	normalize_double(double *x, double *y)
{
	double	mag;

	mag = sqrt((*x) * (*x) + (*y) * (*y));
	if (mag > 1e-5)
	{
		*x /= mag;
		*y /= mag;
	}
	else
	{
		*x = 0.0;
		*y = 0.0;
	}
}

bool	double_close(double x, double y)
{
	return (fabs(x - y) <= DOUBLE_EPSILON);
}
