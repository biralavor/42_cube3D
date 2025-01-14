/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/14 19:17:55 by umeneses         ###   ########.fr       */
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

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define RESET	"\033[0m"


typedef struct s_map
{
	char	**gamemap;
	char	*buffer;
	int32_t	bytes_read;
	int32_t	fd;
}			t_map;

void	gamemap_init(t_map *map);

bool	map_validation_manager(int ac, char **av, t_map *map);
bool	map_file_checker(int ac, char **av, t_map *map);
bool	valid_extension_checker(char **av);
bool	map_opener(int ac, char **argv, t_map *map);
bool	map_reader(t_map *map);
void	map_printer(t_map *map);
bool	unique_def_compass(t_map *map);
bool	north_compass_datafinder(t_map *map, int *already_found);
bool	south_compass_datafinder(t_map *map, int *already_found);
bool	west_compass_datafinder(t_map *map, int *already_found);
bool	east_compass_datafinder(t_map *map, int *already_found);
bool	no_garbage_checker(t_map *map);
int		skipping_all_except_gamemap(t_map *map);
void	gamemap_into_array(t_map *map);
void	map_array_printer(char **array);
bool	no_garbage_at_gamemap(t_map *map);
bool	nothing_aftermap(t_map *map, int *already_found);

bool	map_player_checker(t_map *map);
bool	player_detected(t_map *map);

// struct for all datas
typedef struct s_data
{
	mlx_t			*mlx;
	int				config_stage;
	t_map			*map;
	t_map			*map_clone;
}	t_data;

#endif