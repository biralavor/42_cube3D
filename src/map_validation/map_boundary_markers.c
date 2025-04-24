/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundary_markers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:12:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 18:58:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	is_wall_boundary(t_map *map, int y, int x);

bool	create_boundary_markers(t_map *map)
{
	int		y;
	int		x;
	char	**boundary_map;
	
	// Allocate boundary map (same size as game map)
	boundary_map = ft_calloc(map->max_height + 1, sizeof(char *));
	if (!boundary_map)
	{
		alloc_error_msg(boundary_map, "Memory alloc failed at boundary map\n");
		return (false);
	}
	
	// Initialize each row
	for (y = 0; y < map->max_height; y++)
	{
		boundary_map[y] = ft_calloc(map->max_width + 1, sizeof(char));
		if (!boundary_map[y])
		{
			alloc_error_msg(boundary_map, "Memory alloc failed at boundary map\n");
			return (false);
		}
		ft_memset(boundary_map[y], ' ', map->max_width);
		boundary_map[y][map->max_width] = '\0';
	}
	
	// Mark boundary walls
	for (y = 0; y < map->max_height; y++)
	{
		for (x = 0; x < (int)ft_strlen(map->gamemap[y]); x++)
		{
			// Skip non-walls
			if (map->gamemap[y][x] != 'B')
				continue;
				
			// Check if this wall is adjacent to a space or map edge
			if (is_wall_boundary(map, y, x))
				boundary_map[y][x] = 'B';
		}
	}
	
	map->boundary_map = boundary_map;
	return (true);
}

static bool	is_wall_boundary(t_map *map, int y, int x)
{
	int row_len;

	row_len = ft_strlen(map->gamemap[y]);
	// Edge of map checks
	if (y == 0 || y == map->max_height - 1 || x == 0 || x == row_len - 1)
		return (true);
		
	// Check if adjacent to spaces
	if ((x > 0 && map->gamemap[y][x-1] == 'S') ||
		(x < row_len - 1 && map->gamemap[y][x+1] == 'S') ||
		(y > 0 && x < (int)ft_strlen(map->gamemap[y-1]) && map->gamemap[y-1][x] == 'S') ||
		(y < map->max_height - 1 && x < (int)ft_strlen(map->gamemap[y+1]) && map->gamemap[y+1][x] == 'S'))
		return (true);
		
	return (false);
}

