/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:33:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 15:11:55 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*skip_content(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (is_content_line(line))
	{
		printf("Skipping content line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static bool	valid_map_line(char *line)
{
	if (line == ft_strchr(line, '\n'))
		return (false);
	line = ft_skip_charset(line, MAP_SYMBOLS);
	if (*line != '\n')
		return (false);
	else
		return (true);
}

static t_list	*get_map(int fd, char *line)
{
	t_list	*new;
	t_list	*map;

	map = NULL;
	while (line && valid_map_line(line))
	{
		printf("Parsing map line: %s", line);
		new = ft_lstnew(line);
		if (!new)
			return (free(line), ft_lstclear(&map, free),
				print_parsing_error("Memory allocation failed!\n"), NULL);
		ft_lstadd_back(&map, new);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

bool	parse_map(t_game *game, const char *scene_path)
{
	char	*line;
	int		fd;
	t_list	*map;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (print_parsing_error("Could not open file!\n"), false);
	line = skip_content(fd);
	map = get_map(fd, line);
	if (!map)
		return (close(fd), false);
	while (map)
	{
		printf("Map line: %s", (char *)map->content);
		map = map->next;
	}
	return (close(fd), ft_lstclear(&map, free), true);
}
