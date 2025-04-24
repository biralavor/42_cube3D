/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_skippers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:13:19 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 20:54:31 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	skipping_all_except_colors(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->buffer[idx] != 'F')
		idx++;
	return (idx);
}

int	skipping_all_except_gamemap(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->buffer[idx])
	{
		if (map->buffer[idx] == 'C')
		{
			while (map->buffer[idx] != '\n')
				idx++;
			if (map->buffer[idx] == '\n')
			{
				while (map->buffer[idx] == '\n')
					idx++;
				return (idx);
			}
		}
		idx++;
	}
	return (-1);
}
