/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/23 12:46:23 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	movment_handler(t_game *game)
{
	int	i;

	i = 1;
	if (game->forward == 1)
		i = move_forward(game);
	if (game->backward == 1)
		i = move_backward(game);
	if (game->left == 1)
		i = move_left(game);
	if (game->right == 1)
		i = move_right(game);
	if (game->rotation_left == 1)
		i = rotate_left(game);
	if (game->rotation_right == 1)
		i = rotate_right(game);
	return (i);
}

void	loophook(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	if (game->capture_mouse)
	{
        mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
    }
	i = 1;
	i = movment_handler(game);
	if (DEBUG && !i)
		print_game(game);
}
