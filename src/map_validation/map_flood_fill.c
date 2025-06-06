/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:20:53 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 16:27:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	flood_fill_it(char **map, int x, int y, t_flood_dim *dim)
{
	if (x < 0 || y < 0 || x >= dim->width || y >= dim->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_it(map, x + 1, y, dim);
	flood_fill_it(map, x - 1, y, dim);
	flood_fill_it(map, x, y + 1, dim);
	flood_fill_it(map, x, y - 1, dim);
}
