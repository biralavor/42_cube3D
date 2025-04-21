/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/21 14:30:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		free(game);
		ft_error_msg("Map Memory Allocation failed\n");
	}
	struct_memory_alloc(game->map);
	if (map_opener(ac, av, game->map)
		&& map_validation_manager(av, game->map))
	{
		printf(GRE"\n\n>>>>>> Hello, Cube3D!\n"RESET);
		if (setup_init(game) == -1)
		{
			clear_all_exit_smoothly(game->map);
			ft_error_msg("Erro na inicialização gráfica");
		}
	}
	else
	{
		clear_all_exit_smoothly(game->map);
		ft_error_msg("Map validation failed\n");
	}
	exit(EXIT_SUCCESS);
}
