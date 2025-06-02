/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:55:55 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/25 17:34:33 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_flag(char c, t_flag *flag)
{
	int	counter;

	counter = 0;
	if (isflag(flag, '-'))
	{
		write(1, &c, 1);
		while (counter < flag->width - 1)
			counter += write(1, " ", 1);
	}
	else
	{
		while (counter < flag->width -1)
		{
			counter += write(1, " ", 1);
		}
		write(1, &c, 1);
	}
	return (counter + 1);
}

int	ft_putstr_flag(char *str, t_flag *flag)
{
	int	strlen;
	int	counter;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	counter = 0;
	if (flag->precision >= 0 && strlen > flag->precision)
		strlen = flag->precision;
	if (isflag(flag, '-'))
	{
		counter += write(1, str, strlen);
		while (counter < flag->width)
			counter += write(1, " ", 1);
	}
	else
	{
		while (strlen + counter < flag->width)
			counter += write(1, " ", 1);
		counter += write(1, str, strlen);
	}
	return (counter);
}
