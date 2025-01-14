/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/14 19:03:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation_manager(int ac, char **av, t_map *map)
{
	if (map_file_checker(ac, av, map))
	{
		map_printer(map);
		return (true);
	}
	return(false);
}

bool	map_file_checker(int ac, char **av, t_map *map)
{
	if (map_opener(ac, av, map)
		&& map_reader(map)
		&& unique_def_compass(map)
		&& valid_extension_checker(av)
		&& no_garbage_checker(map))
		return (true);
	return(false);
}