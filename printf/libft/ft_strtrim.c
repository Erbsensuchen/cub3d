/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:54:27 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/16 13:16:59 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	cinsetleft(char const *s1, char const *set)
{
	int	counter;

	counter = 0;
	while (isinset(s1[counter], set))
		counter++;
	return (counter);
}

static int	cinsetright(char const *s1, char const *set)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	counter2 = 0;
	while (s1[counter1] != '\0')
	{
		counter1++;
	}
	counter1--;
	while (isinset(s1[counter1], set))
	{
		counter2++;
		counter1--;
	}
	return (counter2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		lstrip;
	int		rstrip;
	int		counter;

	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	counter = 0;
	lstrip = cinsetleft(s1, set);
	rstrip = cinsetright(s1, set);
	if ((int)ft_strlen(s1) - lstrip - rstrip < 1)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	str = ft_calloc(ft_strlen(s1) - lstrip - rstrip + 1, 1);
	if (str == 0)
		return (str);
	while (lstrip + counter < (int)ft_strlen(s1) - rstrip)
	{
		str[counter] = s1[lstrip + counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

// int	main(void)
// {
// 	ft_strtrim("", "");
// }
