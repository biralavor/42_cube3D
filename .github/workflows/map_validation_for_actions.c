/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_for_actions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/14 20:26:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation_manager(int ac, char **av, t_map *map)
{
	if (map_file_checker(ac, av, map)
		&& map_player_checker(map))
	{
		printf(GREEN"Game Map approved!\n");
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

bool	map_player_checker(t_map *map)
{
	if (player_detected(map))
	{
		return (true);
	}
	return (false);
}
