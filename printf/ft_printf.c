/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:09:17 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/13 15:00:14 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printwrite(t_flag *flag, const char *str, va_list ap, int counter)
{
	int	i;
	int	flaglen;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			flaglen = setflags(flag, str + i, ap);
			if (flaglen == -1)
				return (-1);
			i += flaglen;
			counter += sort(str + i, ap, flag);
			free(flag->flags);
		}
		else
		{
			write(1, &str[i], 1);
			counter++;
		}
		i++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	t_flag	*flag;

	flag = ft_calloc(1, sizeof(t_flag));
	if (flag == NULL)
		return (-1);
	va_start(ap, str);
	i = ft_printwrite(flag, str, ap, 0);
	va_end(ap);
	free(flag);
	if (i == -1)
		return (-1);
	return (i);
}
