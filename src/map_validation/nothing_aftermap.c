/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing_aftermap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:57:59 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 14:20:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	nothing_aftermap(t_map *map)
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
			if (arr[y][x] && (arr[y][x] == '1' || arr[y][x] == '0')
				&& (x - 2) > 0 && arr[y][x - 1] && arr[y][x - 1] == '1'
				&& arr[y][x - 2] && arr[y][x - 2] == '1' && y > 2
				&& arr[y - 1][x] && arr[y - 1][x] == '1'
				&& (!arr[y][x + 1] || arr[y][x + 1] == '\n'))
			{
				if ((!arr[y][x + 1] || arr[y + 1][0] == '\n')
					&& linebreak_reader(arr, y, x))
					return (true);
				else if (!arr[y][x + 1] && !arr[y + 1][0])
					return (true);
			}
		}
	}
	ft_putstr_fd(YEL"Your should have nothing after the gamemap :(", \
		STDERR_FILENO);
	return (false);
}

bool	linebreak_reader(char **arr, int y, int x)
{
	(void)x;
	
	while (arr[++y][0] == '\n')
	{
		if (!arr[y][1] && !arr[y + 1][0] && !arr[y + 1][1])
			return (true);
		else if (arr[y + 1][0] != '\n')
			break ;
	}
	return (false);
}
