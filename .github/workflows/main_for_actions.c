/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/17 19:12:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	gamemap_init(map);

	if(map_validation_manager(ac, av, map))
	{
		printf(GREEN"\n\nHello, Cube3D!\n"RESET);
	}
	else
		ft_error_msg("Map validation failed\n");

	exit(EXIT_SUCCESS);
}
