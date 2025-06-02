/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:44 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/11 12:08:45 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')
		|| (letter <= '9' && letter >= '0'))
		return (1);
	return (0);
}

// int main()
// {
// 	return (ft_isalnum('Z'));
// }
