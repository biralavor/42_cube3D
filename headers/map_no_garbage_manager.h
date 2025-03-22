/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_no_garbage_manager.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:30:11 by umeneses          #+#    #+#             */
/*   Updated: 2025/03/21 20:04:37 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NO_GARBAGE_MANAGER_H
# define MAP_NO_GARBAGE_MANAGER_H

/**
 * @brief Check if there is no garbage inside the entire map file. To do so,
 * 			it calls the functions `no_garbage_at_gamemap` and
 * 			`no_garbage_at_texture`.
 * @param  map struct with all map data
 * @return `bool` true if there is no garbage, false otherwise
 */
bool	no_garbage_manager(t_map *map);

/**
 * @brief Check if `map->ggraph` has no garbage inside, by verifying if all
 * 			the texture paths are there, without non-expected data.
 * @param  arr array with all the texture paths
 * @return `bool` true if there is no garbage, false otherwise
 */
bool	no_garbage_at_texture(char **arr);

/**
 * @brief Check if `map->gamemap` has no garbage inside, by verifying if all
 * 			the map data is there, without non-expected data.
 * @param  arr array with all the map data
 * @return `bool` true if there is no garbage, false otherwise
 */
bool	no_garbage_at_gamemap(char **arr);

#endif
