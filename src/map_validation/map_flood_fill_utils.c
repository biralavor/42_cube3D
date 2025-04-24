/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:20:53 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 15:45:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	max_width_getter(t_map *map)
{
	int	idx;
	int	line_len;

	idx = 0;
	line_len = 0;
	map->max_width = 0;
	while (map->gamemap[idx])
	{
		line_len = ft_strlen(map->gamemap[idx]);
		if (line_len > map->max_width)
			map->max_width = line_len;
		idx++;
	}
}

void	max_height_getter(t_map *map)
{
	int	idx;
	int	height_len;

	idx = 0;
	height_len = 0;
	map->max_height = 0;
	while (map->gamemap[height_len][idx])
	{
		while (map->gamemap[height_len][idx])
			height_len++;
		if (height_len > map->max_height)
			map->max_height = height_len;
		idx++;
		height_len = 0;
	}
}

void	map_spaces_normalizer(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->gamemap[y])
	{
		x = 0;
		while (map->gamemap[y][x])
		{
			if (map->gamemap[y][x] == ' ' || map->gamemap[y][x] == '\t'
				|| map->gamemap[y][x] == '\v')
				map->gamemap[y][x] = 'S';
			x++;
		}
		y++;
	}
}
