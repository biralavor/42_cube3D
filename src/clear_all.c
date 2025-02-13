/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 14:47:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	clear_all_exit_smoothly(t_map *map)
{
	ft_free_array(map->colors);
	ft_free_array(map->ggraph);
	ft_free_array(map->gamemap);
	free(map->buffer);
	free(map);
}
