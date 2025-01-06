/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_mapfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:28:14 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 18:40:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	existing_mapfile(int ac, char **argv, t_map *map)
{
	if (ac != 2)
	{
		if (ac < 2)
			ft_error_msg("Cube3D needs a map file to starts the game session.\n");
		else
			printf("Cube3D only accepts one map file to starts the game session.\n");
	}
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("saving map file at map->fd = %d\n", map->fd);
	if (map->fd != -1)
		return (true);
	ft_putendl_fd("Error!\nInvalid map file T.T", STDOUT_FILENO);
	close(map->fd);
	return (false);
}
