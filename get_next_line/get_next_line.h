/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:13 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 14:24:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// Handle Functions
char	*get_next_line(int fd);

// Utility Functions
char	*get_next_nl(char *s);
char	*rstr(const char *s, size_t *nl_r_len);
bool	buffer_join(char **nl, char const *buffer, size_t *nl_r_len);
size_t	local_strlen(const char *s);
void	*local_memmove(void *dst, const void *src, size_t len);

#endif
