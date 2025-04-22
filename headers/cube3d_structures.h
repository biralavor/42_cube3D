/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_structures.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:11 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/22 19:21:12 by umeneses         ###   ########.fr       */
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
	int		floor_color;
	int		ceiling_color;
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

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	map;
	t_vec	delta;
	t_vec	side;
	t_vec	step;
	float	perp_dist;
	int		hit_side;
	float	angle;
	bool	hit_door;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_image;
	t_map			*map;
	float			player_x;
	float			player_y;
	float			player_angle;
	float			plane_x;
	float			plane_y;
	float			dir_x;
	float			dir_y;
	mlx_texture_t	*tex_north;
	mlx_texture_t	*tex_south;
	mlx_texture_t	*tex_east;
	mlx_texture_t	*tex_west;
	mlx_texture_t	*tex_door;
}	t_game;

#endif
