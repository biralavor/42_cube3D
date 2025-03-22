/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_structures.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:53:55 by umeneses          #+#    #+#             */
/*   Updated: 2025/03/22 18:51:41 by gigardin         ###   ########.fr       */
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


typedef struct s_render_info
{
	int		ray;
	int		num_rays;
	float	ray_angle;
	float	angle_step;
	float	distance;
	float	corrected_dist;
	int		col_height;
	int		col_top;
	int		screen_y;
}	t_render_info;

typedef struct s_ray_info
{
	float x;
	float y;
	float dx;
	float dy;
	float step_size;
	int   steps;
}	t_ray_info;

typedef struct s_game
{
    mlx_t       *mlx;          // Ponteiro para a MLX42
    mlx_image_t *mlx_image;    // Imagem onde desenhamos o jogo
    t_map       map;           // Estrutura que armazena o mapa

    int         player_x;      // Posição X do jogador no mapa
    int         player_y;      // Posição Y do jogador no mapa
    float       player_angle;  // Ângulo de visão do jogador
    float       dir_x;         // Direção X do jogador
    float       dir_y;         // Direção Y do jogador
}   t_game;
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
