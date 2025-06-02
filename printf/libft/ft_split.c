/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:30:50 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/16 11:16:59 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	getwordamount(const char *s, char c)
{
	int	newword;
	int	counter;

	newword = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c)
			newword = 1;
		if (*s == c && newword == 1)
		{
			newword = 0;
			counter++;
		}
		s++;
	}
	return (counter + newword);
}

static char	*getword(char const *s, char c, int index)
{
	char	*str;
	int		counter;

	counter = 0;
	while (*s == c)
		s++;
	while (index != 0)
	{
		s++;
		if (*s != c && *(s - 1) == c)
			index--;
	}
	while (s[counter] != '\0' && s[counter] != c)
		counter++;
	str = malloc(counter + 1);
	if (str == 0)
		return (0);
	counter = 0;
	while (s[counter] != '\0' && s[counter] != c)
	{
		str[counter] = s[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**res;
	int		wordamount;

	wordamount = getwordamount(s, c);
	wordcount = 0;
	res = malloc(8 * (wordamount + 1));
	if (res == 0)
		return (0);
	while (wordcount < wordamount)
	{
		res[wordcount] = getword(s, c, wordcount);
		if (res[wordcount] == 0)
			return (0);
		wordcount++;
	}
	res[wordcount] = 0;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "olol                     ";
// 	char **result = ft_split(s, ' ');
// 	printf("%s", result[0]);
// 	return (0);
// }
