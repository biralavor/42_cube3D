/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_checker_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:58:26 by gigardin          #+#    #+#             */
/*   Updated: 2025/01/16 20:36:49 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	south_compass_datafinder(t_map *map, int *already_found)
{
	int		idx;
	int		check_path;
	char	*texture;

	idx = -1;
	while (map->buffer[++idx])
	{
		if (map->buffer[idx] == 'N' && map->buffer[idx + 1] == 'O')
		{
			if (map->buffer[idx] == ' ')
			{
				while(map->buffer[idx] != ' ')
					idx++;
			}
			while (map->buffer[idx] != '\0')
			{
				texture[idx]= map->buffer[idx];
				idx++;
				return (true);
			}
			check_path = open(texture, O_WRONLY);
			if (check_path > 0)
			{
				already_found[0]++;
				break ;
				return (true);
			}
		}
	}
	ft_error_msg("No valid path found for 'SO' in map file\n");
	return (false);
}
