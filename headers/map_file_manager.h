/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_manager.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/15 20:25:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MAP_FILE_MANAGER_H
# define MAP_FILE_MANAGER_H

/**
 * @brief Check if the map is valid, by calling several functions
 * 			like: map_file_manager, map_player_manager, closed_wall_manager,
 * 			no_garbage_manager, texture_path_manager, map_colors_manager
 * @param  av argument vector
 * @param  map struct with all map data
 * @return `bool` true if the map is valid, false otherwise
 */
bool	map_validation_manager(char **av, t_map *map);

/**
 * @brief Call a few functions to valide the map as a file, like:
 * 			valid_extension_checker, map_reader, map_structs_init,
 * 			unique_def_compass, nothing_aftermap
 * @param  av argument vector
 * @param  map struct with all map data
 * @return `bool` true if the map is valid as a file, false otherwise
 */
bool	map_file_manager(char **av, t_map *map);

/**
 * @brief Check the extension of the map file. It should be '*.cub'
 * @param  av argument vector
 * @param  map struct with all map data
 * @return `bool` true if the extension is valid, false otherwise
 */
bool	valid_extension_checker(char **av, t_map *map);

/**
 * @brief Read the map file and store it in the struct (map->buffer)
 * @param  map struct with all map data
 * @return `bool` true if the map was read successfully, false otherwise
 */
bool	map_reader(t_map *map);

/**
 * @brief Store data at gamegraph, colors and gamemap from the buffer
 * @param  map struct with all map data
 * @return `void`
 */
void	map_structs_init(t_map *map);

/**
 * @brief Read the map file, skipping all the data except the colors, and
 * 			returns the index of `map->buffer`
 * @param  map struct with all map data
 * @return `int` index of `map->buffer`
 */
int		skipping_all_except_colors(t_map *map);

/**
 * @brief Read the map file, skipping all the data except the gamemap, and
 * 			returns the index of `map->buffer`
 * @param  map struct with all map data
 * @return `int` index of `map->buffer`
 */
int		skipping_all_except_gamemap(t_map *map);

/**
 * @brief Store the gamegraph data from the buffer into the gamegraph array
 * @param  map struct with all map data
 * @return `void`
 */
void	gamegraph_into_array(t_map *map);

/**
 * @brief Store the colors data from the buffer into the colors array
 * @param  map struct with all map data
 * @return `void`
 */
void	colorsmap_into_array(t_map *map);

/**
 * @brief Store the gamemap data from the buffer into the gamemap array
 * @param  map struct with all map data
 * @return `void`
 */
void	gamemap_into_array(t_map *map);		

/**
 * @brief Check if the compass definitions are unique in the map. It calls
 * 			all the fourth compass rose functions (north, south, west, east).
 * @param  map struct with all map data
 * @return `bool` true if the compass definitions are not duplicated,
 * 			or not defined, false otherwise
 */
bool	unique_def_compass(t_map *map);

/**
 * @brief Check if the compass rose 'N' is defined only once in the map
 * @param  map struct with all map data
 * @param  already_found array with the compass rose found
 * @return `bool` true if the compass rose 'N' is defined only once,
 * 			false otherwise
 */
bool	north_compass_datafinder(t_map *map, int *already_found);

/**
 * @brief Check if the compass rose 'S' is defined only once in the map
 * @param  map struct with all map data
 * @param  already_found array with the compass rose found
 * @return `bool` true if the compass rose 'S' is defined only once,
 * 			false otherwise
 */
bool	south_compass_datafinder(t_map *map, int *already_found);

/**
 * @brief Check if the compass rose 'W' is defined only once in the map
 * @param  map struct with all map data
 * @param  already_found array with the compass rose found
 * @return `bool` true if the compass rose 'E' is defined only once,
 * 			false otherwise
 */
bool	west_compass_datafinder(t_map *map, int *already_found);

/**
 * @brief Check if the compass rose 'E' is defined only once in the map
 * @param  map struct with all map data
 * @param  already_found array with the compass rose found
 * @return `bool` true if the compass rose 'E' is defined only once,
 * 			false otherwise
 */
bool	east_compass_datafinder(t_map *map, int *already_found);

/**
 * @brief Check if there is nothing after the map in the buffer
 * @param  arr array with the map data
 * @return `bool` true if there is nothing after the map, false otherwise
 */
bool	nothing_aftermap(char **arr);

#endif
