/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:56:24 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/15 12:41:30 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		counter;
	char		*cdest;
	const char	*csrc;

	if (dest == 0 && src == 0)
		return (0);
	csrc = (const char *)src;
	cdest = (char *)dest;
	counter = 0;
	while (counter < n)
	{
		cdest[counter] = csrc[counter];
		counter++;
	}
	return (cdest);
}

// int	main(void)
// {
// 	ft_memcpy(0, 0, 5);
// }