/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:16:38 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/14 13:32:37 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspacesahead(const char *str)
{
	int	counter;

	counter = 0;
	while ((str[counter] >= '\t' && str[counter] <= '\r')
		|| str[counter] == ' ')
		counter++;
	return (counter);
}

int	ft_atoi(const char *str)
{
	int	isnegative;
	int	nb;

	nb = 0;
	isnegative = 0;
	str += isspacesahead(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			isnegative = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		if (isnegative)
			nb -= *str - '0';
		else
			nb += *str - '0';
		str++;
	}
	return (nb);
}

// #include "libft.h"

// int	main(void)
// {
// 	printf("%d", ft_atoi("   -2147483648"));
// }