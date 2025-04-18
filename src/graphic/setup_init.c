/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:22:42 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/06 16:08:10 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void setup_hooks(t_game *game)
{
	if (!game->mlx)
	{
		printf("Erro: MLX não inicializado corretamente!\n");
		return;
	}
	printf("Registrando eventos de teclado...\n");
	mlx_key_hook(game->mlx, handle_keypress, game);
}

void set_player_position(t_game *game)
{
	char	mapdir;

	mapdir = game->map.gamemap[game->map.player_pos_y][game->map.player_pos_x];
	game->player_x = game->map.player_pos_x;
	game->player_y = game->map.player_pos_y;
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

int setup_init(t_game *game)
{
	game->mlx = mlx_init(MAX_MAP_WIDTH, MAX_MAP_HEIGHT, "Cub3D", false);
	if (!game->mlx)
		return (-1);
	game->mlx_image = mlx_new_image(game->mlx, MAX_MAP_WIDTH, MAX_MAP_HEIGHT);
	if (!game->mlx_image)
	{
		printf("Erro ao criar a imagem MLX!\n");
		exit(EXIT_FAILURE);
	}
	printf("Imagem MLX criada com sucesso!\n");
	set_player_position(game);
	mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	render_init(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (EXIT_SUCCESS);
}
