/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_garbage_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:48:01 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/08 18:48:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	while (arr[++y][0] != '\0')
	{
		x = -1;
		while (arr[y][++x])
		{
			if (garbage_inside_gamemap_detected(arr, x, y))
				return (false);
			if (arr[y][x] && (arr[y][x] == '1' || arr[y][x] == '0')
				&& (x - 1) > 0 && arr[y][x - 1] && arr[y][x - 1] == '1'
				&& (x - 2) > 0 && arr[y][x - 2] && arr[y][x - 2] == '1'
				&& y > 2 && arr[y - 1][x] == '1' && (arr[y][x + 1] == '\n'
				|| !arr[y][x + 1]))
				return (true);
			else if (arr[y][x + 1] == '\0' && arr[y + 1][0])
				break ;
		}
	}
	ft_putstr_fd(YEL"Garbage inside GameMap detected", STDERR_FILENO);
	return (false);
}

static bool	garbage_inside_gamemap_detected(char **arr, int x, int y)
{
	if (arr[y][x] != '1' && arr[y][x] != '0' && arr[y][x] != 'N'
		&& arr[y][x] != 'S' && arr[y][x] != 'W' && arr[y][x] != 'E'
		&& arr[y][x] != '2')
	{
		ft_putstr_fd(YEL"Garbage inside GameMap "
			"detected", STDERR_FILENO);
		return (true);
	}
	return (false);
}
