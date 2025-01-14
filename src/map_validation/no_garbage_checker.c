/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_garbage_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:48:01 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/08 18:48:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	no_garbage_checker(t_map *map)
{
	gamemap_into_array(map);
	map_array_printer(map->gamemap);
	if (no_garbage_at_gamemap(map))
		return (true);
	ft_error_msg("Garbage inside GameMap detected\n");
	return (false);
}

int	skipping_all_except_gamemap(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->buffer[idx])
	{
		if (map->buffer[idx] == 'C')
		{
			while (map->buffer[idx] != '\n')
				idx++;
			if (map->buffer[idx] == '\n')
			{
				while (map->buffer[idx] == '\n')
					idx++;
				return (idx);
			}
		}
		idx++;
	}
	return (-1);
}

void	gamemap_into_array(t_map *map)
{
	int	idx;
	int	x;
	int	y;

	x = -1;
	y = 0;
	idx = skipping_all_except_gamemap(map);
	if (idx != -1)
	{
		while (map->buffer[idx])
		{
			map->gamemap[y][++x] = map->buffer[idx];
			idx++;
			if (map->buffer[idx] == '\n')
			{
				y++;
				x = -1;
				idx++;
			}
		}
	}
}

bool	no_garbage_at_gamemap(t_map *map)
{
	char	**arr;
	int		y;
	int		x;

	arr = map->gamemap;
	y = -1;
	while (arr[++y][0] != '\0')
	{
		x = -1;
		while (arr[y][++x])
		{
			if (arr[y][x] != '1' && arr[y][x] != '0'&& arr[y][x] != 'N'
				&& arr[y][x] != 'S' && arr[y][x] != 'W' && arr[y][x] != 'E'
				&& arr[y][x] != '2')
					return (false);
			if ((arr[y][x] == '1' && !arr[y][x + 1] && arr[y][x - 1] == '1'
				&& arr[y][x - 2] == '1' && !arr[y + 2][0] && !arr[y + 1][1])
				&& (arr[y + 1][0] == '\n' || !arr[y + 1][0]))
				return (true);
			else if (arr[y][x + 1] == '\0' && arr[y + 1][0])
				break ;
		}
	}
	return (false);
}
