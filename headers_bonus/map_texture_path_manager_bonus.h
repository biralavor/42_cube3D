/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_path_manager_bonus.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:04:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/23 10:38:05 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TEXTURE_PATH_MANAGER_BONUS_H
# define MAP_TEXTURE_PATH_MANAGER_BONUS_H

/**
 * @brief Check if the texture path is valid, by testing the path and counting
 * 			how many textures are approved.
 * @param  map struct with all map data
 * @return `bool` true if all textures are approved, false otherwise
 */
bool	texture_path_manager(t_map *map);

/**
 * @brief Test if the texture path is valid, by adding the current working
 * 			directory to the path and opening the file.
 * @param  path texture path
 * @param  cwd current working directory
 * @return `bool` true if the file exists, false otherwise
 */
bool	texture_path_tester(char *path, char *cwd);

#endif
