/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 15:06:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

void	toggle_wall_in_front(t_game *game)
{
	int	front_x;
	int	front_y;

	front_x = game->player_x + game->dir_x;
	front_y = game->player_y + game->dir_y;
	if (front_x <= 0 || front_y <= 0 || front_y >= MAX_MAP_HEIGHT - 1
		|| front_x == (int)ft_strlen(game->map->gamemap[0] - 1))
	{
		printf("Your are in front a wall. Return!\n");
		return ;
	}
	if (game->map->gamemap[front_y][front_x] == '0')
		game->map->gamemap[front_y][front_x] = '1';
	else if (game->map->gamemap[front_y][front_x] == '1')
		game->map->gamemap[front_y][front_x] = '0';
}
