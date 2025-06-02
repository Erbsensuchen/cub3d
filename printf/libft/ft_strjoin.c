/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:38:14 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/10 16:54:53 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	counter;

	counter = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (str == 0)
		return (0);
	while (counter < len)
	{
		if (*s1 != '\0')
		{
			str[counter] = *s1;
			s1++;
		}
		else
		{
			str[counter] = *s2;
			s2++;
		}
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_strjoin("12345", "67890"));
// }