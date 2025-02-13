/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:10:55 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 14:50:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_reader(t_map *map)
{
	char	buffer[(MAX_MAP_WIDTH * MAX_MAP_HEIGHT)];

	map->bytes_read = read(map->fd, buffer, sizeof(buffer));
	close(map->fd);
	if (map->bytes_read < 0)
	{
		perror("Couldn't read the file");
		return (false);
	}
	if (map->bytes_read > 0)
	{
		map->buffer = (char *)ft_calloc(map->bytes_read + 1, sizeof(char));
		if (!map->buffer)
		{
			ft_putstr_fd(YEL"Memory allocation failed T.T", STDERR_FILENO);
			return (false);
		}
		ft_memcpy(map->buffer, buffer, map->bytes_read);
		map->buffer[map->bytes_read] = '\0';
		return (true);
	}
	ft_putstr_fd(YEL"No map data here. Is it empty?", STDERR_FILENO);
	return (false);
}
