/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/06 18:52:50 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libs/libft/includes/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct s_map
{
	char	**matrix_map;
	int32_t	fd;
}			t_map;

bool	map_validation(int ac, char **av, t_map *map);
bool	existing_mapfile(int ac, char **argv, t_map *map);



// struct for all datas
typedef struct s_data
{
	mlx_t			*mlx;
	int				config_stage;
	t_map			*map;
	t_map			*map_clone;
}	t_data;

#endif