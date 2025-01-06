/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:56 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation(int ac, char **av, t_map *map)
{
	if (existing_mapfile(ac, av, map))
	{
		check_extension_valid(ac, av, map);
		check_file_content_map(ac, av, map);
		// add map functions here
		return (true);
	}
		
	return(false);
}
