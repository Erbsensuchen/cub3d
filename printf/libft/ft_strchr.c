/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:52:02 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/17 16:33:56 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == (char)c)
			return ((char *)str + counter);
		counter++;
	}
	if (str[counter] == (char)c)
		return ((char *)str + counter);
	return (0);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strchr("asdfghkl", '\0');
// 	printf("%s", str);
// }
