/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:42:32 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/06 15:18:32 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort(const char *str, va_list ap, t_flag *flag)
{
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (*str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*str == '%')
		return (ft_putchar('%'));
	if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*str == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (*str == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (*str == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (*str == 'p')
		return (ft_put_ptr((unsigned long long)va_arg(ap, void *),
				"0123456789abcdef"));
	return (0);
	flag->flags = "";
}
