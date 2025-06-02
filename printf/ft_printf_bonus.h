/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:59:41 by mlendle           #+#    #+#             */
/*   Updated: 2024/11/07 17:09:11 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "ft_printf.h"
# include <stdio.h>

int	ft_putchar_flag(char c, t_flag *flag);
int	ft_putnbr_flag(int nb, t_flag *flag);
int	ft_putstr_flag(char *str, t_flag *flag);
int	isflag(t_flag *flag, char c);
int	ft_putunbr_flag(unsigned int nb, t_flag *flag);
int	ft_puthex_flag(unsigned int nb, char *base, t_flag *flag);
int	ft_put_ptr_flag(unsigned long long ptr, char *base, t_flag *flag);

#endif
