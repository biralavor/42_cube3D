/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_manager.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/21 20:04:42 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PLAYER_MANAGER_H
# define MAP_PLAYER_MANAGER_H

/**
 * @brief Check if the player is detected in the map, and also
 * 			if the player is free to go.
 * @param  map struct with all map data
 * @return `bool` true if the player is detected and free to go,
 * 			false otherwise
 */
bool	map_player_manager(t_map *map);

/**
 * @brief Check if the player is detected in the map.
 * @param  map struct with all map data
 * @return `bool` true if the player is detected, false otherwise
 */
bool	player_detected(t_map *map);

/**
 * @brief Check if the player is free to go. In other words, check if
 * 				the player is NOT surrounded by walls. To do so, it needs to
 * 				copy the player position into the struct, and then check
 * 				what is surrounding the player.
 * @param  map struct with all map data
 * @return `bool` true if the player is free to go, false otherwise
 */
bool	player_free_to_go(t_map *map);

/**
 * @brief Copy player position into the struct (map->player_pos_y
 * 			and map->player_pos_x), from the game map.
 * @param  map struct with all map data
 * @return `void`
 */
void	player_position_into_struct(t_map *map);

/**
 * @brief Count the number of detected walls the player has around.
 * @param  map struct with all map data
 * @param  arr game map array
 * @param  y y position of the player, to be used while reading the array
 * @param  x x position of the player, to be used while reading the array
 * @return `int` number of detected walls
 */
int		player_boundary_finder(t_map *map, char **arr, int y, int x);

#endif
