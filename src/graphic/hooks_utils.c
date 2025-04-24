/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/24 20:09:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int safe_get_line_height(t_game *game);
static int safe_get_line_width(t_game *game, int row);

void	handle_mouse_direction(double m_xpos, double m_ypos, void *param)
{
	t_game			*game;
	static double	last_mouse_xpos = -1;
	double			sensitivity;
	double			rotation;

	game = (t_game *)param;
	sensitivity = 0.015;
	(void)m_ypos;
	if (last_mouse_xpos < 0)
		last_mouse_xpos = m_xpos;
	rotation = (m_xpos - last_mouse_xpos) * sensitivity;
	if (fabs(rotation) > 0.0001)
	{
		rotate_player(game, rotation);
	}
	last_mouse_xpos = m_xpos;
	render(game);
}

void	minicraft_effect_runner(t_game *game)
{
	int	front_x;
	int	front_y;

	front_x = (int)(game->player_x + game->dir_x);
	front_y = (int)(game->player_y + game->dir_y);
	if (front_y <= 0 || front_y >= safe_get_line_height(game) - 1
		|| front_y >= safe_get_line_height(game)
		|| front_x <= 0 || front_x >= safe_get_line_width(game, front_y)
		|| front_x >= safe_get_line_width(game, front_y) - 1
		|| safe_get_line_width(game, front_y - 1) <= front_x
		|| safe_get_line_width(game, front_y + 1) <= front_x)
	{
		printf("You can NOT modify the Boundary. Try other location!\n");
		return ;
	}
	if (game->map->gamemap[front_y][front_x] == '0')
		game->map->gamemap[front_y][front_x] = '1';
	else if (game->map->gamemap[front_y][front_x] == '1')
		game->map->gamemap[front_y][front_x] = '0';
}

static int safe_get_line_width(t_game *game, int row)
{
	if (row < 0 || row >= game->map->max_height || !game->map->gamemap[row])
		return 0;
	return ft_strlen(game->map->gamemap[row]);
}

static int safe_get_line_height(t_game *game)
{
	int height;

	height = 0;
	while (game->map->gamemap[height] != NULL)
		height++;
	return height;
}
