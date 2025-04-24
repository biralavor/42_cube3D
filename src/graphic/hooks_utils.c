/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/24 17:58:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	actual_max_line_width_getter(t_game *game);
static int	actual_max_line_height_getter(t_game *game);

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
	int	actual_max_line_height;
	int	actual_max_line_width;

	front_x = game->player_x + game->dir_x;
	front_y = game->player_y + game->dir_y;
	actual_max_line_height = actual_max_line_height_getter(game);
	actual_max_line_width = actual_max_line_width_getter(game);
	map_array_printer(game->map->gamemap, ">>>> gamemap at minicraft_effect_runner");
	while (game->map->gamemap[actual_max_line_height][0])
		actual_max_line_height++;
	while (game->map->gamemap[0][actual_max_line_width])
		actual_max_line_width++;
	if (front_x <= 0 || front_y <= 0 || front_x >= actual_max_line_width - 1
		|| front_y >= actual_max_line_height - 1)
	{
		printf("You can NOT modify the Boundary. Try other location!\n");
		return ;
	}
	if (game->map->gamemap[front_y][front_x] == '0')
		game->map->gamemap[front_y][front_x] = '1';
	else if (game->map->gamemap[front_y][front_x] == '1')
		game->map->gamemap[front_y][front_x] = '0';
}

static int	actual_max_line_width_getter(t_game *game)
{
	int	actual_width;

	actual_width = 0;
	while (game->map->gamemap[(int)game->player_x][actual_width] != 'S')
		actual_width++;
	return (actual_width);
}

static int	actual_max_line_height_getter(t_game *game)
{
	int	actual_height;

	actual_height = 0;
	while (game->map->gamemap[actual_height][(int)game->player_y] != 'S')
		actual_height++;
	return (actual_height);
}
