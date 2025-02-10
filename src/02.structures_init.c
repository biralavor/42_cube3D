/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.structures_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:23:56 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/12 13:23:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	structures_init(t_map *map)
{
	int	idx;

	idx = -1;
	map->gamemap = (char **)ft_calloc(MAX_MAP_HEIGHT, sizeof(char *));
	map->ggraph = (char **)ft_calloc(MAX_TEXTURE_PATH, sizeof(char *));
	map->colors = (char **)ft_calloc(15, sizeof(char *));
	if (!map->gamemap || !map->ggraph  || !map->colors)
		ft_error_msg("Malloc failed at structures init\n");
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
	while (++idx < 8)
	{
		map->colors[idx] = (char *)ft_calloc(15, sizeof(char));
		if (!map->colors[idx])
			ft_error_msg("Malloc failed at colors columns\n");
	}
}
