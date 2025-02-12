/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_opener.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:28:14 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/12 19:32:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_opener(int ac, char **av, t_map *map)
{
	if (ac != 2)
	{
		if (ac < 2)
		{
			ft_putstr_fd("Cube3D needs a map file to "
				"starts the game.\n", STDERR_FILENO);
		}
		else
			ft_putstr_fd("Cube3D only accepts one map file.\n", STDERR_FILENO);
	}
	map->fd = open(av[1], O_RDONLY);
	if (map->fd != -1)
		return (true);
	close(map->fd);
	ft_putstr_fd("No map file found with this name T.T\n", STDERR_FILENO);
	return (false);
}
