/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:29 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/08 19:03:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	valid_extension_checker(char **av)
{
	int		i;
	char	*map_name;

	i = ft_strlen(av[1]);
	map_name = av[1];
	if (ft_strncmp(&map_name[i - 4], ".cub", 4) == 0)
		return (true);
	ft_putendl_fd(RED"Map not in '.cub' extension!"RESET, STDOUT_FILENO);
	return (false);
}

// bool	check_file_content_map(t_map *map)
// {
// 	int		fd;
// 	char	buffer[1];
// 	// int		i;

// 	// i = ft_strlen(map->file);
// 	fd = open(map->buffer, O_RDONLY);
// 	if (read(fd, buffer, 1) == 0)
// 	{
// 		close(fd);
// 		ft_putendl_fd("Map file is empty!", STDOUT_FILENO);
// 		return (false);
// 	}
// 	close(fd);
// 	return (true);
// }