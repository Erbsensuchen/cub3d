/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:50 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 19:28:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	get_texture_path_pointer(t_game *game, char *id, char ***out_path)
{
	if (ft_strcmp(id, "NO") == 0)
		*out_path = &game->north.path;
	else if (ft_strcmp(id, "SO") == 0)
		*out_path = &game->south.path;
	else if (ft_strcmp(id, "EA") == 0)
		*out_path = &game->east.path;
	else if (ft_strcmp(id, "WE") == 0)
		*out_path = &game->west.path;
	else if (ft_strcmp(id, GOOSE_ELEMENT) == 0)
		*out_path = &game->goose.path;
	else if (ft_strcmp(id, DOOR_OPEN_ELEMENT) == 0)
		*out_path = &game->door_open_texture.path;
	else if (ft_strcmp(id, DOOR_CLOSE_ELEMENT) == 0)
		*out_path = &game->door_close_texture.path;
	else
		return (false);
	return (true);
}

static bool	handle_args(t_game *game, char **args)
{
	char	**path;

	if (ft_strcmp(args[0], "F") == 0)
		return (parse_color(&game->floor, args[1]));
	else if (ft_strcmp(args[0], "C") == 0)
		return (parse_color(&game->ceiling, args[1]));
	if (!get_texture_path_pointer(game, args[0], &path))
		return (true);
	if (*path)
		return (print_parsing_error_line("Duplicate Texture: ", args[0]),
			false);
	*path = ft_strdup(args[1]);
	if (!*path)
		return (print_parsing_error("Memory allocation failed!"), false);
	return (true);
}

static bool	dispatch_content(t_game *game, const char *line)
{
	char	**args;
	int		len;

	args = ft_split_charset(line, PARSING_SKIP);
	if (!args)
		return (print_parsing_error("Memory allocation failed!"), false);
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

static bool	parse_content(t_game *game, int fd, char **last_line)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (print_parsing_error("File is empty!"), false);
	while (is_content_line(line))
	{
		if (!dispatch_content(game, line))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (print_parsing_error("No Map found!"), false);
	}
	*last_line = line;
	return (true);
}

bool	parse_game(t_game *game, const char *scene_path)
{
	int		fd;
	char	*last_line;

	if (!filename_valid(scene_path))
		return (print_parsing_error("Files need to End with .cub!"), false);
	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (print_parsing_error("Could not open file!"), false);
	if (!parse_content(game, fd, &last_line))
		return (close(fd), false);
	if (!parse_map(game, fd, last_line))
		return (close(fd), false);
	return (close(fd), true);
}
