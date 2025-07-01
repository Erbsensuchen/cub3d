/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/01 12:17:25 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42/MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# ifndef __USE_MISC // for linux
#  define __USE_MISC
# endif // __USE_MISC
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// debug
# ifndef DEBUG
#  define DEBUG 0
# endif

// base
# define TITLE "Cub3D"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

// movement
# define MOVEMENT_SPEED 0.05
# define ROTATION_SPEED 0.02
# define MOUSE_SENSITIVITY 0.002
# define FOV M_PI_4      // 45 degrees
# define RAY_STEP 0.0002 // Step size for ray casting

// parsing
# define PARSING_SKIP " \t\r\n"
# define MAP_SYMBOLS " 01NSEWD"
# define EMPTY_SYMBOLS " 0"
# define PLAYER_POSITION_SYMBOLS "NSEW"

// minimap
# define MINIMAP_SIZE 0.2f
# define MINIMAP_CELLS_COUNT 10
# define MINIMAP_PLAYER_SIZE 0.015f
# define MINIMAP_PLAYER_WIDTH 0.005f
# define PLAYER_COLOR 0xFF0000FF

// utils
# define DOUBLE_EPSILON 1e-8

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	uint32_t	rgb;
}				t_color;
// color functions
void			print_color(t_color *color);

typedef struct s_texture
{
	char		*path;
	mlx_image_t	*img;
}				t_texture;

// texture functions
void			init_texture(t_texture *texture);
void			free_texture(mlx_t *mlx, t_texture *texture);
void			print_texture(t_texture *texture);

// directions
typedef enum e_wall_dir
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_EAST,
	WALL_WEST,
	WALL_UNKNOWN,
}				t_wall_dir;

typedef struct s_ray
{
	double angle;    // Angle of the ray
	double distance; // Distance to the wall hit
	double hit_x;    // X coordinate of the wall hit
	double		prev_x;
	double		prev_y;
	double hit_y; // Y coordinate of the wall hit
	t_wall_dir	hit_dir;
}				t_ray;

typedef struct s_triangle
{
	double		tip_x;
	double		tip_y;
	double		base_x;
	double		base_y;
	double		left_x;
	double		left_y;
	double		right_x;
	double		right_y;
	double		denom;
	double		a;
	double		b;
	double		c;
	int			px;
	double		py;
	int			min_x;
	int			min_y;
	int			max_x;
	int			max_y;
}				t_triangle;

typedef struct s_game
{
	// MLX
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*old_img;
	bool		capture_mouse;

	// Textures
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;

	// Colors
	t_color		floor;
	t_color		ceiling;

	// Map
	char		**grid;
	int			width;
	int			height;

	// Player
	double		player_x;
	double		player_y;
	double		player_rotation;

	// Movement flags
	bool		forward;
	bool		backward;
	bool		left;
	bool		right;
	bool		rotation_left;
	bool		rotation_right;

	// Movement Vector
	double		mouse_delta_x;
	float		move_x;
	float		move_y;

	// Minimap
	int			mi_size;
	int			mi_cell_size;
	int			mi_player_size;
	int			mi_player_width;
}				t_game;

// game functions
void			init_game(t_game *game);
void			free_game(t_game *game);
void			print_game(t_game *game);
void			print_grid(t_game *game);
void			print_movement(t_game *game);
bool			load_game_textures(t_game *game);

// parsing util functions
void			print_parsing_error(const char *error_msg);
void			print_parsing_error_line(const char *error_msg,
					const char *line);
bool			filename_valid(const char *scene_path);
bool			is_content_line(char *line);
bool			parse_color(t_color *color, const char *arg);

// parsing functions
bool			parse_game(t_game *game, const char *scene_path);
bool			parse_map(t_game *game, int fd, char *last_line);
bool			validate_grid(t_game *game);

// movement functions
bool			move(t_game *game);

// hooks
void			keyhook(mlx_key_data_t keydata, void *param);
void			loophook(void *param);
void			cursorhook(double x, double y, void *param);
void			resize(int width, int height, void *param);
void			mousehook(mouse_key_t keydata, action_t action,
					modifier_key_t mods, void *param);

// minimap
void			print_minimap(t_game *game);
void			draw_player_triangle(t_game *game, int x, int y,
					double angle_rad);

// rendering functions
void			cast_rays(t_game *game);
mlx_image_t		*pre_render(t_game *game);

// angle utils
double			mod_angle(double angle);

// double utils
bool			double_close(double x, double y);

#endif // HEADER_H
