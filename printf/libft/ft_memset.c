/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:22:33 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/14 11:00:29 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)b;
	counter = 0;
	while (counter < len)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (ptr);
}

// #include <unistd.h>

// int	main(void)
// {
// 	int	buffer[100];

// 	ft_memset(buffer, 'a', 100);
// 	write(1, buffer, 100);
// 	return (0);
// }
