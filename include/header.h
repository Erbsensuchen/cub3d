#ifndef HEADER_H
#define HEADER_H

# include <stdbool.h>

typedef struct s_color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_texture
{
	char *path;
	void *img;
	char *addr;
	int width;
	int height;
}	t_texture;

typedef struct s_game
{
	// MLX
	void *mlx;
	void *win;

	// Textures
	t_texture north;
	t_texture south;
	t_texture east;
	t_texture west;

	// Colors
	t_color floor;
	t_color ceiling;

	// Map
	char **grid;
	int width;
	int height;

	// Player
	double player_x;
	double player_zy;
	double player_x_rotation;
	double player_y_rotation;

	// Movement flags
	double x_movement;
    double y_movement;
	double x_rotation;
	double y_rotation;

	// .cub file path
	char *scene_path;
}	t_game;

#endif // HEADER_H
