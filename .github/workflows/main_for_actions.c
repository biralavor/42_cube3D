/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/11 17:26:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error_msg("Map Memory Allocation failed\n");
	structures_init(map);
	if(map_opener(ac, av, map)
		&& map_validation_manager(av, map))
	{
		printf(GREEN"\n\n>>>>>> Hello, Cube3D!\n"RESET);
	}
	else
	{
		clear_all_exit_smoothly(map);
		ft_error_msg("Map validation failed\n");
	}
	clear_all_exit_smoothly(map);
	exit(EXIT_SUCCESS);
}
