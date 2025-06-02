/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:34:57 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:59:29 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_nblen(int nb, t_flag *flag)
{
	int	counter;

	counter = 0;
	if (!nb && flag->precision != 0)
		return (1);
	while (nb != 0)
	{
		counter++;
		nb = nb / 10;
	}
	return (counter);
}

static int	flagslnum(int nb, t_flag *flag, int isnegative)
{
	int	counter;
	int	maxnblen;
	int	counter2;

	counter2 = 0;
	maxnblen = flag->precision;
	if (maxnblen < ft_nblen(nb, flag))
		maxnblen = ft_nblen(nb, flag);
	maxnblen += (isnegative || isflag(flag, '+') || isflag(flag, ' '));
	counter = 0;
	if (flag->precision != -1 || !isflag(flag, '0'))
		while (maxnblen + counter2 < flag->width && !isflag(flag, '-'))
			counter2 += write(1, " ", 1);
	if (isnegative)
		counter += write(1, "-", 1);
	else if (isflag(flag, '+'))
		counter += write(1, "+", 1);
	else if (isflag(flag, ' '))
		counter += write(1, " ", 1);
	while ((isflag(flag, '0') && !isflag(flag, '-') && flag->width - counter2
			- counter > ft_nblen(nb, flag)) || maxnblen > ft_nblen(nb, flag)
		+ counter)
		counter += write(1, "0", 1);
	return (counter + counter2);
}

static void	recursion(int nb)
{
	char	c;

	if (nb != 0)
	{
		recursion(nb / 10);
		c = nb % 10;
		if (c < 0)
			c *= -1;
		c += '0';
		write(1, &c, 1);
	}
}

static void	recursion_flag(int nb, t_flag *flag)
{
	if (!nb && flag->precision != 0)
		write(1, "0", 1);
	recursion(nb);
}

int	ft_putnbr_flag(int nb, t_flag *flag)
{
	int	counter;
	int	isnegative;

	isnegative = 0;
	if (nb < 0)
		isnegative = 1;
	counter = 0;
	counter += flagslnum(nb, flag, isnegative);
	counter += ft_nblen(nb, flag);
	recursion_flag(nb, flag);
	if (isflag(flag, '-'))
		while (counter < flag->width)
			counter += write(1, " ", 1);
	return (counter);
}
