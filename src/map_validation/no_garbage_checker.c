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
	if (no_garbage_at_gamemap(map))
		return (true);
	ft_putstr_fd(RED"Garbage inside GameMap detected", STDERR_FILENO);
	return (false);
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
	return (false);
}
