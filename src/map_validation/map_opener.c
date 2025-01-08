/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_mapfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:28:14 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 20:22:47 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_opener(int ac, char **av, t_map *map)
{
	if (ac != 2)
	{
		if (ac < 2)
			ft_error_msg("Cube3D needs a map file to starts the game.\n");
		else
			ft_error_msg("Cube3D only accepts one map file.\n");
	}
	map->fd = open(av[1], O_RDONLY);
	if (map->fd != -1)
		return (true);
	ft_error_msg("Error!\nInvalid map file T.T\n");
	close(map->fd);
	return (false);
}
