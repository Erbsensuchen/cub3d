/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:30 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/17 12:31:33 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	size_t	counter;
	size_t	counter2;

	counter2 = 0;
	counter = 0;
	len = ft_strlen(dest) + ft_strlen(src);
	if (destsize < len)
		if (destsize + ft_strlen(src) < len)
			len = destsize + ft_strlen(src);
	if (destsize < ft_strlen(dest) || destsize == 0)
		return (len);
	while (dest[counter] != '\0')
		counter++;
	while (counter < destsize - 1 && src[counter2] != '\0')
	{
		dest[counter] = src[counter2];
		counter++;
		counter2++;
	}
	dest[counter] = '\0';
	return (len);
}

// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	dest[30];
// 	char	*src;

// 	memset(dest, 0, 30);
// 	memset(dest, 'C', 5);
// 	src = (char *)"AAAAAAAAA";
// 	printf("%d", ft_strlcat(dest, src, -1) != 14);
// 	// printf("strlcat:\n%s\nft_strlcat:\n%s\n", buff1, buff2);
// 	return (strcmp(dest, "CCCCCAAAAAAAAA"));
// }
