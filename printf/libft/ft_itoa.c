/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:38:48 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:49:40 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnblen(int nb)
{
	int	counter;

	counter = 0;
	while (nb != 0)
	{
		counter++;
		nb = nb / 10;
	}
	return (counter);
}

static char	*craftstr(int n, char *str, int nblen, int isnegative)
{
	while (nblen != 0)
	{
		if (isnegative == 1)
			str[nblen - 1] = (n % 10 * -1) + '0';
		else
			str[nblen - 1] = n % 10 + '0';
		n = n / 10;
		nblen--;
	}
	if (isnegative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nblen;
	char	*str;
	int		isnegative;

	if (n == 0)
	{
		str = ft_calloc(2, 1);
		if (str == 0)
			return (0);
		str[0] = '0';
		return (str);
	}
	isnegative = 0;
	if (n < 0)
		isnegative = 1;
	nblen = getnblen(n) + isnegative;
	str = ft_calloc(nblen + 1, 1);
	if (str == 0)
		return (0);
	return (craftstr(n, str, nblen, isnegative));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	printf("%s", ft_itoa(2147483647));
// }
