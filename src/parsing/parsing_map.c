/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:33:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/08 12:59:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	valid_map_line(char *line)
{
	if (line == ft_strchr(line, '\n'))
		return (false);
	line = ft_skip_charset(line, MAP_SYMBOLS);
	if (*line != '\n' && *line != '\0')
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
		new = ft_lstnew(line);
		if (!new)
			return (free(line), ft_lstclear(&map, free),
				print_parsing_error("Memory allocation failed!"), NULL);
		ft_lstadd_back(&map, new);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (*ft_skip_charset(line, PARSING_SKIP) != 0)
			return (ft_lstclear(&map, free),
				print_parsing_error_line("Invalid Map Line: ", line),
				free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

static int	get_map_width(t_list *map)
{
	int	current;
	int	max;

	max = 0;
	while (map && map->content)
	{
		ft_remove_c(map->content, "\n");
		current = ft_strlen(map->content);
		if (current > max)
			max = current;
		map = map->next;
	}
	return (max);
}

static bool	map_to_grid(t_game *game, t_list *map)
{
	int	i;

	game->width = get_map_width(map);
	if (game->width == 0)
		return (print_parsing_error("Map Width is 0!"), false);
	game->height = ft_lstsize(map);
	if (game->height == 0)
		return (print_parsing_error("Map Height is 0!"), false);
	game->grid = malloc((game->height + 1) * sizeof(char *));
	if (!game->grid)
		return (print_parsing_error("Memory allocation failed!"), false);
	i = 0;
	while (i < game->height)
	{
		if (!map || !map->content)
			return (ft_free_strs_partial(game->grid, i), game->grid = NULL,
				print_parsing_error("Map is incomplete!"), false);
		game->grid[i] = ft_create_filled_str(map->content, game->width, ' ');
		if (!game->grid[i])
			return (ft_free_strs_partial(game->grid, i), game->grid = NULL,
				print_parsing_error("Memory allocation failed!"), false);
		i++;
		map = map->next;
	}
	return (game->grid[game->height] = NULL, true);
}

bool	parse_map(t_game *game, int fd, char *last_line)
{
	t_list	*map;

	map = get_map(fd, last_line);
	if (!map)
		return (false);
	if (!map_to_grid(game, map))
		return (ft_lstclear(&map, free), false);
	if (!validate_grid(game))
		return (ft_lstclear(&map, free), false);
	return (ft_lstclear(&map, free), true);
}
