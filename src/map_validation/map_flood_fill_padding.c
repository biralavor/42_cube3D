/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:20:53 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 18:30:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**create_padded_map_at_top(t_map *map)
{
	char	**padded_map;

	padded_map = ft_calloc(map->max_height + 3, sizeof(char *));
	if (!padded_map)
		display_alloc_error_msg(padded_map, "Memory alloc failed at padded map\n");
	padded_map[map->max_height + 2] = NULL;
	padded_map[0] = ft_calloc(map->max_width + 2, sizeof(char));
	if (!padded_map[0])
		display_alloc_error_msg(padded_map, "Memory alloc failed at padded map\n");
	ft_memset(padded_map[0], 'S', map->max_width + 1);
	padded_map[0][map->max_width + 1] = '\0';
	return (padded_map);
}

char	**create_padded_map_at_middle(t_map *map, char **padded_map)
{
	int	actual_width;
	int	idx;

	idx = 0;
	while (idx < map->max_height)
	{
		actual_width = ft_strlen(map->gamemap[idx]);
		padded_map[idx + 1] = ft_calloc(map->max_width + 2, sizeof(char));
		if (!padded_map[idx + 1])
			display_alloc_error_msg(padded_map, "Memory alloc failed at padded map\n");
		padded_map[idx + 1][0] = 'S';
		copy_map_data_and_fill_spaces(map, padded_map, idx, actual_width);
		padded_map[idx + 1][map->max_width + 1] = '\0';
		idx++;
	}
	return (padded_map);
}

void	copy_map_data_and_fill_spaces(t_map *map, char **padded_map,
			int idx, int actual_width)
{
	int	jdx;

	jdx = 0;
	while (jdx < actual_width)
	{
		padded_map[idx + 1][jdx + 1] = map->gamemap[idx][jdx];
		jdx++;
	}
	jdx = actual_width;
	while (jdx < map->max_width)
	{
		padded_map[idx + 1][jdx + 1] = 'S';
		jdx++;
	}
}

char	**create_padded_map_at_bottom(t_map *map, char **padded_map)
{
	padded_map[map->max_height + 1] = ft_calloc(map->max_width + 2,
			sizeof(char));
	if (!padded_map[map->max_height + 1])
		display_alloc_error_msg(padded_map, "Memory alloc failed at padded map\n");
	ft_memset(padded_map[map->max_height + 1], 'S', map->max_width + 1);
	padded_map[map->max_height + 1][map->max_width + 1] = '\0';
	return (padded_map);
}
