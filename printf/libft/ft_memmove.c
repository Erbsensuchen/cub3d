/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:16:16 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/15 12:41:37 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*cdest;
	const char	*csrc;

	if (dest == 0 && src == 0)
		return (0);
	csrc = (const char *)src;
	cdest = (char *)dest;
	if (dest < src + len && dest >= src)
	{
		while (len > 0)
		{
			cdest[len - 1] = csrc[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (cdest);
}
// #include <string.h>

// char		str1[10] = "aabbccdd";
// char		str2[10] = "123456";

// int	main(void)
// {
// 	printf("memcopy:\n");
// 	printf("The string: %s\n", str1);
// 	printf("New string: %s\n", (char*)memmove(str2, str2 + 6, 5));
// 	strcpy(str1, "aabbccdd"); // reset string
// 	strcpy(str2, "123456"); // reset string
// 	printf("ft_memcpy:\n");
// 	printf("The string: %s\n", str1);
// 	printf("New string: %s\n", (char*)ft_memmove(str2, str2 + 6, 5));
// }
