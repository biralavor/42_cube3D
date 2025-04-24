/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundary_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:20:53 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 16:34:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_boundaries_validation_manager(t_map *map)
{
	char		**padded_map;
	t_flood_dim	dim;

	max_width_getter(map);
	max_height_getter(map);
	map_spaces_normalizer(map);
	padded_map = create_padded_map_at_top(map);
	padded_map = create_padded_map_at_middle(map, padded_map);
	padded_map = create_padded_map_at_bottom(map, padded_map);
	dim.height = map->max_height + 2;
	dim.width = map->max_width + 2;
	flood_fill_it(padded_map, 0, 0, &dim);
	map_array_printer(padded_map, "padded_map");
	if (is_map_closed(map, padded_map))
	{
		ft_free_array(padded_map);
		return (true);
	}
	ft_free_array(padded_map);
	return (false);
}

bool	are_diagonals_valid(t_map *map, int row, int col)
{
	if (row > 0 && col > 0 && map->gamemap[row - 1][col - 1] == 'S')
		return (false);
	if (row + 1 < map->max_height && col > 0
		&& map->gamemap[row + 1][col - 1] == 'S')
		return (false);
	if (row > 0 && col + 1 < (int)ft_strlen(map->gamemap[row])
		&& map->gamemap[row - 1][col + 1] == 'S')
		return (false);
	if (row + 1 < map->max_height
		&& col + 1 < (int)ft_strlen(map->gamemap[row])
		&& col + 1 < (int)ft_strlen(map->gamemap[row + 1])
		&& map->gamemap[row + 1][col + 1] == 'S')
		return (false);
	return (true);
}

bool	are_sides_valid(t_map *map, int row, int col)
{
	if (row <= 0 || row >= map->max_height -1
		|| col <= 0 || col >= (int)ft_strlen(map->gamemap[row]) - 1)
		return (false);
	if (map->gamemap[row - 1][col] == 'S')
		return (false);
	if (map->gamemap[row + 1][col] == 'S')
		return (false);
	if (map->gamemap[row][col - 1] == 'S')
		return (false);
	if (map->gamemap[row][col + 1] == 'S')
		return (false);
	return (true);
}

bool	is_position_valid(t_map *map, char **padded_map, int map_y, int map_x)
{
	char	boundary_char;
	int		padded_y;
	int		padded_x;

	padded_y = map_y + 1;
	padded_x = map_x + 1;
	if (map_x >= (int)ft_strlen(map->gamemap[map_y]))
		return (true);
	boundary_char = map->gamemap[map_y][map_x];
	if (boundary_char == 'S' || boundary_char == '1')
		return (true);
	if (padded_map[padded_y][padded_x] == 'V'
		|| !are_diagonals_valid(map, map_y, map_x)
		|| !are_sides_valid(map, map_y, map_x))
	{
		printf("Map breach at position [%d,%d] (char: '%c')\n",
			map_y, map_x, boundary_char);
		return (false);
	}
	return (true);
}

bool	is_map_closed(t_map *map, char **padded_map)
{
	int	x;
	int	y;

	y = 0;
	while (++y <= map->max_height)
	{
		x = 0;
		while (++x <= map->max_width)
		{
			if (is_position_valid(map, padded_map, y - 1, x - 1))
				return (true);
		}
	}
	return (false);
}
