/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:41:35 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/16 12:43:43 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_the_str(const char *test_haystack, const char *test_needle)
{
	while (*test_haystack == *test_needle)
	{
		test_needle++;
		test_haystack++;
		if (*test_needle == '\0')
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		counter;
	const char	*test_haystack;
	const char	*test_needle;
	size_t		len_needle;

	len_needle = ft_strlen(needle);
	counter = 0;
	if (len_needle == 0)
		return ((char *)haystack);
	while (counter < len)
	{
		test_haystack = haystack;
		test_needle = needle;
		if (check_the_str(test_haystack, test_needle))
		{
			if (counter + len_needle > len || *haystack == '\0')
				return (0);
			return ((char *)haystack);
		}
		if (counter + len_needle > len || *haystack == '\0')
			return (0);
		counter++;
		haystack++;
	}
	return (0);
}

// int	main(void)
// {
// 	ft_strnstr("", "teste", 2);
// }
