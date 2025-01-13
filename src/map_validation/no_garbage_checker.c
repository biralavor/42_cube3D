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
	int	idx;

	idx = -1;
	gamemap_into_array(map);
	map_array_printer(map->gamemap);
	// if (no_garbage_at_gamemap(map))
	// {
	// 	printf(PURPLE"Game Map ending point found\n");
	// 	return (true);
	// }
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'N' || map->buffer[idx] == 'S'
			|| map->buffer[idx] == 'W' || map->buffer[idx] == 'E')
			while (map->buffer[idx] != '\n')
				idx++;
		else if ((map->buffer[idx] == '\n' || map->buffer[idx + 1] == 'F'
			|| map->buffer[idx + 1] == 'C') || (map->buffer[idx] == 'F'
			|| map->buffer[idx] == 'C'))
			while (map->buffer[idx] != '\n')
				idx++;
		else if (map->buffer[idx] == '1' && map->buffer[idx + 1] == '1')
			while (map->buffer[idx] == '1' || map->buffer[idx] == '0'
				|| map->buffer[idx] == 'N' || map->buffer[idx] == 'S'
				|| map->buffer[idx] == 'W' || map->buffer[idx] == 'E'
				|| map->buffer[idx] == '\n' || map->buffer[idx] == '2')
				idx++;
		else if (map->buffer[idx] == '1' && map->buffer[idx - 1] == '1'
				&& map->buffer[idx - 2] == '1' && map->buffer[idx + 1] == '\0')
		{
			printf("Game Map ending point found\n");
			return (true);
		}
		else
			break ;
	}
	ft_putstr_fd(RED"Garbage found on map file at line ", STDERR_FILENO);
	ft_putstr_fd(ft_itoa(idx), STDERR_FILENO);
	ft_putendl_fd(":"YELLOW, STDERR_FILENO);
	ft_putchar_fd('>', STDERR_FILENO);
	ft_putstr_fd(RED"", STDERR_FILENO);
	while (map->buffer[idx])
	{
		ft_putchar_fd(map->buffer[idx], STDERR_FILENO);
		idx++;
	}
	return (false);
}

int	skipping_all_except_gamemap(t_map *map)
{
	int	idx;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == '1' && map->buffer[idx + 1] == '1'
			&& map->buffer[idx + 2] == '1' && map->buffer[idx + 3] == '1')
			return (idx);
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

// bool	no_garbage_at_gamemap(t_map *map)
// {
// 	char	**gmap;
// 	int	y;
// 	int	x;

// 	gmap = map->gamemap;
// 	y = -1;
// 	while (gmap[++y])
// 	{
// 		x = 0;
// 		while (gmap[y + 1][0] && (gmap[y][x] == '1' || gmap[y][x] == '0'
// 				|| gmap[y][x] == 'N' || gmap[y][x] == 'S' || gmap[y][x] == 'W'
// 				|| gmap[y][x] == 'E' || gmap[y][x] == '2' || gmap[y][x] == '\000'))
// 		{
// 			if (gmap[y][x] == '\000' && gmap[y + 1][0] == '\000'
// 				&& gmap[y][x - 1] == '1' && gmap[y][x - 2] == '1')
// 				return (true);
// 			x++;
// 		}
// 	}
// 	return (false);
// }
