/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/18 12:37:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	closed_wall_manager(t_map *map)
{
	char	tofind;

	tofind = '1';
	if (top_wall_finder(map, tofind)
		&& middle_wall_finder(map, tofind)
		&& bottom_wall_finder(map, tofind))
		return (true);
	return (false);
}

bool	top_wall_finder(t_map *map, char tofind)
{
	int		x;
	char	**arr;

	x = 0;
	arr = map->gamemap;
	if (arr[0][x] == tofind)
	{
		while (arr[0][++x] && arr[0][x] == tofind)
		{
			if (!arr[0][x + 1])
				return (true);
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the top wall", STDOUT_FILENO);
	return (false);
}

bool	middle_wall_finder(t_map *map, char tofind)
{
	int		y;
	int		x;
	char	**arr;

	y = 1;
	x = 0;
	arr = arr;
	while (arr[y][x] && arr[y][x] == tofind
		&& arr[y + 2])
	{
		while (arr[y][x + 1])
			x++;
		if (arr[y][x] == tofind)
		{
			if (arr[y + 2][x] == '\0')
				return (true);
		}
		else if (arr[y][x] != tofind)
			break ;
		y++;
		x = 0;
	}
	ft_putstr_fd(RED"Your MAP has a breach on the middle wall", STDOUT_FILENO);
	return (false);
}

bool	bottom_wall_finder(t_map *map, char tofind)
{
	int		y;
	int		x;
	char	**arr;

	y = 0;
	x = 0;
	arr = map->gamemap;
	while (arr[y][x] && arr[y + 1][x] && arr[y + 1][x] != '\n')
		y++;
	if (arr[y][x] == tofind)
	{
		while (arr[y][x] && arr[y][x] == tofind)
		{
			if ((!arr[y][x + 1] || arr[y][x + 1] == '\n')
				&& (!arr[y + 1][0] || arr[y + 1][0] == '\n'))
			{
				if (arr[y][x + 1] == '\n' && linebreak_reader(arr, y, x))
					return (true);
				else if (!arr[y][x + 1])
					return (true);
			}
			x++;
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the bottom wall", STDOUT_FILENO);
	return (false);
}
