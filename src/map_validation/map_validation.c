/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 16:31:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_validation_manager(char **av, t_map *map)
{
	if (map_file_checker(av, map)
		&& map_player_checker(map)
		&& closed_wall_manager(map)
		&& no_garbage_checker(map)
		&& texture_path_manager(map)
		&& map_colors_manager(map))
	{
		printf(GRE"✅ Game Map \t\tapproved!\n");
		map_printer(map);
		return (true);
	}
	return (false);
}

bool	map_file_checker(char **av, t_map *map)
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
	static int	rgbrgb[6];
	char		**arr;
	int			id;

	arr = map->colors;
	id = 0;
	color_digits_counter(arr, color_digits);
	if (color_digits_quantity_checker(color_digits))
	{
		if (!no_garbage_at_color_values(arr, color_digits, id))
		{
			ft_putstr_fd(YEL"Garbage inside MapColors detected", STDERR_FILENO);
			return (false);
		}
		if (color_values_into_array(arr, color_digits, rgbrgb)
			&& colors_with_min_max_values(rgbrgb))
		{
			printf(GRE"✅ Color Map \t\tapproved!\n");
			return (true);
		}
	}
	return (false);
}

bool	no_garbage_checker(t_map *map)
{
	if (no_garbage_at_texture(map)
		&& no_garbage_at_gamemap(map))
		return (true);
	return (false);
}
