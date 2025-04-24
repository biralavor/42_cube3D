/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:08:32 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 20:54:17 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	map_printer(t_map *map)
{
	if (map->buffer)
	{
		ft_printf(CYA"\nThis is your MAP:\n"RESET);
		write(STDOUT_FILENO, map->buffer, map->bytes_read);
	}
}
