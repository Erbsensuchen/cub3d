/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:40:19 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:59:15 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_nblen(unsigned int nb, t_flag *flag)
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

static void	checkhashtag(unsigned int nb, char base, t_flag *flag)
{
	if (isflag(flag, '#') && base == 'a' && nb != 0)
		write(1, "0x", 2);
	else if (isflag(flag, '#') && base == 'A' && nb != 0)
		write(1, "0X", 2);
}

static int	flagslnum(unsigned int nb, t_flag *flag, char base)
{
	int	counter;
	int	maxnblen;
	int	counter2;

	counter2 = 0;
	if (isflag(flag, '#') && nb != 0)
		counter2 += 2;
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
	checkhashtag(nb, base, flag);
	while ((isflag(flag, '0') && !isflag(flag, '-') && flag->width - counter2
			- counter > ft_nblen(nb, flag)) || maxnblen > ft_nblen(nb, flag)
		+ counter)
		counter += write(1, "0", 1);
	return (counter + counter2);
}

static void	recursion(unsigned int nb, char *base, t_flag *flag)
{
	char	c;

	if (!nb && flag->precision != 0)
		write(1, "0", 1);
	if (nb != 0)
	{
		flag->precision = 0;
		recursion(nb / 16, base, flag);
		c = nb % 16;
		write(1, base + c, 1);
	}
}

int	ft_puthex_flag(unsigned int nb, char *base, t_flag *flag)
{
	int	counter;

	counter = 0;
	counter += flagslnum(nb, flag, base[10]);
	counter += ft_nblen(nb, flag);
	recursion(nb, base, flag);
	if (isflag(flag, '-'))
		while (counter < flag->width)
			counter += write(1, " ", 1);
	return (counter);
}
