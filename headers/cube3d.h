/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/02/17 22:03:53 by umeneses         ###   ########.fr       */
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
# include "closed_wall_manager.h"
# include "garbage_manager.h"
# include "texture_path_manager.h"
# include "map_colors_manager.h"

/* ************************************************************************** */
/*                            CONSTANT DEFINITIONS                            */
/* ************************************************************************** */
# define MAX_MAP_WIDTH 200
# define MAX_MAP_HEIGHT 200
# define MAX_TEXTURE_PATH 200
# define MAX_TEXTURE_FILES 4
# define MAX_TOTAL_COLOR_DIGIT 15
# define MAX_INSIDE_ALLOC 4
# define RED	"\033[0;31m"
# define GRE	"\033[0;32m"
# define YEL	"\033[0;33m"
# define BLU	"\033[0;34m"
# define PUR	"\033[0;35m"
# define CYA	"\033[0;36m"
# define RESET	"\033[0m"

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

/**
 * @brief Free the memory allocated for the entire struct (map->gamemap,
 * 			map->ggraph, map->colors).
 * @param  map struct with all map data
 * @return `void`
 */
void	clear_all_exit_smoothly(t_map *map);

#endif