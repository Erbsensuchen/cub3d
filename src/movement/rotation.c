#include "../../include/header.h"

int	rotate_left(t_game *game)
{
	game->player_rotation -= ROTATION_SPEED;
	if (game->player_rotation < 0)
		game->player_rotation += 2 * M_PI;
	return (0);
}

int	rotate_right(t_game *game)
{
	game->player_rotation += ROTATION_SPEED;
	if (game->player_rotation >= 2 * M_PI)
		game->player_rotation -= 2 * M_PI;
	return (0);
}
