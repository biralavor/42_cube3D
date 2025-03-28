/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/27 21:31:56 by gigardin         ###   ########.fr       */
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
# include <math.h>

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
# define TILE_SIZE 8
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10
# define MOVE_SPEED 1.0
# define ROTATE_SPEED 0.1

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

void			try_open_door(t_game *g);

void			free_textures(t_game *g);

void			load_textures(t_game *game);
mlx_texture_t	*get_texture_for_ray(t_game *game, t_ray *ray);
int				get_tex_x(t_game *g, t_ray *r, mlx_texture_t *t);
void			draw_texture_line(t_game *g, mlx_texture_t *t, t_ray *r, int col, int tex_x);
void			draw_textured_wall(t_game *g, t_ray *r, int col);

void			draw_background(t_game *game);
void			draw_player(t_game *game);


void			draw_minimap_tile(t_game *game, int x, int y, uint32_t color);
void			draw_minimap_player(t_game *game);
void			draw_minimap(t_game *game);

void			setup_ray(t_game *g, float angle, t_ray *r, t_vec *pos);
void			perform_dda(t_game *g, t_ray *r, t_vec pos);
void			cast_ray_dda(t_game *g, float angle, t_ray *r);
void			cast_rays(t_game *game);
void			render_init(t_game *game);
void			render(t_game *game);
void			loop_hook(t_game *game);

void			set_player_position(t_game *game);
void			move_player(t_game *game, float move_x, float move_y);
void			rotate_player(t_game *game, float rotation_speed);

void			handle_movement(mlx_key_data_t keydata, t_game *game);
void			handle_keypress(mlx_key_data_t keydata, void *param);
void			handle_close(void *param);

void			setup_hooks(t_game *game);
void			set_player_position(t_game *game);

void			game_loop(t_game *game);
void			cleanup(t_game *game);
int				setup_init(t_game *game);

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

#endif
