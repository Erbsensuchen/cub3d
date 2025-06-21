/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:30:43 by hello_x           #+#    #+#             */
/*   Updated: 2025/06/21 15:58:42 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_str;
	const int	s_len = ft_strlen(s);

	new_str = malloc(sizeof(char) * (s_len) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, s_len + 1);
	return (new_str);
}

char	*ft_strndup(char *src, char *next)
{
	const int	dest_len = next - src;
	char		*dest;
	int			i;

	dest = malloc(dest_len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_create_terminated_str(int len)
{
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (result);
}

char	*ft_create_filled_str(char *str, int len, char fill_char)
{
	char	*result;
	int		i;
	int		str_len;
	int		final_len;

	str_len = ft_strlen(str);
	if (len > str_len)
		final_len = len;
	else
		final_len = str_len;
	result = ft_create_terminated_str(final_len);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < str_len)
		result[i] = str[i];
	while (i < final_len)
		result[i++] = fill_char;
	return (result);
}
