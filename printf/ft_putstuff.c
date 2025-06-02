/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:29:42 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/06 15:18:44 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	counter;

	if (!nb)
		return (write(1, "0", 1));
	ft_putnbr_fd(nb, 1);
	counter = 0;
	if (nb < 0)
		counter++;
	while (nb != 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (str == 0)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putunbr(unsigned int nb)
{
	int	nblen;
	int	counter;

	nblen = ft_nblen_base(nb, "0123456789");
	if (!nblen)
		nblen = 1;
	counter = nblen;
	while (counter)
	{
		write_nb_base(nb, counter - 1, "0123456789");
		counter--;
	}
	return (nblen);
}

int	ft_puthex(long long nb, char *base)
{
	int	nblen;
	int	counter;

	nblen = ft_nblen_base(nb, base);
	if (!nblen)
		nblen = 1;
	counter = nblen;
	while (counter)
	{
		write_nb_base(nb, counter - 1, base);
		counter--;
	}
	return (nblen);
}
