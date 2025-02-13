/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.mem_struct_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:54:40 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 14:54:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	inside_pointers_alloc(char **array, int idx, int size,
				int alloc_nitems);

void	struct_memory_alloc(t_map *map)
{
	int	idx;

	map->gamemap = (char **)ft_calloc(MAX_MAP_HEIGHT + 1, sizeof(char *));
	map->ggraph = (char **)ft_calloc(MAX_TEXTURE_PATH, sizeof(char *));
	map->colors = (char **)ft_calloc(MAX_COLOR_DIGIT, sizeof(char *));
	if (!map->gamemap || !map->ggraph || !map->colors)
		ft_error_msg("Malloc failed at memory struct init\n");
	idx = -1;
	inside_pointers_alloc(map->gamemap, idx, MAX_MAP_HEIGHT, MAX_MAP_WIDTH);
	idx = -1;
	inside_pointers_alloc(map->ggraph, idx, 4, MAX_TEXTURE_PATH);
	idx = -1;
	inside_pointers_alloc(map->colors, idx, 4, MAX_COLOR_DIGIT);
}

static void	inside_pointers_alloc(char **array, int idx, int size,
				int alloc_nitems)
{
	while (++idx < size)
	{
		array[idx] = (char *)ft_calloc(alloc_nitems, sizeof(char));
		if (!array[idx])
			ft_error_msg("Malloc failed at inside pointers alloc\n");
	}
}
