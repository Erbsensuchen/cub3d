/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:51:35 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/11 13:13:30 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (str[counter] == (unsigned char)c)
		{
			return (str + counter);
		}
		counter++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%s", (char *)ft_memchr("asdfghjklqwertyuiop", '0', 18));
// }