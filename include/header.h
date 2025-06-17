/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/06/17 14:35:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42/MLX42.h"
# include <stdbool.h>

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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

typedef struct s_game
{
	// MLX
	void		*mlx;
	void		*win;

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
	double		player_zy;
	double		player_x_rotation;
	double		player_y_rotation;

	// Movement flags
	double		x_movement;
	double		y_movement;
	double		x_rotation;
	double		y_rotation;

	// .cub file path
	char		*scene_path;
}				t_game;

// game functions
void			init_game(t_game *game);
void			free_game(t_game *game);

#endif // HEADER_H
