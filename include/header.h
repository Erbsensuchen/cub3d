/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/27 14:06:32 by lseeger          ###   ########.fr       */
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
# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.04
# define MOUSE_SENSITIVITY 0.002
# define FOV M_PI_4      // 45 degrees
# define RAY_STEP 0.0002 // Step size for ray casting

// parsing
# define PARSING_SKIP " \t\r\n"
# define MAP_SYMBOLS " 01NSEW"
# define EMPTY_SYMBOLS " 0"
# define PLAYER_POSITION_SYMBOLS "NSEW"

// minimap
# define MINIMAP_SIZE 0.1f
# define MINIMAP_CELLS_COUNT 10

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

typedef struct s_ray
{
	double angle;    // Angle of the ray
	double distance; // Distance to the wall hit
	double hit_x;    // X coordinate of the wall hit
	double hit_y;    // Y coordinate of the wall hit
}				t_ray;

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

	// Minimap
	int			mi_size;
	int			mi_cell_size;
}				t_game;

// game functions
void			init_game(t_game *game);
void			free_game(t_game *game);
void			print_game(t_game *game);
void			print_grid(t_game *game);
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
int				move_forward(t_game *game);
int				move_backward(t_game *game);
int				move_left(t_game *game);
int				move_right(t_game *game);
int				test_movement(t_game *game, double new_x, double new_y);

// rotation functions
int				rotate_left(t_game *game);
int				rotate_right(t_game *game);

// hooks
void			keyhook(mlx_key_data_t keydata, void *param);
void			loophook(void *param);
void			cursorhook(double x, double y, void *param);
void			resize(int width, int height, void *param);

// minimap
void			print_minimap(t_game *game);

// rendering functions
void			cast_rays(t_game *game);
mlx_image_t		*pre_render(t_game *game);

// utils
double			mod_angle(double angle);

#endif // HEADER_H
