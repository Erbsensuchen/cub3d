/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_goose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:41:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/07 19:15:36 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_pixel_if_visible(t_game *game, t_render_context *ctx)
{
	if (ctx->screen_x >= 0 && ctx->screen_x < (int)game->img->width
		&& ctx->screen_y >= 0 && ctx->screen_y < (int)game->img->height)
	{
		mlx_put_pixel(game->img, ctx->screen_x, ctx->screen_y, ctx->color);
	}
}

static void	render(t_game *game, int i, int anim_row)
{
	int					y;
	int					x;
	t_render_context	ctx;

	ctx.tex = game->goose.tex;
	ctx.pixels = (uint32_t *)ctx.tex->pixels;
	ctx.tex_width = ctx.tex->width;
	ctx.src_x = game->goose_anim_frame[i] * GOOSE_ANIMATION_SIZE;
	ctx.src_y = anim_row * GOOSE_ANIMATION_SIZE;
	y = -1;
	while (++y < GOOSE_ANIMATION_SIZE)
	{
		x = -1;
		while (++x < GOOSE_ANIMATION_SIZE)
		{
			ctx.color = ctx.pixels[(ctx.src_y + y) * ctx.tex_width + (ctx.src_x
					+ x)];
			if ((ctx.color >> 24) == 0)
				continue ;
			ctx.screen_x = game->goose_pos_x[i] - GOOSE_ANIMATION_SIZE / 2 + x;
			ctx.screen_y = game->goose_pos_y[i] - GOOSE_ANIMATION_SIZE / 2 + y;
			put_pixel_if_visible(game, &ctx);
		}
	}
}

void	render_goose(t_game *game)
{
	int	anim_row;
	int	i;

	i = 0;
	while (i < GOOSE_COUNT)
	{
		if (game->goose_states[i] == GOOSE_SIT)
			anim_row = GOOSE_SIT_ANIM;
		else if (game->goose_states[i] == GOOSE_WALK)
			anim_row = GOOSE_WALK_ANIM;
		else
			anim_row = 0;
		render(game, i, anim_row);
		i++;
	}
}
