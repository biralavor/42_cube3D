/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/08 19:00:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation(int ac, char **av, t_map *map)
{
	if (map_opener(ac, av, map)
		&& map_reader(map)
		&& unique_def_compass(map)
		&& valid_extension_checker(av))
	{
		// check_file_content_map(map);
		map_printer(map);
		return (true);
	}
		
	return(false);
}
