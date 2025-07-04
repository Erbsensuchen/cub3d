/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_goose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:44:51 by lseeger           #+#    #+#             */
/*   Updated: 2025/07/04 18:16:46 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_state(t_game *game, int i)
{
	game->goose_states[i] = lcg_rand_max(GOOSE_STATE_COUNT);
	game->goose_target_x[i] = game->goose_pos_x[i];
	game->goose_target_y[i] = game->goose_pos_y[i];
	game->goose_times[i] = 0;
	game->goose_anim_frame[i] = 0;
	if (game->goose_states[i] == GOOSE_SIT)
	{
		game->goose_times[i] = GOOSE_SIT_TIME;
		game->goose_anim_count[i] = GOOSE_SIT_ANIM_FRAMES;
	}
	else if (game->goose_states[i] == GOOSE_WALK)
	{
		game->goose_target_x[i] = lcg_rand_max(game->mlx->width);
		game->goose_target_y[i] = lcg_rand_max(game->mlx->height);
		game->goose_anim_count[i] = GOOSE_WALK_ANIM_FRAMES;
	}
}

static void	update_goose_animation(t_game *game)
{
	int	i;

	game->goose_anim_wait++;
	if (game->goose_anim_wait < GOOSE_ANIMATION_WAIT)
		return ;
	game->goose_anim_wait = 0;
	i = 0;
	while (i < GOOSE_COUNT)
	{
		game->goose_anim_frame[i]++;
		if (game->goose_anim_frame[i] >= game->goose_anim_count[i])
			game->goose_anim_frame[i] = 0;
		i++;
	}
}

void	update_goose(t_game *game)
{
	int	i;

	update_goose_animation(game);
	i = 0;
	while (i < GOOSE_COUNT)
	{
		if (game->goose_times[i] <= 0 && ft_distance(game->goose_pos_x[i],
				game->goose_pos_y[i], game->goose_target_x[i],
				game->goose_target_y[i]) < GOOSE_DISTANCE)
			update_state(game, i);
		else
		{
			if (game->goose_pos_x[i] < game->goose_target_x[i])
				game->goose_pos_x[i] += GOOSE_SPEED;
			else if (game->goose_pos_x[i] > game->goose_target_x[i])
				game->goose_pos_x[i] -= GOOSE_SPEED;
			if (game->goose_pos_y[i] < game->goose_target_y[i])
				game->goose_pos_y[i] += GOOSE_SPEED;
			else if (game->goose_pos_y[i] > game->goose_target_y[i])
				game->goose_pos_y[i] -= GOOSE_SPEED;
			else if (game->goose_times[i] > 0)
				game->goose_times[i]--;
		}
		i++;
	}
}
