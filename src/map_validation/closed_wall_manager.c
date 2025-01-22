/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/19 18:57:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	top_wall_finder(t_map *map, char w)
{
	int		x;
	char	**arr;

	x = 0;
	arr = map->gamemap;
	if (arr[0][x] == w)
	{
		while (arr[0][++x] && arr[0][x] == w)
		{
			if (!arr[0][x + 1])
				return (true);
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the top wall", STDOUT_FILENO);
	return (false);
}

bool	middle_wall_finder(t_map *map, char w)
{
	int		y;
	int		x;
	char	**arr;

	y = 1;
	x = 0;
	arr = map->gamemap;
	while (arr[y][x] && arr[y][x] == w && arr[y + 2]
		&& goto_arr_bondary(arr, &y, &x, w))
	{
		if (!arr[y + 2][0] && middle_last_line_checker(arr, y, x, w))
			return (true);
		if (y == 1 || (arr[y - 1][x] == w && arr[y + 1][x] == w)
			|| arr[y + 1][x + 1] == w || middle_max_boundary(arr, y, x, w))
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

bool	goto_arr_bondary(char **arr, int *y, int *x, char w)
{
	while (arr[*y][*x + 1])
		*x = *x + 1;
	if (arr[*y][*x] == w && !arr[*y + 2][0])
		return (true);
	else if (arr[*y][*x] == w && (arr[*y - 1][*x - 1] == w
		|| arr[*y - 1][*x] == w))
		return (true);
	else if (arr[*y][*x] == w && (!arr[*y - 1][*x - 1] || !arr[*y - 1][*x]))
	{
		while (arr[*y][*x] == w)
			*x = *x - 1;
		if (arr[*y - 1][*x] == w)
			return (true);
	}
	return (false);
}

bool	middle_last_line_checker(char **arr, int y, int x, char w)
{
	if (arr[y][x] == w && !arr[y + 2][0])
	{
		if ((arr[y - 1][x] == w && !arr[y - 1][x + 1])
			|| (arr[y - 1][x + 1] && arr[y - 1][x + 1] == w))
		{
			while (arr[y][x] == w)
				x--;
			if (arr[y + 1][x] == w)
				return (true);
		}
	}
	return (false);
}

bool	middle_max_boundary(char **arr, int y, int x, char w)
{
	if (!arr[y + 1][x] && !arr[y - 1][x]
		&& arr[y - 1][x - 1] == w && arr[y + 1][x - 1] == w)
		return (true);
	return (false);
}

bool	bottom_wall_finder(t_map *map, char w)
{
	int		y;
	int		x;
	char	**arr;

	y = 0;
	x = 0;
	arr = map->gamemap;
	while (arr[y][x] && arr[y + 1][x] && arr[y + 1][x] != '\n')
		y++;
	if (arr[y][x] == w)
	{
		while (arr[y][x] && arr[y][x] == w)
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
