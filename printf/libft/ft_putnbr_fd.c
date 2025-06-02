/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:10:04 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/14 11:08:51 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursion(int nb, int fd)
{
	int	i;

	if (nb != 0)
	{
		recursion(nb / 10, fd);
		i = nb % 10 + '0';
		write(fd, &i, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(fd, "0", 1);
	recursion(n, fd);
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	fd;

// 	fd = open("test", O_WRONLY);
// 	ft_putnbr_fd(0, fd);
// 	close(fd);
// }
