/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:08:51 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/18 10:09:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_ALL_H
# define CLEAR_ALL_H

/**
 * @brief Free the memory allocated for the entire struct (map->gamemap,
 * 			map->ggraph, map->colors).
 * @param  map struct with all map data
 * @return `void`
 */
void	clear_all_exit_smoothly(t_map *map);

#endif