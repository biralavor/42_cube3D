/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:22:42 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 13:45:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	game_directions_init(t_game *game);
static void	map_direction_getter(t_game *game);

static void	map_direction_getter(t_game *game)
{
	int	y;
	int	x;

	y = game->map->player_pos_y;
	x = game->map->player_pos_x;
	game->map->map_direction = game->map->gamemap[y][x];
}

static void	game_directions_init(t_game *game)
{
	game->player_x = game->map->player_pos_x;
	game->player_y = game->map->player_pos_y;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_y = 0;
	game->plane_x = 0;
}

void	game_directions_setter(t_game *game)
{
	if (game->map->map_direction == 'N')
	{
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->player_angle = 3 * M_PI / 2;
	}
	else if (game->map->map_direction == 'S')
	{
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->player_angle = M_PI / 2;
	}
	else if (game->map->map_direction == 'E')
	{
		game->dir_x = 1;
		game->plane_y = 0.66;
		game->player_angle = 0;
	}
	else if (game->map->map_direction == 'W')
	{
		game->dir_x = -1;
		game->plane_y = -0.66;
		game->player_angle = M_PI;
	}
}

void	setup_init_validation(t_game *game)
{
	game->mlx = mlx_init(MAX_MAP_WIDTH, MAX_MAP_HEIGHT, "Cub3D", false);
	if (!game->mlx)
	{
		clear_all_exit_smoothly(game);
		ft_error_msg("MLX initialization error\n");
	}
	game->mlx_image = mlx_new_image(game->mlx, MAX_MAP_WIDTH, MAX_MAP_HEIGHT);
	if (!game->mlx_image)
	{
		clear_all_exit_smoothly(game);
		ft_error_msg("MLX Image initialization error\n");
	}
	printf("Imagem MLX criada com sucesso!\n");
}

void	setup_init(t_game *game)
{
	setup_init_validation(game);
	printf(GRE"\n\n>>>>>> Starting Cube3D now!\n"RESET);
	map_direction_getter(game);
	game_directions_init(game);
	game_directions_setter(game);
	mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	render_init(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
}
