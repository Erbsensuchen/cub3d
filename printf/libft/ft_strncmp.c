/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:25:23 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/16 13:25:04 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (str1[counter] == str2[counter] && counter < n)
	{
		if (str1[counter] == '\0')
			return (0);
		counter++;
	}
	if (n == 0 || counter == n)
	{
		return (0);
	}
	return ((unsigned char)str1[counter] - (unsigned char)str2[counter]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%i", ft_strncmp("", "", 1));
// }
