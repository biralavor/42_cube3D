/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:05:54 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/21 08:03:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_structs_init(t_map *map)
{
	gamemap_into_array(map);
	colorsmap_into_array(map);
	map_array_printer(map->gamemap, "map->gamemap");
}

void	colorsmap_into_array(t_map *map)
{
	int	idx;
	int	x;
	int	y;

	x = -1;
	y = 0;
	idx = skipping_all_except_colors(map);
	if (idx != -1)
	{
		while (map->buffer[idx])
		{
			map->colors[y][++x] = map->buffer[idx];
			idx++;
			if (map->buffer[idx] == '\n' && map->buffer[idx + 1] == '1'
				&& map->buffer[idx + 2] == '1' && map->buffer[idx + 3] == '1')
				break ;
			else if (map->buffer[idx] == '\n' && map->buffer[idx + 1] == 'C')
			{
				y++;
				x = -1;
				idx++;
			}
		}
	}
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
