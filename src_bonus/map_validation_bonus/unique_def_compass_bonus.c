/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_def_compass_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:28:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:28:07 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

bool	unique_def_compass(t_map *map)
{
	static int	already_found[4];

	if (north_compass_datafinder(map, already_found)
		&& south_compass_datafinder(map, already_found)
		&& west_compass_datafinder(map, already_found)
		&& east_compass_datafinder(map, already_found))
	{
		if (already_found[0] == 1 && already_found[1] == 1
			&& already_found[2] == 1 && already_found[3] == 1)
			return (true);
	}
	ft_putstr_fd(YEL"Not unique definitions for "
		"compass points detected", STDERR_FILENO);
	return (false);
}
