/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:05:54 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 20:54:26 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	map_structs_init(t_map *map)
{
	gamegraph_into_array(map);
	colorsmap_into_array(map);
	gamemap_into_array(map);
	map_array_printer(map->ggraph, "map->gamegraph");
	map_array_printer(map->colors, "map->colors");
	map_array_printer(map->gamemap, "map->gamemap");
}

void	gamegraph_into_array(t_map *map)
{
	int	idx;
	int	x;
	int	y;

	x = -1;
	y = 0;
	idx = 0;
	while (map->buffer[idx] && y < 4)
	{
		map->ggraph[y][++x] = map->buffer[idx];
		idx++;
		if (map->buffer[idx] == '\n')
		{
			y++;
			x = -1;
			idx++;
		}
	}
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
