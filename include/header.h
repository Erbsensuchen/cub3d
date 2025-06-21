/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/21 14:57:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42/MLX42.h"
# include "get_next_line.h"
# include "libft.h"
# ifndef __USE_MISC
#  define __USE_MISC
# endif // __USE_MISC
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define TITLE "Cub3D"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define MOVEMENT_SPEED 0.1
# define ROTATION_SPEED 0.1
# define MOUSE_SENSITIVITY 0.01

# define PARSING_SKIP " \t\r\n"
# define MAP_SYMBOLS "01NSEW"

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;
// color functions
void			print_color(t_color *color);

typedef struct s_texture
{
	char		*path;
	void		*img;
	int			width;
	int			height;
}				t_texture;

// texture functions
void			init_texture(t_texture *texture);
void			free_texture(mlx_t *mlx, t_texture *texture);
void			print_texture(t_texture *texture);

typedef struct s_game
{
	// MLX
	mlx_t		*mlx;

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
	int			forward;
	int			sideways;
	int			rotation;
}				t_game;

// game functions
void			init_game(t_game *game);
void			free_game(t_game *game);
void			print_game(t_game *game);
void			print_grid(t_game *game);

// parsing util functions
void			print_parsing_error(const char *error_msg);
void			print_parsing_error_line(const char *error_msg,
					const char *line);
bool			filename_valid(const char *scene_path);
bool			is_content_line(char *line);
bool			parse_color(t_color *color, const char *arg);

// parsing functions
bool			parse_map(t_game *game, const char *line);
bool			parse_game(t_game *game, const char *scene_path);

// movement functions
int				move_forward(t_game *game);
int				move_backward(t_game *game);
int				move_left(t_game *game);
int				move_right(t_game *game);

// rotation functions
int				rotate_left(t_game *game);
int				rotate_right(t_game *game);

// hooks
void			keyhook(mlx_key_data_t keydata, void *param);
void			loophook(void *param);
void			mouse_rotation(double x, double y, void *param);

#endif // HEADER_H
