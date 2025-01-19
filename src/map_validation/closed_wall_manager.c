/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/19 16:39:57 by umeneses         ###   ########.fr       */
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
	arr = map->gamemap;
	while (arr[y][x] && arr[y][x] == tofind && arr[y + 2]
		&& goto_arr_bondary(arr, &y, &x, tofind))
	{
		if (!arr[y + 2][0] && middle_last_line_checker(arr, y, x, tofind))
			return (true);
		if ((arr[y - 1][x] == tofind && arr[y + 1][x] == tofind)
			|| arr[y + 1][x + 1] == tofind
			|| middle_max_boundary(arr, y, x, tofind)) // max boundary
		{
			if (!arr[y + 2][0])
				return (true);
			y++;
			x = 0;
			continue ;
		}
		else
			break ;
	}
	ft_putstr_fd(RED"Your MAP has a breach on the middle wall", STDOUT_FILENO);
	return (false);
}

bool	goto_arr_bondary(char **arr, int *y, int *x, char tofind)
{
	while (arr[*y][*x + 1])
		*x = *x + 1;
	if (arr[*y][*x] == tofind)
		return (true);
	return (false);
}

bool	middle_last_line_checker(char **arr, int y, int x, char tofind)
{
	if (arr[y][x] == tofind && !arr[y + 2][0]) // last middle line
	{
		if (arr[y - 1][x + 1] && arr[y - 1][x + 1] == tofind) // check if previous line with next char is closed
		{
			while (arr[y][x] == tofind)
					x--;
			if (arr[y + 1][x] == tofind)
				return (true);
		}
	}
	return (false);
}

bool	middle_max_boundary(char **arr, int y, int x, char tofind)
{
	if (!arr[y + 1][x] && !arr[y - 1][x]
		&& arr[y - 1][x - 1] == tofind
		&& arr[y + 1][x - 1] == tofind)
		return (true);
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
