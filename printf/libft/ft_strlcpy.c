/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:02:27 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/15 14:21:05 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	len;
	size_t	counter;

	counter = 0;
	len = ft_strlen(src);
	if (destsize == 0)
		return (len);
	while (counter < destsize - 1 && src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter++;
	}
	if (destsize != 0)
		dest[counter] = '\0';
	return (len);
}
// #include <string.h>

// int main()
// {
// 	char ptr[10];
// 	char ptr2[10];
// 	strlcpy(ptr, "hello !", 0);
// 	ft_strlcpy(ptr2, "hello !", 0);
// 	printf("strlcpy\n%s\nft_strlcpy\n%s\n", ptr, ptr2);
// }