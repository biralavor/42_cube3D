/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/21 14:34:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

void	clear_all_exit_smoothly(t_game *game)
{
	ft_free_array(game->map->colors);
	ft_free_array(game->map->ggraph);
	ft_free_array(game->map->gamemap);
	free(game->map->buffer);
	free(game->map);
	free(game);
}
