/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/08 18:28:49 by umeneses         ###   ########.fr       */
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

# define MAX_MAP_WIDTH 20
# define MAX_MAP_HEIGHT 20

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define RESET	"\033[0m"


typedef struct s_map
{
	char	**matrix_map;
	char	*buffer;
	int32_t	bytes_read;
	int32_t	fd;
}			t_map;

bool	valid_extension_checker(t_map *map);
// bool	check_file_content_map(t_map *map);
bool	map_validation(int ac, char **av, t_map *map);
bool	map_opener(int ac, char **argv, t_map *map);
bool	map_reader(t_map *map);
void	map_printer(t_map *map);
bool	unique_def_compass(t_map *map);
bool	north_compass_datafinder(t_map *map, int *already_found);
bool	south_compass_datafinder(t_map *map, int *already_found);
bool	west_compass_datafinder(t_map *map, int *already_found);
bool	east_compass_datafinder(t_map *map, int *already_found);


// struct for all datas
typedef struct s_data
{
	mlx_t			*mlx;
	int				config_stage;
	t_map			*map;
	t_map			*map_clone;
}	t_data;

#endif