/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loophook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/27 13:10:21 by lseeger          ###   ########.fr       */
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
		mlx_set_mouse_pos(game->mlx, game->mlx->width / 2, game->mlx->height
			/ 2);
	}
	i = 1;
	i = movment_handler(game);
	if (DEBUG && !i)
		print_game(game);
	game->old_img = game->img;
	game->img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	pre_render(game);
	cast_rays(game);
	print_minimap(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	if (game->old_img)
		mlx_delete_image(game->mlx, game->old_img);
}
