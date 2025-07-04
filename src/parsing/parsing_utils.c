/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:36:38 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 15:29:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_parsing_error(const char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_parsing_error_line(const char *error_msg, const char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	if (line != NULL)
	{
		ft_putstr_fd("\"", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd("\"\n", STDERR_FILENO);
	}
	else
		ft_putstr_fd("Line: NULL\n", STDERR_FILENO);
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
	line = ft_skip_charset(line, PARSING_SKIP);
	if (*line == 0)
		return (true);
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0
		|| ft_strncmp(line, GOOS_ELEMENT, ft_strlen(GOOS_ELEMENT)) == 0)
		return (true);
	return (false);
}

bool	parse_color(t_color *color, const char *arg)
{
	char	**args;
	int		r;
	int		g;
	int		b;

	args = ft_split(arg, ',');
	if (!args)
		return (print_parsing_error("Memory allocation failed!"), false);
	if (ft_strarr_len(args) != 3)
		return (ft_free_strs(args),
			print_parsing_error_line("Invalid color arg: ", arg), false);
	if (!ft_aisi(args[0]) || !ft_aisi(args[1]) || !ft_aisi(args[2]))
		return (ft_free_strs(args),
			print_parsing_error_line("Color values must be integers: ", arg),
			false);
	r = ft_atoi(args[0]);
	g = ft_atoi(args[1]);
	b = ft_atoi(args[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_free_strs(args),
			print_parsing_error_line("Invalid color values: ", arg), false);
	return (color->r = r, color->g = g, color->b = b,
		color->rgb = color->r << 24 | color->g << 16 | color->b << 8 | 0xFF,
		ft_free_strs(args), true);
}
