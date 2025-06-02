/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:00:49 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:59:43 by mlendle          ###   ########.fr       */
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
		nb = nb / 10;
	}
	return (counter);
}

static int	flagslnum(unsigned int nb, t_flag *flag)
{
	int	counter;
	int	maxnblen;
	int	counter2;

	counter2 = 0;
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
	while ((isflag(flag, '0') && !isflag(flag, '-') && flag->width - counter2
			- counter > ft_nblen(nb, flag)) || maxnblen > ft_nblen(nb, flag)
		+ counter)
		counter += write(1, "0", 1);
	return (counter + counter2);
}

static void	recursion(unsigned int nb)
{
	char	c;

	if (nb != 0)
	{
		recursion(nb / 10);
		c = nb % 10;
		c += '0';
		write(1, &c, 1);
	}
}

static void	recursion_flag(unsigned int nb, t_flag *flag)
{
	if (!nb && flag->precision != 0)
		write(1, "0", 1);
	recursion(nb);
}

int	ft_putunbr_flag(unsigned int nb, t_flag *flag)
{
	int	counter;

	counter = 0;
	counter += flagslnum(nb, flag);
	counter += ft_nblen(nb, flag);
	recursion_flag(nb, flag);
	if (isflag(flag, '-'))
		while (counter < flag->width)
			counter += write(1, " ", 1);
	return (counter);
}
