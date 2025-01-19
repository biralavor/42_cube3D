/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/19 18:57:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation_manager(char **av, t_map *map)
{
	if (map_file_checker(av, map)
		&& map_player_checker(map)
		&& closed_wall_manager(map)
		&& no_garbage_checker(map))
	{
		printf(GREEN"\nGame Map approved!\n");
		map_printer(map);
		return (true);
	}
	return(false);
}

bool	map_file_checker(char **av, t_map *map)
{
	if (valid_extension_checker(av)
		&& map_reader(map))
	{
		map_structs_init(map);
		if (unique_def_compass(map)
			&& nothing_aftermap(map))
			return (true);
	}
	return(false);
}

bool	map_player_checker(t_map *map)
{
	if (player_detected(map)
		&& player_free_to_go(map))
		return (true);
	return (false);
}

bool	closed_wall_manager(t_map *map)
{
	char	w;

	w = '1';
	if (top_wall_finder(map, w)
		&& middle_wall_finder(map, w)
		&& bottom_wall_finder(map, w))
		return (true);
	return (false);
}

bool	no_garbage_checker(t_map *map)
{
	if (no_garbage_at_gamemap(map))
		return (true);
	ft_putstr_fd(RED"Garbage inside GameMap detected", STDERR_FILENO);
	return (false);
}
