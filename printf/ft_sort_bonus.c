/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:50:08 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/07 17:01:16 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	sort(const char *str, va_list ap, t_flag *flag)
{
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr_flag(va_arg(ap, int), flag));
	if (*str == 'c')
		return (ft_putchar_flag(va_arg(ap, int), flag));
	if (*str == '%')
		return (ft_putchar_flag('%', flag));
	if (*str == 's')
		return (ft_putstr_flag(va_arg(ap, char *), flag));
	if (*str == 'u')
		return (ft_putunbr_flag(va_arg(ap, unsigned int), flag));
	if (*str == 'x')
		return (ft_puthex_flag(va_arg(ap, unsigned int), "0123456789abcdef",
				flag));
	if (*str == 'X')
		return (ft_puthex_flag(va_arg(ap, unsigned int), "0123456789ABCDEF",
				flag));
	if (*str == 'p')
		return (ft_put_ptr_flag((unsigned long long)va_arg(ap, void *),
				"0123456789abcdef", flag));
	return (0);
}

int	isflag(t_flag *flag, char c)
{
	int	i;

	i = 0;
	while (flag->flags[i])
	{
		if (flag->flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
