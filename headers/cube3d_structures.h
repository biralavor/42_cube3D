/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_structures.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:53:55 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/17 22:06:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_STRUCTURES_H
# define CUBE3D_STRUCTURES_H

/**
 * @brief Structure for map file data
 * @param gamemap 2D array with the map
 * @param ggraph 2D array with the map and the player
 * @param colors 2D array with the colors
 * @param buffer pointer to a buffer with the map file
 * @param bytes_read bytes read from the map file, used by `buffer`
 * @param fd file descriptor
 * @param player_pos_y player position y
 * @param player_pos_x player position x
 */
typedef struct s_map
{
	char	**gamemap;
	char	**ggraph;
	char	**colors;
	char	*buffer;
	int32_t	bytes_read;
	int32_t	fd;
	int		player_pos_y;
	int		player_pos_x;
}			t_map;

/**
 * @brief Structure for mlx data
 * @param mlx pointer to the mlx struct
 * @param map pointer to the map struct
 */
typedef struct s_data
{
	mlx_t	*mlx;
	t_map	*map;
}			t_data;

#endif