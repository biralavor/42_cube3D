/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_wall_manager.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:52:38 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/21 20:05:06 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLOSED_WALL_MANAGER_H
# define MAP_CLOSED_WALL_MANAGER_H

/**
 * @brief Check if the map is closed by walls, by dividing the map in 3 parts
 *			(top, middle, bottom) and checking if there is a wall in each part.
 * @param  t_map *map struct with all map data
 * @return `bool` true if the map is closed by walls, false otherwise
 */
bool	closed_wall_manager(t_map *map);

/**
 * @brief Check if the top part of the map is closed by walls.
 * @param  arr array to be checked
 * @param  tofind character to be found
 * @return `bool` true if the top part of the map is closed by walls,
 * 			false otherwise
 */
bool	top_wall_finder(char **arr, char tofind);

/**
 * @brief Check if the middle part of the map is closed by walls. To do so,
 * 				it calls the subfunctions `goto_arr_bondary`,
 * 				`middle_last_line_checker` and `middle_max_boundary`.
 * @param  arr array to be checked
 * @param  tofind character to be found
 * @return `bool` true if the middle part of the map is closed by walls,
 * 			false otherwise
 */
bool	middle_wall_finder(char **arr, char tofind);

/**
 * @brief Read the array until the end of the line. If the line ends with
 * 			the character tofind, it returns true, otherwise false.
 * @param  arr array to be checked
 * @param  y y position in the array, to be checked
 * @param  x x position in the array, to be checked
 * @param  tofind character to be found
 * @return `bool` true if the line ends with the character tofind,
 * 			false otherwise
 */
bool	goto_arr_bondary(char **arr, int *y, int *x, char tofind);

/**
 * @brief Check if the last line of the middle part of the map
 * 			is closed by walls. To do so, it reads the line until the end
 * 			and checks if the last character is the character tofind.
 * @param  arr array to be checked
 * @param  y y position in the array, to be checked
 * @param  x x position in the array, to be checked
 * @param  tofind character to be found
 * @return `bool` true if the last line of the middle part of the map
 * 			is closed by walls, false otherwise
 */
bool	middle_last_line_checker(char **arr, int y, int x, char tofind);

/**
 * @brief For non-rectangular maps, it detects the line with the maximum
 * 			length and checks if it is closed by walls.
 * @param  arr array to be checked
 * @param  y y position in the array, to be checked
 * @param  x x position in the array, to be checked
 * @param  tofind character to be found
 * @return `bool` true if the middle part of the map is closed by walls,
 * 			false otherwise
 */
bool	middle_max_boundary(char **arr, int y, int x, char tofind);

/**
 * @brief Check if the bottom part of the map is closed by walls.
 * @param  arr array to be checked
 * @param  tofind character to be found
 * @return `bool` true if the bottom part of the map is closed by walls,
 * 			false otherwise
 */
bool	bottom_wall_finder(char **arr, char tofind);

#endif
