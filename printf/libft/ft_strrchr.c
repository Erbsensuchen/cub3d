/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:05:40 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/17 16:32:22 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len != -1)
	{
		if (str[len] == (char)c)
			return ((char *)str + len);
		len--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strrchr("123456789", 'e');
// 	printf("%s", str);
// }
