/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:22:42 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/22 23:15:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_hooks(t_game *game)
{
	if (!game->mlx)
	{
		printf("Erro: MLX não inicializado corretamente!\n");
		return;
	}
	printf("Registrando eventos de teclado...\n");
	mlx_key_hook(game->mlx, handle_keypress, game);
}

void	set_player_position(t_game *game)
{
	char	mapdir;

	mapdir = game->map->gamemap[game->map->player_pos_y][game->map->player_pos_x];
	game->player_x = game->map->player_pos_x;
	game->player_y = game->map->player_pos_y;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_y = 0;
	game->plane_x = 0;
	if (mapdir == 'N')
	{
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->player_angle = 3 * M_PI / 2;
	}
	else if (mapdir == 'S')
	{
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->player_angle = M_PI / 2;
	}
	else if (mapdir == 'E')
	{
		game->dir_x = 1;
		game->plane_y = 0.66;
		game->player_angle = 0;
	}
	else if (mapdir == 'W')
	{
		game->dir_x = -1;
		game->plane_y = -0.66;
		game->player_angle = M_PI;
	}
}

void	setup_init(t_game *game)
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
	printf(GRE"\n\n>>>>>> Starting Cube3D now!\n"RESET);
	set_player_position(game);
	mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	render_init(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
}
