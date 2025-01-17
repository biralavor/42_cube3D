/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/17 11:16:28 by umeneses         ###   ########.fr       */
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
	int	x;

	x = 0;
	if (map->gamemap[0][x] == tofind)
	{
		while (map->gamemap[0][++x] && map->gamemap[0][x] == tofind)
		{
			if (!map->gamemap[0][x + 1])
				return (true);
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the top wall", STDOUT_FILENO);
	return (false);
}

bool	middle_wall_finder(t_map *map, char tofind)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (map->gamemap[y][x] && map->gamemap[y][x] == tofind
		&& map->gamemap[y + 2])
	{
		while (map->gamemap[y][x + 1])
			x++;
		if (map->gamemap[y][x] == tofind)
		{
			if (map->gamemap[y + 2][x] == '\0')
				return (true);
		}
		else if (map->gamemap[y][x] != tofind)
			break ;
		y++;
		x = 0;
	}
	ft_putstr_fd(RED"Your MAP has a breach on the middle wall", STDOUT_FILENO);
	return (false);
}

bool	bottom_wall_finder(t_map *map, char tofind)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->gamemap[y][x] && map->gamemap[y + 1][x])
		y++;
	if (map->gamemap[y][x] == tofind)
	{	
		while (map->gamemap[y][x] && map->gamemap[y][x] == tofind)
		{
			if (!map->gamemap[y][x + 1])
				return (true);
			x++;
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the bottom wall", STDOUT_FILENO);
	return (false);
}
