/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/18 13:42:29 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	movment_handler(t_game *game)
{
	int	i;

	i = 0;
	if (game->forward == -1)
		i = move_backward(game);
	if (game->forward == 1)
		i = move_forward(game);
	if (game->sideways == -1)
		i = move_left(game);
	if (game->sideways == 1)
		i = move_right(game);
	if (game->rotation == -1)
		i = rotate_left(game);
	if (game->rotation == 1)
		i = rotate_right(game);
	return (i);
}

void	loophook(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	i = 0;
	i = movment_handler(game);
	if (DEBUG && i)
		print_game(game);
}
