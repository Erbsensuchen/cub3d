/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:28:58 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/11 13:26:30 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			counter;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (str1[counter] != str2[counter])
		{
			return (str1[counter] - str2[counter]);
		}
		counter++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%i", ft_memcmp("moin", "moinm", 4));
// }
