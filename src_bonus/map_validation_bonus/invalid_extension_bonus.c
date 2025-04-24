/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_extension_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:29 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/24 20:53:39 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

bool	valid_extension_checker(char **av, t_map *map)
{
	int		idx;
	char	*map_name;

	idx = ft_strlen(av[1]);
	map_name = av[1];
	if (ft_strncmp(&map_name[idx - 4], ".cub", 4) == 0)
		return (true);
	close(map->fd);
	ft_putendl_fd(RED"Map not in '.cub' extension!"RESET, STDOUT_FILENO);
	return (false);
}
