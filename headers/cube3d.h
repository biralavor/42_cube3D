/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:33 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 18:41:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libs/libft/includes/libft.h"
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

#endif