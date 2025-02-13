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

void	memory_struct_init(t_map *map)
{
	int	idx;

	map->gamemap = (char **)ft_calloc(MAX_MAP_HEIGHT + 1, sizeof(char *));
	map->ggraph = (char **)ft_calloc(MAX_TEXTURE_PATH, sizeof(char *));
	map->colors = (char **)ft_calloc(MAX_COLOR_DIGIT, sizeof(char *));
	if (!map->gamemap || !map->ggraph || !map->colors)
		ft_error_msg("Malloc failed at memory struct init\n");
	idx = -1;
	while (++idx < MAX_MAP_HEIGHT)
	{
		map->gamemap[idx] = (char *)ft_calloc(MAX_MAP_WIDTH, sizeof(char));
		if (!map->gamemap[idx])
			ft_error_msg("Malloc failed at gamemap columns\n");
	}
	idx = -1;
	while (++idx < 4)
	{
		map->ggraph[idx] = (char *)ft_calloc(MAX_TEXTURE_PATH, sizeof(char));
		if (!map->ggraph[idx])
			ft_error_msg("Malloc failed at gamegraph columns\n");
	}
	idx = -1;
	while (++idx < 4)
	{
		map->colors[idx] = (char *)ft_calloc(MAX_COLOR_DIGIT, sizeof(char));
		if (!map->colors[idx])
			ft_error_msg("Malloc failed at colors columns\n");
	}
}
