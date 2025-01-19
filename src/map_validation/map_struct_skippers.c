/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_skippers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:13:19 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/19 19:13:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	skipping_all_except_colors(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->buffer[idx] != 'F')
		idx++;
	if (map->buffer[idx] == 'F')
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
