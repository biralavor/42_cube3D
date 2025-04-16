/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/16 00:27:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	map = ft_calloc(1, sizeof(t_map));
	game = ft_calloc(1, sizeof(t_game));
	if (!map)
		ft_error_msg("Map Memory Allocation failed\n");
	struct_memory_alloc(map);
	if (map_opener(ac, av, map)
		&& map_validation_manager(av, map))
	{
		printf(GRE"\n\n>>>>>> Hello, Cube3D!\n"RESET);
		game->map = *map;
		if (setup_init(game) == -1)
		{
			clear_all_exit_smoothly(map);
			ft_error_msg("Erro na inicialização gráfica");
		}
	}
	else
	{
		clear_all_exit_smoothly(map);
		ft_error_msg("Map validation failed\n");
	}
	exit(EXIT_SUCCESS);
}
