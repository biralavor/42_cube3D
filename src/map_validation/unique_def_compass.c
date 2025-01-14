/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_def_compass.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:27:15 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/07 16:27:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	unique_def_compass(t_map *map)
{
	static int already_found[5];

	if (north_compass_datafinder(map, already_found)
		&& south_compass_datafinder(map, already_found)
		&& west_compass_datafinder(map, already_found)
		&& east_compass_datafinder(map, already_found)
		&& nothing_aftermap(map, already_found))
	{
		if (already_found[0] == 1 && already_found[1] == 1
			&& already_found[2] == 1 && already_found[3] == 1
			&& already_found[4] == 1)
				return (true);
	}
	ft_error_msg("Not unique definitions for compass points detected\n");
	return (false);
}
