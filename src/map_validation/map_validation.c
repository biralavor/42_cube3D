/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/15 20:35:24 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

bool	map_validation_manager(char **av, t_map *map)
{
	if (map_file_manager(av, map)
		&& map_player_manager(map)
		&& closed_wall_manager(map)
		&& no_garbage_manager(map)
		&& texture_path_manager(map)
		&& map_colors_manager(map))
	{
		printf(GRE"✅ Game Map \t\tapproved!\n");
		map_printer(map);
		return (true);
	}
	return (false);
}

bool	map_file_manager(char **av, t_map *map)
{
	if (valid_extension_checker(av, map)
		&& map_reader(map))
	{
		map_structs_init(map);
		if (unique_def_compass(map)
			&& nothing_aftermap(map->gamemap))
			return (true);
	}
	return (false);
}

bool	map_player_manager(t_map *map)
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
	if (top_wall_finder(map->gamemap, w)
		&& middle_wall_finder(map->gamemap, w)
		&& bottom_wall_finder(map->gamemap, w))
		return (true);
	return (false);
}
