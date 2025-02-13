/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_middlewall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 17:12:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	middle_wall_finder(char **arr, char w)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
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
