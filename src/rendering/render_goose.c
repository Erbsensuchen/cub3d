/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_goose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 18:11:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	render(t_game *game, int dst_x, int dst_y, int anim_row, int frame)
{
	mlx_texture_t	*tex;
	uint32_t		*pixels;
	int				tex_width;
	int				src_x;
	int				src_y;
	uint32_t		color;
	int				screen_x;
	int				screen_y;

	tex = game->goose.tex;
	pixels = (uint32_t *)tex->pixels;
	tex_width = tex->width;
	src_x = frame * GOOSE_ANIMATION_SIZE;
	src_y = anim_row * GOOSE_ANIMATION_SIZE;
	for (int y = 0; y < GOOSE_ANIMATION_SIZE; y++)
	{
		for (int x = 0; x < GOOSE_ANIMATION_SIZE; x++)
		{
			color = pixels[(src_y + y) * tex_width + (src_x + x)];
			if ((color >> 24) == 0)
				continue ;
			screen_x = dst_x + x;
			screen_y = dst_y + y;
			if (screen_x >= 0 && screen_x < (int)game->img->width
				&& screen_y >= 0 && screen_y < (int)game->img->height)
			{
				mlx_put_pixel(game->img, screen_x, screen_y, color);
			}
		}
	}
}

void	render_goose(t_game *game)
{
	int	i;

	i = 0;
	while (i < GOOSE_COUNT)
	{
		render(game, game->goose_pos_x[i] - GOOSE_ANIMATION_SIZE / 2,
			game->goose_pos_y[i] - GOOSE_ANIMATION_SIZE / 2, 7,
			game->goose_anim_frame[i]);
		i++;
	}
}
