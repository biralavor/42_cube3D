/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:25:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:25:07 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		setup_init(game);
	else
	{
		clear_all_exit_smoothly(game);
		ft_error_msg("Map validation failed\n");
	}
	clear_all_exit_smoothly(game);
	exit(EXIT_SUCCESS);
}
