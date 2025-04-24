/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:35 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 19:04:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/* ************************************************************************** */
/*                            STANDARD LIBRARIES                              */
/* ************************************************************************** */
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

/* ************************************************************************** */
/*                            ADDITIONAL LIBRARIES                            */
/* ************************************************************************** */
# include "../libs/libft/includes/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"

/* ************************************************************************** */
/*                            PROGRAM LIBRARIES                               */
/* ************************************************************************** */
# include "cube3d_structures.h"
# include "map_file_manager.h"
# include "map_player_manager.h"
# include "map_closed_wall_manager.h"
# include "map_no_garbage_manager.h"
# include "map_texture_path_manager.h"
# include "map_colors_manager.h"
# include "clear_all.h"

/* ************************************************************************** */
/*                            CONSTANT DEFINITIONS                            */
/* ************************************************************************** */
# define MAX_MAP_WIDTH 800
# define MAX_MAP_HEIGHT 600
# define WIDTH 800
# define HEIGHT 600
# define MAX_TEXTURE_PATH 400
# define MAX_TEXTURE_FILES 6
# define MAX_INSIDE_ALLOC 4
# define MAX_RGB_SLOTS 6
# define TOTAL_COLOR_DIGIT 15
# define RED	"\033[0;31m"
# define GRE	"\033[0;32m"
# define YEL	"\033[0;33m"
# define BLU	"\033[0;34m"
# define PUR	"\033[0;35m"
# define CYA	"\033[0;36m"
# define RESET	"\033[0m"
# define EMPTY_SPACE_COLOR 0x555555FF
# define WALLS_COLOR 0xFFFFFFFF
# define BACKGROUND_COLOR 0x000000FF
# define PLAYER_DIR_COLOR 0xFFFF00FF
# define PLAYER_POS_COLOR 0xFF0000FF
# define TILE_SIZE 8
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10
# define MOVE_SPEED 1.0
# define ROTATE_SPEED 0.1
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

void			load_textures(t_game *game);
/**
 * @brief Get the texture for the ray based on the hit side.
 * If the ray hits a horizontal wall, it returns the
 * texture for the east or west wall.
 * If the ray hits a vertical wall,
 * it returns the texture for the north or south wall.
 * @param  game struct with all game data
 * @param  ray struct with the ray data
 * @return `mlx_texture_t*` pointer to the texture
 */
mlx_texture_t	*get_texture_for_ray(t_game *game, t_ray *ray);
int				get_tex_x(t_game *g, t_ray *r, mlx_texture_t *t);

void			draw_texture_pixel(t_game *g, mlx_texture_t *t,
					t_drawinfo *info);
void			draw_texture_line(t_game *g, mlx_texture_t *t,
					t_ray *r, t_drawinfo *info);
void			draw_textured_wall(t_game *g, t_ray *r, int col);

void			draw_background(t_game *game);
void			minimap_tile_render(t_game *game, int x, int y, uint32_t color);
void			minimap_player_render(t_game *game);
void			minimap_manager(t_game *game);
void			setup_step_and_delta(t_ray *r);
void			setup_ray(t_game *g, float angle, t_ray *r, t_vec *pos);
void			perform_dda(t_game *g, t_ray *r, t_vec pos);
void			cast_ray_dda(t_game *g, float angle, t_ray *r);
void			cast_rays(t_game *game);
void			render_init(t_game *game);
/**
 * @brief Render the game screen. To do so, it clears the screen,
 * 			draws the background, loads the textures, and calls
 * 			the function to `cast_rays()` and `draw_minimap()`.
 * @param  game struct with all game data
 * @return `void`
 */
void			render(t_game *game);
void			loop_hook(t_game *game);
/**
 * @brief Sets the player position at game startup.
 * 	It also initilizes the player direction
 * 	(dix_x and dir_y), camera plane direction
 * 	(plane_x and plane_y) and player angle.
 * 	The payer angle is set to 0 degrees (facing right) by default.
 * 	- N = North (up) = 270 degrees
 * 	- S = South (down) = 90 degrees
 * 	- E = East (right) = 0 degrees
 * 	- W = West (left) = 180 degrees
 * @param  game struct with all game data
 * @return `void`
 */
void			game_directions_setter(t_game *game);

void			move_player(t_game *game, float move_x, float move_y);
/**
 * @brief Rotate the player direction and camera plane
 * 	based on the rotation speed.
 * 	- The rotation speed is defined by the ROTATE_SPEED constant.
 * 	- The calculation is done using cosine and sine functions.
 * 	- The direction vector (dir_x and dir_y) is rotated to match the new dir.
 * 	- The camera plane is rotated to match the new direction.
 * 	- The player angle is updated to keep track of the current direction.
 * 	- The player angle is normalized to be between 0 and 2 * PI.
 * * @param  game struct with all game data
 * @param  rotation_speed rotation speed in radians
 * @return `void`
 */
void			rotate_player(t_game *game, float rotation_speed);
void			resolve_move_direction(int key, t_game *game,
					t_movement *m);
void			handle_movement(mlx_key_data_t keydata, t_game *game);
void			handle_keypress(mlx_key_data_t keydata, void *param);
void			handle_mouse_direction(double m_xpos, double m_ypos,
					void *param);
void			minicraft_effect_runner(t_game *game);
void			setup_hooks(t_game *game);
void			game_loop(t_game *game);
void			setup_init(t_game *game);
/**
 * @brief Allocate memory for the entire struct (map->gamemap,
 * 			map->ggraph, map->colors).
 *			It initializes the map struct with empty values.
 * @param  map struct with all map data
 * @return `void`
 */
void			struct_memory_alloc(t_map *map);

/**
 * @brief Open the map file and check if it exists
 * @param  ac argument count
 * @param  av argument vector
 * @param  map struct with all map data
 * @return `bool` true if the file exists, false otherwise
 */
bool			map_opener(int ac, char **av, t_map *map);

bool			linebreak_reader(char **arr, int y, int x);
/**
 * @brief Print the specif array from the map in the terminal
 * @param  map struct with all map data
 * @param  array array to be printed
 * @param  array_name name of the array to be printed
 * @return `void`
 */
void			map_array_printer(char **array, char *array_name);

/**
 * @brief Print the map in the terminal
 * @param  map struct with all map data
 * @return `void`
 */
void			map_printer(t_map *map);

bool			map_boundaries_validation_manager(t_map *map);
bool			create_boundary_markers(t_map *map);
bool			is_map_closed(t_map *map, char **padded_map);
bool			is_position_valid(t_map *map, char **padded_map,
					int map_y, int map_x);
void			flood_fill_it(char **map, int x, int y, t_flood_dim *dim);
void			alloc_error_msg(char **matrix, char *str);
char			**create_padded_map_at_bottom(t_map *map, char **padded_map);
char			**create_padded_map_at_middle(t_map *map, char **padded_map);
void			copy_map_data_and_fill_spaces(t_map *map, char **padded_map,
					int idx, int actual_width);
char			**create_padded_map_at_top(t_map *map);
void			map_spaces_normalizer(t_map *map);
void			max_height_getter(t_map *map);
void			max_width_getter(t_map *map);

#endif
