/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structs_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:05:54 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/16 18:14:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_structs_init(t_map *map)
{
	gamemap_into_array(map);
	map_array_printer(map->gamemap);
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
