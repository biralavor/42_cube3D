/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/20 19:16:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	color_digits_quantity_checker(int *color_digits)
{
	int	id;

	id = -1;
	while (++id < 6)
	{
		if (color_digits[id] >= 1 && color_digits[id] <= 3)
		{
			if (id == 5)
				return (true);
		}
	}
	ft_putstr_fd(RED"Invalid number of digits at Color Map\n", STDERR_FILENO);
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
