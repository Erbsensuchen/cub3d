/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:19:52 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/16 12:19:16 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	str_len = ft_strlen(s + start);
	if (len < str_len)
		substr = ft_calloc(len + 1, 1);
	else
		substr = ft_calloc(str_len + 1, 1);
	if (substr == 0)
		return (0);
	while (counter < len && counter < str_len)
	{
		substr[counter] = s[counter + start];
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}

// int main()
// {
// 	printf("%s", ft_substr("asdfghjklqwertyuiop", 5, 19));
// }
