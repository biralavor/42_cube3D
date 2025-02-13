/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/02/13 17:19:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libs/libft/includes/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define MAX_MAP_WIDTH 200
# define MAX_MAP_HEIGHT 200
# define MAX_TEXTURE_PATH 200
# define MAX_COLOR_DIGIT 15

# define RED	"\033[0;31m"
# define GRE	"\033[0;32m"
# define YEL	"\033[0;33m"
# define BLU	"\033[0;34m"
# define PUR	"\033[0;35m"
# define CYA	"\033[0;36m"
# define RESET	"\033[0m"

typedef struct s_map
{
	char	**gamemap;
	char	**ggraph;
	char	**colors;
	char	*buffer;
	int32_t	bytes_read;
	int32_t	fd;
	int		player_pos_y;
	int		player_pos_x;
}			t_map;

void	struct_memory_alloc(t_map *map);

bool	map_opener(int ac, char **argv, t_map *map);
bool	map_validation_manager(char **av, t_map *map);
bool	map_file_checker(char **av, t_map *map);
bool	valid_extension_checker(char **av, t_map *map);
bool	map_reader(t_map *map);
void	map_structs_init(t_map *map);
void	map_printer(t_map *map);

bool	unique_def_compass(t_map *map);
bool	north_compass_datafinder(t_map *map, int *already_found);
bool	south_compass_datafinder(t_map *map, int *already_found);
bool	west_compass_datafinder(t_map *map, int *already_found);
bool	east_compass_datafinder(t_map *map, int *already_found);

bool	map_colors_manager(char **arr);
bool	no_garbage_manager(t_map *map);
bool	no_garbage_at_color_values(char **arr, int digit,
			int *color_digits, int id);
bool	no_garbage_at_gamemap(char **arr);
void	gamegraph_into_array(t_map *map);
bool	no_garbage_at_texture(char **arr);
int		skipping_all_except_colors(t_map *map);
int		skipping_all_except_gamemap(t_map *map);
void	colorsmap_into_array(t_map *map);
void	convert_color_digits_id_to_int(char actual_char, int *rgbrgb, int *id,
			char *one_value);
void	gamemap_into_array(t_map *map);
void	color_digits_counter(char **arr, int *color_digits);
bool	color_digits_quantity_checker(int *color_digits);
bool	color_values_into_array(char **arr, int *color_values, int *rgbrgb);
bool	colors_with_min_max_values(int *rgbrgb);
void	map_array_printer(char **array, char *array_name);

bool	texture_path_manager(t_map *map);
bool	texture_path_tester(char *path, char *cwd);

bool	nothing_aftermap(char **arr);
bool	linebreak_reader(char **arr, int y, int x);

bool	map_player_manager(t_map *map);
bool	player_detected(t_map *map);
void	player_position_into_struct(t_map *map);
bool	player_free_to_go(t_map *map);
int		player_boundary_finder(t_map *map, char **arr, int y, int x);

bool	closed_wall_manager(t_map *map);
bool	top_wall_finder(char **arr, char tofind);
bool	middle_wall_finder(char **arr, char tofind);
bool	goto_arr_bondary(char **arr, int *y, int *x, char tofind);
bool	middle_last_line_checker(char **arr, int y, int x, char tofind);
bool	middle_max_boundary(char **arr, int y, int x, char tofind);
bool	bottom_wall_finder(char **arr, char tofind);

void	clear_all_exit_smoothly(t_map *map);

// struct for all datas
typedef struct s_data
{
	mlx_t			*mlx;
	int				config_stage;
	t_map			*map;
	t_map			*map_clone;
}	t_data;

#endif