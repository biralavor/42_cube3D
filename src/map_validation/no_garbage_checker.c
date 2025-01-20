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

bool	no_garbage_at_colors(t_map *map)
{
	int			y;
	int			x;
	int			id;
	static int	color_digits[6];
	static int	rgbrgb[6];

	y = -1;
	x = -1;
	id = -1;
	color_digits_counter(map, color_digits);
	while (color_digits[++id])
		printf("Color Digits[%d]: %d\n", id, color_digits[id]);

	while (map->colors[++y][0])
	{
		while (map->colors[y][++x] != ',')
			;
		if (ft_isdigit(map->colors[y][x - 1])	
			&& ft_isdigit(map->colors[y][x - 2])
			&& ft_isdigit(map->colors[y][x + 2]))
			{
				rgbrgb[++id] = 1;
				x += 2;
			}
		else if (map->colors[y][x] == '\n')
			break ;
	}
	if (rgbrgb[0] == 1 && rgbrgb[1] == 1 && rgbrgb[2] == 1
		&& rgbrgb[3] == 1 && rgbrgb[4] == 1 && rgbrgb[5] == 1)
	{
		printf("\nPrinting Map Colors:\n");
		map_array_printer(map->colors);
		return (true);
	}
	ft_putstr_fd(RED"Garbage inside MapColors detected", STDERR_FILENO);
	// ft_putstr_fd(RED"Invalid definition at Color Map\n"RESET, STDERR_FILENO);
	return (false);
}

void	color_digits_counter(t_map *map, int *color_digits)
{
	int	y;
	int	x;
	int	id;
	int	comma_counter;

	y = -1;
	id = 0;
	while (map->colors[++y][0])
	{
		comma_counter = 0;
		x = 1;
		while (comma_counter < 3)
		{
			while (map->colors[y][++x] && map->colors[y][x] != ','
				&& map->colors[y][x] != '\n')
				color_digits[id]++;
			comma_counter++;
			id++;
			if (map->colors[y][x + 1] == '\n')
				break ;
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
			if (arr[y][x] != '1' && arr[y][x] != '0' && arr[y][x] != 'N'
				&& arr[y][x] != 'S' && arr[y][x] != 'W' && arr[y][x] != 'E'
				&& arr[y][x] != '2')
					return (false);
			if ((arr[y][x] == '1' || arr[y][x] == '0') && arr[y][x - 1] == '1'
				&& arr[y][x - 2] == '1' && y > 2 && arr[y - 1][x] == '1'
				&& (arr[y][x + 1] == '\n' || !arr[y][x + 1]))
				return (true);
			else if (arr[y][x + 1] == '\0' && arr[y + 1][0])
				break ;
		}
	}
	ft_putstr_fd(RED"Garbage inside GameMap detected", STDERR_FILENO);
	return (false);
}
