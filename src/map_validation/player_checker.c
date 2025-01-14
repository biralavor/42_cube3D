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