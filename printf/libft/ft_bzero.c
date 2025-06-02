/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:32:41 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/14 14:25:31 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char *)s;
	counter = 0;
	while (counter < n)
	{
		*ptr = 0;
		ptr++;
		counter++;
	}
}

// #include <unistd.h>

// int	main(void)
// {
// 	char	*s;

// 	s = "qpasdklzxcvbnm";
// 	ft_bzero(s, 14);
// 	write(1, s, 15);
// }
