/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:50 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/20 18:23:02 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	handle_args(t_game *game, char **args)
{
	char	**path;

	if (ft_strcmp(args[0], "F") == 0)
		return (parse_color(&game->floor, args[1]));
	else if (ft_strcmp(args[0], "C") == 0)
		return (parse_color(&game->ceiling, args[1]));
	if (ft_strcmp(args[0], "NO") == 0)
		path = &game->north.path;
	else if (ft_strcmp(args[0], "SO") == 0)
		path = &game->south.path;
	else if (ft_strcmp(args[0], "EA") == 0)
		path = &game->east.path;
	else if (ft_strcmp(args[0], "WE") == 0)
		path = &game->west.path;
	else
		return (true);
	if (*path)
		return (print_parsing_error_line("Duplicate Texture: ", args[0]),
			false);
	*path = ft_strdup(args[1]);
	if (!*path)
		return (print_parsing_error("Memory allocation failed!\n"), false);
	return (true);
}

bool	dispatch_content(t_game *game, const char *line)
{
	char	**args;
	int		len;

	args = ft_split_charset(line, PARSING_SKIP);
	if (!args)
		return (print_parsing_error("Memory allocation failed!\n"), false);
	len = ft_strarr_len(args);
	if (len == 0)
		return (ft_free_strs(args), true);
	if (len != 2)
		return (ft_free_strs(args),
			print_parsing_error_line("Invalid content: ", line), false);
	if (!handle_args(game, args))
		return (ft_free_strs(args), false);
	return (ft_free_strs(args), true);
}

bool	parse_content(t_game *game, const char *scene_path)
{
	int		fd;
	char	*line;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (print_parsing_error("Could not open file!\n"), false);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), print_parsing_error("File is empty!\n"), false);
	while (is_content_line(line))
	{
		if (!dispatch_content(game, line))
			return (close(fd), free(line), false);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (close(fd), print_parsing_error("No Map found!\n"), false);
	}
	return (close(fd), true);
}

bool	parse_game(t_game *game, const char *scene_path)
{
	if (!filename_valid(scene_path))
		return (print_parsing_error("Files need to End with .cub!\n"), false);
	if (!parse_content(game, scene_path))
		return (false);
	if (!parse_map(game, scene_path))
		return (false);
	return (true);
}
