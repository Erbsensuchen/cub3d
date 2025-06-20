/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:36:38 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/20 17:28:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_parsing_error(const char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
}

void	print_parsing_error_line(const char *error_msg, const char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	if (line != NULL)
	{
		ft_putstr_fd("Line: ", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("Line: NULL\n", STDERR_FILENO);
	}
}

bool	filename_valid(const char *scene_path)
{
	int	len;

	if (scene_path == NULL)
		return (false);
	len = ft_strlen(scene_path);
	if (len < 5)
		return (false);
	if (ft_strncmp(scene_path + len - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

bool	is_content_line(char *line)
{
	if (!line)
		return (false);
	line = ft_skip_charset(line, " \t\r\n");
	if (*line == 0)
		return (true);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}
