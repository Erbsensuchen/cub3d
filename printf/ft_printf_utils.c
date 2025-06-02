/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:43:51 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/07 10:56:36 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen_base(unsigned long long nb, char *base)
{
	int	counter;
	int	strlen;

	if (!nb)
		nb = 1;
	counter = 0;
	strlen = ft_strlen(base);
	while (nb != 0)
	{
		nb = nb / strlen;
		counter++;
	}
	return (counter);
}

void	write_nb_base(long long nb, int index, char *base)
{
	int	strlen;

	strlen = ft_strlen(base);
	while (index)
	{
		nb = nb / strlen;
		index--;
	}
	nb = nb % strlen;
	if (nb > 0)
		write(1, (base + nb), 1);
	else
		write(1, (base - nb), 1);
}

static void	recursion(unsigned long long nb, char *base)
{
	int	i;

	if (nb != 0)
	{
		recursion(nb / 16, base);
		i = nb % 16;
		if (nb > 0)
			write(1, base + i, 1);
		else
			write(1, base - i, 1);
	}
}

int	ft_put_ptr(unsigned long long n, char *base)
{
	write(1, "0x", 2);
	if (n == 0)
		write(1, "0", 1);
	recursion(n, base);
	return (ft_nblen_base(n, base) + 2);
}
