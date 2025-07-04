/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:18:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 16:18:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uint32_t	lcg_rand(void)
{
	static uint32_t	state = 1;

	state = 1664525u * state + 1013904223u;
	return (state);
}

uint32_t	lcg_rand_max(uint32_t max)
{
	return (lcg_rand() % max);
}
