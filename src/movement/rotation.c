#include "../../include/header.h"

void rotate_left(t_game *game)
{
    game->player_rotation -= 0.1; // Adjust the rotation speed as needed
    if (game->player_rotation < 0)
        game->player_rotation += 2 * M_PI; // Wrap around to keep within [0, 2π]
}

void rotate_right(t_game *game)
{
    game->player_rotation += 0.1; // Adjust the rotation speed as needed
    if (game->player_rotation >= 2 * M_PI)
        game->player_rotation -= 2 * M_PI; // Wrap around to keep within [0, 2π]
}
