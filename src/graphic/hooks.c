/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/21 21:56:36 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void move_player(t_game *game, float move_x, float move_y)
{
	int new_x;
	int new_y;

	if (!game->map.gamemap)
	{
		printf("Erro: mapa não carregado\n");
		return;
	}

	new_x = (int)(game->player_x + move_x);
	new_y = (int)(game->player_y + move_y);

	if (new_y >= 0 && new_y < MAX_MAP_HEIGHT && new_x >= 0 && new_x < MAX_MAP_WIDTH)
	{
		if (game->map.gamemap[new_y][new_x] != '1')
		{
			game->player_x += move_x;
			game->player_y += move_y;
			printf("Jogador andou para X=%.2f, Y=%.2f\n", (float)game->player_x, (float)game->player_y);
		}
		else
			printf("Colidiu com parede!\n");
	}
	else
		printf("Tentou sair dos limites do mapa!\n");
}

void handle_movement(mlx_key_data_t keydata, t_game *game)
{
	float move_x;
	float move_y;
	float rotate_angle;

	move_x = 0;
	move_y = 0;
	rotate_angle = 0;

	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
		{
			move_x = game->dir_x * MOVE_SPEED;
			move_y = game->dir_y * MOVE_SPEED;
		}
		else if (keydata.key == MLX_KEY_S)
		{
			move_x = -game->dir_x * MOVE_SPEED;
			move_y = -game->dir_y * MOVE_SPEED;
		}
		else if (keydata.key == MLX_KEY_A)
		{
			move_x = game->dir_y * MOVE_SPEED;
			move_y = -game->dir_x * MOVE_SPEED;
		}
		else if (keydata.key == MLX_KEY_D)
		{
			move_x = -game->dir_y * MOVE_SPEED;
			move_y = game->dir_x * MOVE_SPEED;
		}
		else if (keydata.key == MLX_KEY_LEFT)
		{
			rotate_angle = -ROTATE_SPEED;
			rotate_player(game, rotate_angle);
		}
		else if (keydata.key == MLX_KEY_RIGHT)
		{
			rotate_angle = ROTATE_SPEED;
			rotate_player(game, rotate_angle);
		}

		if (move_x != 0 || move_y != 0)
			move_player(game, move_x, move_y);
	}
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	game = (t_game *)param;

    // DEBUG: Verificar se a função está capturando as teclas
    printf("Tecla pressionada: %d\n", keydata.key);

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_close_window(game->mlx);
        return ;
    }

    handle_movement(keydata, game);
}

void handle_close(void *param)
{
    t_game *game = (t_game *)param;
    cleanup(game);
    exit(0);
}
