/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_garbage_manager_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:27:18 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:27:18 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

static bool	garbage_inside_gamemap_detected(char **arr, int x, int y);

bool	no_garbage_manager(t_map *map)
{
	if (no_garbage_at_texture(map->ggraph)
		&& no_garbage_at_gamemap(map->gamemap))
		return (true);
	return (false);
}

bool	no_garbage_at_texture(char **arr)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (arr[y][x] != '\0')
	{
		if ((arr[y][x] == 'N' && arr[y][x + 1] == 'O')
			|| (arr[y][x] == 'S' && arr[y][x + 1] == 'O')
			|| (arr[y][x] == 'W' && arr[y][x + 1] == 'E')
			|| (arr[y][x] == 'E' && arr[y][x + 1] == 'A'))
		{
			if (y == 3)
				return (true);
			y++;
		}
		else
			break ;
	}
	ft_putstr_fd(YEL"Garbage inside Textures detected", STDERR_FILENO);
	return (false);
}

bool	no_garbage_at_gamemap(char **arr)
{
	int	y;
	int	x;

	y = -1;
	while (arr[++y])
	{
		x = -1;
		while (arr[y][++x])
		{
			if (garbage_inside_gamemap_detected(arr, x, y))
				return (false);
			if (arr[y] && x + 1 < (int)ft_strlen(arr[y])
				&& arr[y][x + 1] == '\0'
				&& arr[y + 1] && arr[y + 1][0])
			{
				if (x >= 2 && arr[y][x - 1] && arr[y][x - 2]
					&& arr[y][x - 1] == '1' && arr[y][x - 2] == '1'
					&& y >= 1 && arr[y - 1] && arr[y - 1][x] == '1')
					continue ;
			}
		}
	}
	return (true);
}

static bool	garbage_inside_gamemap_detected(char **arr, int x, int y)
{
	char	c;

	c = arr[y][x];
	if (c != '1' && c != '0' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E' && c != '2' && c != ' ')
	{
		ft_putstr_fd(YEL"Garbage inside GameMap detected\n", STDERR_FILENO);
		return (true);
	}
	return (false);
}
