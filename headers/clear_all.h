/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:08:51 by umeneses          #+#    #+#             */
/*   Updated: 2025/03/21 20:05:17 by gigardin         ###   ########.fr       */
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
