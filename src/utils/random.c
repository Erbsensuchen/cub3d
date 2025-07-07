/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:18:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 19:04:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uint32_t	lcg_rand(void)
{
	static uint32_t	state = GOOSE_SEED;

	state = 1664525u * state + 1013904223u;
	return (state);
}

uint32_t	lcg_rand_max(uint32_t max)
{
	return (lcg_rand() % max);
}

uint32_t	lcg_rand01(void)
{
	return (lcg_rand() & 1);
}
