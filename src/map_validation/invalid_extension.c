/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:29 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/08 18:28:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	valid_extension_checker(t_map *map)
{
	int		i;

	i = ft_strlen(map->buffer);
	if (ft_strncmp(&map->buffer[i - 4], ".cub", 4) == 0)
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