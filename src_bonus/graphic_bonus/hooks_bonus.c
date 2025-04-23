/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 13:37:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_hooks(t_game *game)
{
	if (!game->mlx)
	{
		printf("Error: MLX not initialized properly!\n");
		return ;
	}
	printf("Registering keyboard events...\n");
	mlx_key_hook(game->mlx, handle_keypress, game);
}

void	move_player(t_game *game, float move_x, float move_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(game->player_x + move_x);
	new_y = (int)(game->player_y + move_y);
	if (new_y >= 0 && new_y < MAX_MAP_HEIGHT && new_x >= 0
		&& new_x < MAX_MAP_WIDTH)
	{
		if (game->map->gamemap[new_y][new_x] != '1')
		{
			game->player_x += move_x;
			game->player_y += move_y;
			printf("Player moved to X=%.2f, Y=%.2f\n", game->player_x,
				game->player_y);
		}
		else
			printf("Collision with wall at (%d, %d)!\n", new_x, new_y);
	}
	else
		printf("Tried to move out of map bounds!\n");
}

void	resolve_move_direction(int key, t_game *game, t_movement *m)
{
	if (key == MLX_KEY_W || key == MLX_KEY_UP)
	{
		m->move_x = game->dir_x * MOVE_SPEED;
		m->move_y = game->dir_y * MOVE_SPEED;
	}
	else if (key == MLX_KEY_S || key == MLX_KEY_DOWN)
	{
		m->move_x = -game->dir_x * MOVE_SPEED;
		m->move_y = -game->dir_y * MOVE_SPEED;
	}
	else if (key == MLX_KEY_A)
	{
		m->move_x = -game->plane_x * MOVE_SPEED;
		m->move_y = -game->plane_y * MOVE_SPEED;
	}
	else if (key == MLX_KEY_D)
	{
		m->move_x = game->plane_x * MOVE_SPEED;
		m->move_y = game->plane_y * MOVE_SPEED;
	}
	else if (key == MLX_KEY_LEFT)
		m->rotate_angle = -ROTATE_SPEED;
	else if (key == MLX_KEY_RIGHT)
		m->rotate_angle = ROTATE_SPEED;
}

void	handle_movement(mlx_key_data_t keydata, t_game *game)
{
	t_movement	m;

	m.move_x = 0;
	m.move_y = 0;
	m.rotate_angle = 0;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		resolve_move_direction(keydata.key, game, &m);
		if (m.rotate_angle != 0)
			rotate_player(game, m.rotate_angle);
		move_player(game, m.move_x, m.move_y);
	}
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	printf("Key pressed: %d\n", keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	handle_movement(keydata, game);
	render(game);
}
