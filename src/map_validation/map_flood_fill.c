/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:20:53 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 15:56:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	flood_fill_it(char **map, int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_it(map, x + 1, y, height, width);
	flood_fill_it(map, x - 1, y, height, width);
	flood_fill_it(map, x, y + 1, height, width);
	flood_fill_it(map, x, y - 1, height, width);
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

bool	is_map_closed(t_map *map, char **padded_map)
{
	int		x;
	int		y;
	char	boundary_char;

	y = 1;
	while (y <= map->max_height)
	{
		x = 1;
		while (x <= map->max_width)
		{
			if (x - 1 >= (int)ft_strlen(map->gamemap[y - 1]))
			{
				x++;
				continue ;
			}
			boundary_char = map->gamemap[y - 1][x - 1];
			if (boundary_char == 'S' || boundary_char == '1')
			{
				x++;
				continue ;
			}
			if (padded_map[y][x] == 'V'
				|| !are_diagonals_valid(map, y - 1, x - 1)
				|| !are_sides_valid(map, y - 1, x - 1))
			{
				printf("Map breach at position [%d,%d] (char: '%c')\n",
					y, x, boundary_char);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	map_boundaries_validation(t_map *map)
{
	char	**padded_map;

	max_width_getter(map);
	max_height_getter(map);
	map_spaces_normalizer(map);
	padded_map = create_padded_map_at_top(map);
	padded_map = create_padded_map_at_middle(map, padded_map);
	padded_map = create_padded_map_at_bottom(map, padded_map);
	flood_fill_it(padded_map, 0, 0, map->max_height + 2, map->max_width + 2);
	map_array_printer(padded_map, "padded_map");
	if (is_map_closed(map, padded_map))
	{
		ft_free_array(padded_map);
		return (true);
	}
	ft_free_array(padded_map);
	return (false);
}
