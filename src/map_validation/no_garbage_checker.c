/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_garbage_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:48:01 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/08 18:48:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	no_garbage_checker(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->buffer[idx] != 1)
	{
		if (map->buffer[idx] == 1 && map->buffer[idx + 1] == 1 && map->buffer[idx - 1] == '\n')
		{
			printf("Game Map starting point found\n");
			return (true);
		}
	}
	return (false);
}
