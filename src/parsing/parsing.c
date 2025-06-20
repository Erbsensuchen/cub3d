/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:50 by lseeger           #+#    #+#             */
/*   Updated: 2025/06/20 17:27:45 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	dispatch_content(t_game *game, const char *line)
{
	printf("Dispatching content: %s\n", line);
	return (true);
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
		dispatch_content(game, line);
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
