/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:22:26 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/01 14:24:55 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	handle_player_position(t_game *game, int x, int y, char symbol)
{
	game->grid[y][x] = '0';
	game->player_x = x + 0.5;
	game->player_y = y + 0.5;
	if (symbol == 'N')
		game->player_rotation = M_PI / 2;
	else if (symbol == 'S')
		game->player_rotation = -M_PI / 2;
	else if (symbol == 'E')
		game->player_rotation = 0.0;
	else if (symbol == 'W')
		game->player_rotation = M_PI;
}

static bool	set_player_position(t_game *game)
{
	bool	found;
	int		i;
	char	*tmp;

	found = false;
	i = -1;
	while (++i < game->height)
	{
		tmp = ft_strpbrk(game->grid[i], PLAYER_POSITION_SYMBOLS);
		if (tmp)
		{
			if (found)
				return (print_parsing_error("Multiple player positions found!"),
					false);
			found = true;
			handle_player_position(game, tmp - game->grid[i], i, *tmp);
			tmp = ft_strpbrk(tmp + 1, PLAYER_POSITION_SYMBOLS);
			if (tmp)
				return (print_parsing_error("Multiple player positions found!"),
					false);
		}
	}
	if (!found)
		return (print_parsing_error("No player position found!"), false);
	return (true);
}

static bool	is_closed(t_game *game, char **closed, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width)
		return (false);
	if (closed[y][x] == '1' || closed[y][x] == 'V')
		return (true);
	if (closed[y][x] != '0' && closed[y][x] != 'D')
		return (false);
	closed[y][x] = 'V';
	if (!is_closed(game, closed, x + 1, y) || !is_closed(game, closed, x - 1, y)
		|| !is_closed(game, closed, x, y + 1) || !is_closed(game, closed, x, y
			- 1))
		return (false);
	return (true);
}

bool	validate_grid(t_game *game)
{
	char	**closed;

	if (!set_player_position(game))
		return (false);
	closed = ft_strsdup(game->grid);
	if (!closed)
		return (print_parsing_error("Memory allocation failed!"), false);
	if (!is_closed(game, closed, (int)game->player_x, (int)game->player_y))
		return (ft_free_strs(closed),
			print_parsing_error("Map is not enclosed!"), false);
	return (ft_free_strs(closed), true);
}
