/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compass_datafinder_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:26:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:26:07 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

bool	north_compass_datafinder(t_map *map, int *already_found)
{
	int	idx;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'N' && map->buffer[idx + 1] == 'O')
			already_found[0]++;
		if (map->buffer[idx + 1] == '\0')
		{
			if (already_found[0] == 0)
				break ;
			return (true);
		}
	}
	ft_putstr_fd(YEL"No data found for 'NO' in map file", STDERR_FILENO);
	return (false);
}

bool	south_compass_datafinder(t_map *map, int *already_found)
{
	int	idx;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'S' && map->buffer[idx + 1] == 'O')
			already_found[1]++;
		if (map->buffer[idx + 1] == '\0')
		{
			if (already_found[1] == 0)
				break ;
			return (true);
		}
	}
	ft_putstr_fd(YEL"No data found for 'SO' in map file", STDERR_FILENO);
	return (false);
}

bool	west_compass_datafinder(t_map *map, int *already_found)
{
	int	idx;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'W' && map->buffer[idx + 1] == 'E')
			already_found[2]++;
		if (map->buffer[idx + 1] == '\0')
		{
			if (already_found[2] == 0)
				break ;
			return (true);
		}
	}
	ft_putstr_fd(YEL"No data found for 'WE' in map file", STDERR_FILENO);
	return (false);
}

bool	east_compass_datafinder(t_map *map, int *already_found)
{
	int	idx;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'E' && map->buffer[idx + 1] == 'A')
			already_found[3]++;
		if (map->buffer[idx + 1] == '\0')
		{
			if (already_found[3] == 0)
				break ;
			return (true);
		}
	}
	ft_putstr_fd(YEL"No data found for 'EA' in map file", STDERR_FILENO);
	return (false);
}
