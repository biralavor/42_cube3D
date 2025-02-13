/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 13:13:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error_msg("Map Memory Allocation failed\n");
	memory_struct_init(map);
	if(map_opener(ac, av, map)
		&& map_validation_manager(av, map))
	{
		printf(GRE"\n\n>>>>>> Hello, Cube3D!\n"RESET);
	}
	else
	{
		clear_all_exit_smoothly(map);
		ft_error_msg("Map validation failed\n");
	}
	clear_all_exit_smoothly(map);
	exit(EXIT_SUCCESS);
}
