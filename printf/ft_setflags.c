/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:33:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/21 11:46:32 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isinflag(char c)
{
	if (c == '0' || c == '-' || c == ' ' || c == '+' || c == '#')
		return (1);
	return (0);
}

static void	initflags(t_flag *flag)
{
	flag->precision = -1;
	flag->width = 0;
}

static char	*ft_strldup(char const *str, int n)
{
	int		strlen;
	int		counter;
	char	*nstr;

	counter = 0;
	strlen = ft_strlen(str);
	if (n > strlen)
		n = strlen;
	nstr = malloc((strlen + 1) * sizeof(char));
	if (!nstr)
		return (0);
	while (counter < n)
	{
		nstr[counter] = str[counter];
		counter++;
	}
	nstr[counter] = 0;
	return (nstr);
}

static int	set_precision(t_flag *flag, int index, va_list ap, const char *str)
{
	int	counter;

	counter = 0;
	if (str[index] == '.')
	{
		counter++;
		index++;
		if (str[index] == '*')
		{
			flag->width = va_arg(ap, int);
			counter++;
		}
		else
		{
			flag->precision = ft_atoi(str + index);
			while (ft_isdigit(str[index]))
			{
				counter++;
				index++;
			}
		}
	}
	return (counter);
}

int	setflags(t_flag *flag, const char *str, va_list ap)
{
	int	counter;

	counter = 0;
	initflags(flag);
	while (isinflag(str[counter]))
		counter++;
	flag->flags = ft_strldup(str, counter);
	if (flag->flags == 0)
		return (-1);
	if (str[counter] == '*')
		flag->width = va_arg(ap, int);
	else if (ft_isdigit(str[counter]))
		flag->width = ft_atoi(str + counter);
	while (ft_isdigit(str[counter]))
		counter++;
	counter += set_precision(flag, counter, ap, str);
	while (ft_isdigit(str[counter]))
		counter++;
	return (counter);
}

// int main()
// {
// 	t_flag *flag= malloc(1 * sizeof(flag));
// 	printf("%i\n", setflags(flag, "f"));
// }
