/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/08 17:53:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation(int ac, char **av, t_map *map)
{
	if (map_opener(ac, av, map)
		&& map_reader(map))
	{
		//check_extension_valid(map);
		//check_file_content_map(map);
		// add map functions here
		map_printer(map);
		return (true);
	}
		
	return(false);
}
