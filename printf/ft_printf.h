/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:15:32 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/06 15:18:38 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	char	*flags;
	int		precision;
	int		width;
}			t_flag;

int			ft_printf(const char *str, ...);
int			sort(const char *str, va_list ap, t_flag *flag);
int			ft_putnbr(int n);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putunbr(unsigned int nb);
int			ft_puthex(long long nb, char *base);
int			ft_nblen_base(unsigned long long nb, char *base);
void		write_nb_base(long long nb, int index, char *base);
int			ft_put_ptr(unsigned long long n, char *base);
int			setflags(t_flag *flag, const char *str, va_list ap);
int			setflags(t_flag *flag, const char *str, va_list ap);
#endif