/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:33:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/21 15:30:04 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

bool	parse_map(t_game *game, int fd, char *last_line)
{
	t_list	*map;

	map = get_map(fd, last_line);
	if (!map)
		return (false);
	// debug print
	while (map)
	{
		printf("Map line: %s", (char *)map->content);
		map = map->next;
	}
	return (ft_lstclear(&map, free), true);
}
