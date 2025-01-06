/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:08:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 20:18:47 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_printer(t_map *map)
{
	int32_t	y;

	y = -1;
	if (map->buffer)
	{
		ft_printf(CYAN"\nThis is your MAP:\n"RESET);
		write(STDOUT_FILENO, map->buffer, map->bytes_read);
	}
}