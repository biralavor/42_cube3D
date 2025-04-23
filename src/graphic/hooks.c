/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 00:20:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_hooks(t_game *game)
{
	if (!game->mlx)
	{
		printf("Erro: MLX não inicializado corretamente!\n");
		return ;
	}
	printf("Registrando eventos de teclado...\n");
	mlx_key_hook(game->mlx, handle_keypress, game);
}

void move_player(t_game *game, float move_x, float move_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(game->player_x + move_x);
	new_y = (int)(game->player_y + move_y);
	if (new_y >= 0 && new_y < MAX_MAP_HEIGHT && new_x >= 0 && new_x < MAX_MAP_WIDTH)
	{
		if (game->map->gamemap[new_y][new_x] != '1')
		{
			game->player_x += move_x;
			game->player_y += move_y;
			printf("Player moved to X=%.2f, Y=%.2f\n", game->player_x, game->player_y);
		}
		else
			printf("Collision with wall at (%d, %d)!\n", new_x, new_y);
	}
	else
		printf("Tried to move out of map bounds!\n");
}

void	handle_movement(mlx_key_data_t keydata, t_game *game)
{
	float	move_x;
	float	move_y;
	float	rotate_angle;

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
			move_x = -game->plane_x * MOVE_SPEED;
			move_y = -game->plane_y * MOVE_SPEED;
		}
		else if (keydata.key == MLX_KEY_D)
		{
			move_x = game->plane_x * MOVE_SPEED;
			move_y = game->plane_y * MOVE_SPEED;
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
		move_player(game, move_x, move_y);
	}
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	printf("Tecla pressionada: %d\n", keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	// if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	// 	try_open_door(game);
	handle_movement(keydata, game);
	render(game);
}
