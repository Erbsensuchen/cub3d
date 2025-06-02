/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:57:48 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:59:05 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_nblen(unsigned long long nb, t_flag *flag)
{
	int	counter;

	counter = 0;
	if (!nb && flag->precision != 0)
		return (1);
	while (nb != 0)
	{
		counter++;
		nb = nb / 16;
	}
	return (counter);
}

static int	flagslnum(unsigned long long nb, t_flag *flag)
{
	int	counter;
	int	maxnblen;
	int	counter2;

	counter2 = 2;
	maxnblen = flag->precision;
	if (maxnblen < ft_nblen(nb, flag))
		maxnblen = ft_nblen(nb, flag);
	maxnblen += (isflag(flag, '+') || isflag(flag, ' '));
	counter = 0;
	if (flag->precision != -1 || !isflag(flag, '0'))
		while (maxnblen + counter2 < flag->width && !isflag(flag, '-'))
			counter2 += write(1, " ", 1);
	else if (isflag(flag, '+'))
		counter += write(1, "+", 1);
	else if (isflag(flag, ' '))
		counter += write(1, " ", 1);
	write(1, "0x", 2);
	while ((isflag(flag, '0') && !isflag(flag, '-') && flag->width - counter2
			- counter > ft_nblen(nb, flag)) || maxnblen > ft_nblen(nb, flag)
		+ counter)
		counter += write(1, "0", 1);
	return (counter + counter2);
}

static void	recursion(unsigned long long nb, char *base)
{
	char	c;

	if (nb != 0)
	{
		recursion(nb / 16, base);
		c = nb % 16;
		write(1, base + c, 1);
	}
}

static void	recursion_flag(unsigned long long nb, char *base, t_flag *flag)
{
	if (!nb && flag->precision != 0)
		write(1, "0", 1);
	recursion(nb, base);
}

int	ft_put_ptr_flag(unsigned long long nb, char *base, t_flag *flag)
{
	int	counter;

	counter = 0;
	counter += flagslnum(nb, flag);
	counter += ft_nblen(nb, flag);
	recursion_flag(nb, base, flag);
	if (isflag(flag, '-'))
		while (counter < flag->width)
			counter += write(1, " ", 1);
	return (counter);
}
