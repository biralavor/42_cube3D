/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/25 19:07:13 by gigardin         ###   ########.fr       */
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
# define MAX_TEXTURE_PATH 200
# define MAX_TEXTURE_FILES 4
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
# define MOVE_SPEED 5.0
# define ROTATE_SPEED 0.1

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

void	draw_background(mlx_image_t *image);
void	draw_player(t_game *game);

float	cast_single_ray(t_game *game, float ray_angle);
void	cast_rays(t_game *game);
void	render_init(t_game *game);
void	render(t_game *game);
void	loop_hook(t_game *game);

void	set_player_position(t_game *game);
void	move_player(t_game *game, float move_x, float move_y);
void	rotate_player(t_game *game, float rotation_speed);

void	handle_movement(mlx_key_data_t keydata, t_game *game);
void	handle_keypress(mlx_key_data_t keydata, void *param);
void	handle_close(void *param);

void	setup_hooks(t_game *game);
void	set_player_position(t_game *game);

void	game_loop(t_game *game);
void	cleanup(t_game *game);
int		setup_init(t_game *game);

/**
 * @brief Allocate memory for the entire struct (map->gamemap,
 * 			map->ggraph, map->colors).
 *			It initializes the map struct with empty values.
 * @param  map struct with all map data
 * @return `void`
 */
void	struct_memory_alloc(t_map *map);

/**
 * @brief Open the map file and check if it exists
 * @param  ac argument count
 * @param  av argument vector
 * @param  map struct with all map data
 * @return `bool` true if the file exists, false otherwise
 */
bool	map_opener(int ac, char **av, t_map *map);

bool	linebreak_reader(char **arr, int y, int x);

/**
 * @brief Print the specif array from the map in the terminal
 * @param  map struct with all map data
 * @param  array array to be printed
 * @param  array_name name of the array to be printed
 * @return `void`
 */
void	map_array_printer(char **array, char *array_name);

/**
 * @brief Print the map in the terminal
 * @param  map struct with all map data
 * @return `void`
 */
void	map_printer(t_map *map);

#endif
