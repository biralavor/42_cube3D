/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_detector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:05:11 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/14 17:05:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	player_detected(t_map *map)
{
	int		y;
	int		x;
	char	**arr;
	int		player_found;

	y = -1;
	player_found = 0;
	arr = map->gamemap;
	while (arr[++y])
	{
		if (arr[y][0] == '\0' && player_found == 1)
			return (true);
		x = -1;
		while (arr[y][++x])
		{
			if (arr[y][x] == 'N' || arr[y][x] == 'S' || arr[y][x] == 'W'
				|| arr[y][x] == 'E')
				player_found++;
		}
	}
	ft_error_msg("Player not found or more than one player found\n");
	return (false);
}

void	player_position_into_struct(t_map *map)
{
	int		y;
	int		x;
	char	**arr;

	y = -1;
	arr = map->gamemap;
	while (arr[++y])
	{
		x = -1;
		while (arr[y][++x])
		{
			if (arr[y][x] == 'N' || arr[y][x] == 'S' || arr[y][x] == 'W'
				|| arr[y][x] == 'E')
			{
				map->player_pos_y = y;
				map->player_pos_x = x;
				break ;
			}
		}
	}
}

int	player_boundary_finder(t_map *map, char **arr, int y, int x)
{
	int	corners;

	corners = 0;
	if (y + 1 == map->player_pos_y && arr[y][x + 1] == '1')
		corners++;
	else if (y - 1 == map->player_pos_y && arr[y][x + 1] == '1')
		corners++;
	while(y == map->player_pos_y && x < (map->player_pos_x + 2))
	{
		if (arr[y][x] == '1')
			corners++;
		else if (arr[y][x] == 'N' || arr[y][x] == 'S' || arr[y][x] == 'W'
			|| arr[y][x] == 'E')
		{
			x++;
			continue ;
		}
		else
			break ;
		x++;
	}
	return (corners);
}

bool	player_free_to_go(t_map *map)
{
	int		y;
	int		x;
	int		corners;
	char	**arr;

	player_position_into_struct(map);
	y = map->player_pos_y - 1;
	corners = 0;
	arr = map->gamemap;
	while(arr[y] && (y < (map->player_pos_y + 2)))
	{
		x = map->player_pos_x - 1;
		corners += player_boundary_finder(map, arr, y, x);
		y++;
	}
	if (corners < 4)
		return (true);
	ft_putstr_fd(RED"Player is NOT free to go."RESET, STDERR_FILENO);
	return (false);
}
