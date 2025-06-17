/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 15:59:42 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42/MLX42.h"
# include "libft.h"
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
	double player_rotation; // in radians, 0 / 2*PI means forward
	// Movement flags
	double		x_movement;
	double		y_movement;
	double		x_rotation;
	double		y_rotation;
}				t_game;

// game functions
void			init_game(t_game *game);
void			free_game(t_game *game);
void			print_game(t_game *game);
void			print_grid(t_game *game);

// parsing functions
bool			scene_valid(const char *scene_path);
bool			parse_game(t_game *game, const char *scene_path);

// movement functions
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);

// rotation functions
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);

// hooks
void			keyhook(mlx_key_data_t keydata, void *param);

#endif // HEADER_H
