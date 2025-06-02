/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:39:47 by mlendle           #+#    #+#             */
/*   Updated: 2025/01/14 12:49:00 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		*(char *)s = 0;
		s++;
		counter++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// #include <unistd.h>

// int main()
// {
// 	char * ptr = ft_calloc(100, 1);
// 	// char *ptr = "qpasdklzxcvbnm,";
// 	// ft_bzero((void*)ptr, 100);

// 	write(1, ptr, 100);
// }
