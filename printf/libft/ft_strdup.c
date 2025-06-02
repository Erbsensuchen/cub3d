/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:59:39 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/15 15:28:02 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	size_t	len;
	char	*str2;
	size_t	counter;

	counter = 0;
	len = ft_strlen(str1);
	str2 = malloc(len + 1);
	if (str2 == 0)
		return (0);
	while (counter <= len)
	{
		str2[counter] = str1[counter];
		counter++;
	}
	return (str2);
}

// int	main(void)
// {
// 	printf("%s", ft_strdup("servus"));
// }
