/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:00:32 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/24 20:52:51 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	rotate_player(t_game *game, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
	game->player_angle += angle;
	if (game->player_angle < 0)
		game->player_angle += 2 * M_PI;
	else if (game->player_angle >= 2 * M_PI)
		game->player_angle -= 2 * M_PI;
}
