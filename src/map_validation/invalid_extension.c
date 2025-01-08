/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:29 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/08 17:58:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	check_extension_valid(t_map *map)
{
	int		i;

	i = ft_strlen(map->file);
	if (ft_strncmp(&map->file[i - 4], ".cub", 4) != 0)
	{
		ft_putendl_fd("Map not in .cub extension!\n", STDOUT_FILENO);
		return (false);
	}
	return (true);
}

bool	check_file_content_map(t_map *map)
{
	int		fd;
	char	buffer[1];
	int		i;

	i = ft_strlen(map->file);
	fd = open(map->file, O_RDONLY);
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		ft_putendl_fd("Map file is empty!\n", STDOUT_FILENO);
		return (false);
	}
	close(fd);
	return (true);
}