/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/20 19:16:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation_manager(char **av, t_map *map)
{
	if (map_file_checker(av, map)
		&& map_player_checker(map)
		&& closed_wall_manager(map)
		&& no_garbage_checker(map)
		&& map_colors_manager(map))
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

bool	map_colors_manager(t_map *map)
{
	static int	color_digits[6];
	// static int	rgbrgb[6];
	int	id; //

	id = -1; //
	color_digits_counter(map, color_digits);
	while (color_digits[++id])
		printf("Color Digits[%d]: %d\n", id, color_digits[id]);
	if (color_digits_quantity_checker(color_digits))
	{
		printf(GREEN"\nColor Map approved!\n");
		map_array_printer(map->colors);
		return (true);
	}
	// if (no_garbage_at_colors(map, rgbrgb))
	// {
	// 	printf(GREEN"\nColor Map approved!\n");
	// 	map_array_printer(map->colors);
	// 	return (true);
	// }
	return (false);
}

bool	no_garbage_checker(t_map *map)
{
	if (no_garbage_at_gamemap(map))
		return (true);
	return (false);
}
