/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:58:15 by mlendle           #+#    #+#             */
/*   Updated: 2025/07/07 18:51:54 by lseeger          ###   ########.fr       */
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
# include <stdint.h>
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
# define MOVEMENT_SPEED 2
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
# define MINIMAP_WALL_COLOR 0xFFFFFFFF
# define MINIMAP_DOOR_CLOSE_COLOR 0x303030ff
# define MINIMAP_DOOR_OPEN_COLOR 0x008080ff

// rendering
# define RENDERING_ERROR 0xFF00FFFF         // pinkish
# define RENDERING_OUT_OF_BOUNDS 0xFFFF00FF // yellow

// door
# define DOOR_REACHABLE_DISTANCE 1
# define OPEN_DOOR_PATH "textures/door_open.png"
# define CLOSE_DOOR_PATH "textures/door_close.png"

// utils
# define DOUBLE_EPSILON 1e-8

// goose
# define GOOSE_SEED 42
# define GOOSE_ELEMENT "GO"
# define GOOSE_COUNT 100
# define GOOSE_SPEED 1
# define GOOSE_DISTANCE 10
# define GOOSE_SIT_TIME 1000

// goose animations
# define GOOSE_ANIM_WAIT_SIT 75
# define GOOSE_ANIM_WAIT_WALK 20
# define GOOSE_ANIMATION_SIZE 32
# define GOOSE_SIT_ANIM 7
# define GOOSE_SIT_ANIM_FRAMES 4
# define GOOSE_WALK_ANIM 6
# define GOOSE_WALK_ANIM_FRAMES 4

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	uint32_t		rgb;
}					t_color;
// color functions
void				print_color(t_color *color);

typedef struct s_texture
{
	char			*path;
	xpm_t			*xpmt;
	mlx_texture_t	*tex;
}					t_texture;

// texture functions
void				init_texture(t_texture *texture);
void				free_texture(t_texture *texture);
void				print_texture(t_texture *texture);
uint32_t			get_pixel_color(mlx_texture_t *texture, int x, int y);

// directions
typedef enum e_wall_dir
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_EAST,
	WALL_WEST,
	WALL_UNKNOWN,
}					t_wall_dir;

// goose state
typedef enum e_goose_state
{
	GOOSE_SIT = 0,
	GOOSE_WALK = 1,
	GOOSE_JUMP = 2,
	GOOSE_LOOK = 3,
	GOOSE_FLAP = 4,
	GOOSE_FLY = 5,
	GOOSE_SLEEP = 6,
	GOOSE_EAT = 7,
}					t_goose_state;
# define GOOSE_STATE_COUNT 2

typedef struct s_ray
{
	double			x;
	double			y;
	double			c_d;
	double			angle;
	double			distance;
	double			hit_x;
	double			prev_x;
	double			prev_y;
	double			hit_y;
	t_wall_dir		hit_dir;
	double			door_hit_x;
	double			door_hit_y;
	double			door_d;
	bool			door_open;
	t_wall_dir		door_dir;
}					t_ray;

typedef struct s_triangle
{
	double			tip_x;
	double			tip_y;
	double			base_x;
	double			base_y;
	double			left_x;
	double			left_y;
	double			right_x;
	double			right_y;
	double			denom;
	double			a;
	double			b;
	double			c;
	int				px;
	double			py;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
}					t_triangle;

typedef struct s_box
{
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_box;

typedef struct s_iter
{
	int				i;
	int				j;
}					t_iter;

typedef struct s_game
{
	// MLX
	mlx_t			*mlx;
	mlx_image_t		*img;
	bool			capture_mouse;
	double			old_time;
	double			delta_time;

	// Textures
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_texture		goose;

	// Colors
	t_color			floor;
	t_color			ceiling;

	// Map
	char			**grid;
	int				width;
	int				height;

	// Door
	mlx_image_t		*door_open_text;
	t_texture		door_open_texture;
	mlx_image_t		*door_close_text;
	t_texture		door_close_texture;

	// Player
	double			player_x;
	double			player_y;
	double			player_rotation;

	// Movement flags
	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
	bool			rotation_left;
	bool			rotation_right;

	// Movement Vector
	double			mouse_delta_x;
	double			move_x;
	double			move_y;

	// Minimap
	int				mi_size;
	int				mi_cell_size;
	int				mi_player_size;
	int				mi_player_width;

	// Goose
	int				*goose_pos_x;
	int				*goose_pos_y;
	int				*goose_target_x;
	int				*goose_target_y;
	t_goose_state	*goose_states;
	int				*goose_times;
	int				*goose_anim_wait;
	int				*goose_anim_frame;
	int				*goose_anim_count;
}					t_game;

// game functions
bool				init_game(t_game *game);
void				free_game(t_game *game);
void				init_img(t_game *game);
void				print_game(t_game *game);
void				print_grid(t_game *game);
void				print_movement(t_game *game);
bool				load_game_textures(t_game *game);

// parsing util functions
void				print_parsing_error(const char *error_msg);
void				print_parsing_error_line(const char *error_msg,
						const char *line);
bool				filename_valid(const char *scene_path);
bool				is_content_line(char *line);
bool				parse_color(t_color *color, const char *arg);

// parsing functions
bool				parse_game(t_game *game, const char *scene_path);
bool				parse_map(t_game *game, int fd, char *last_line);
bool				validate_grid(t_game *game);

// movement functions
bool				move(t_game *game);

// hooks
void				hooks(t_game *game);

void				keyhook(mlx_key_data_t keydata, void *param);
void				loophook(void *param);
void				cursorhook(double x, double y, void *param);
void				resize(int width, int height, void *param);
void				mousehook(mouse_key_t keydata, action_t action,
						modifier_key_t mods, void *param);

// minimap
void				print_minimap(t_game *game);
void				draw_player_triangle(t_game *game, int x, int y,
						double angle_rad);

// goose
void				update_goose(t_game *game);

// rendering functions
void				cast_rays(t_game *game);
mlx_image_t			*pre_render(t_game *game);
t_ray				cast_ray(double ray_angle, t_game *game);
void				render_goose(t_game *game);
void				draw_door(t_game *game, int pixel_x, t_ray ray);
uint32_t			get_door_pixel_color(t_game *game, t_ray *ray, int pixel_y);

// rendering utils
void				put_pixel(t_game *game, int x, int y, uint32_t color);
t_wall_dir			get_direction(t_ray *ray, t_game *game);
t_wall_dir			get_door_direction(t_ray *ray, t_game *game);
void				init_ray(t_ray *ray, double x, double y, double ra);

// angle utils
double				mod_angle(double angle);

// double utils
bool				double_close(double x, double y);
void				normalize_doubles(double *x, double *y);
double				ft_distance(int x, int y, int px, int py);

// random functions
uint32_t			lcg_rand(void);
uint32_t			lcg_rand_max(uint32_t max);

#endif // HEADER_H
