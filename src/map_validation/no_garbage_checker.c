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

bool	no_garbage_at_color_values(char **arr, int *color_digits, int id)
{
	int		y;
	int		x;
	int		digit;

	y = -1;
	while (arr[++y][0])
	{
		digit = 0;
		x = 1;
		while (digit++ <= color_digits[id] && ++x)
		{
			if (ft_isdigit(arr[y][x]) && id == 5 && (arr[y][x + 1] == '\n'
				|| !arr[y][x + 1]))
				return (true);
			if (arr[y][x] == ',' || arr[y][x] == '\n' || !arr[y][x])
			{
				id++;
				digit = 0;
				if (arr[y][x] == '\n' || !arr[y][x])
					break ;
			}
			else if (!ft_isdigit(arr[y][x]))
				return (false);
		}
	}
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
			{
				ft_putstr_fd(YEL"Garbage inside GameMap "
					"detected", STDERR_FILENO);
				return (false);
			}
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

bool	no_garbage_at_texture(t_map *map)
{
	char	**arr;
	int		y;
	int		x;

	arr = map->ggraph;
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
