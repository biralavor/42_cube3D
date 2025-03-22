/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:44:24 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/22 18:52:50 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// Corrige o ângulo para sempre estar entre 0 e 2*PI
static float normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

float cast_single_ray(t_game *game, float ray_angle)
{
	t_ray_info	r;
	int			map_x;
	int			map_y;

	ray_angle = normalize_angle(ray_angle);

	r.x = game->player_x;
	r.y = game->player_y;
	r.step_size = 0.05f;
	r.steps = 1000;
	r.dx = cos(ray_angle) * r.step_size;
	r.dy = sin(ray_angle) * r.step_size;

	while (r.steps--)
	{
		r.x += r.dx;
		r.y += r.dy;

		map_x = (int)r.x;
		map_y = (int)r.y;

		if (map_x < 0 || map_x >= MAX_MAP_WIDTH || map_y < 0 || map_y >= MAX_MAP_HEIGHT)
			break;
		if (game->map.gamemap[map_y] && game->map.gamemap[map_y][map_x] == '1')
			break;
	}
	// distância Euclidiana do jogador até o ponto de impacto
	return sqrtf((r.x - game->player_x) * (r.x - game->player_x)
			   + (r.y - game->player_y) * (r.y - game->player_y));
}

void cast_rays(t_game *game)
{
	t_render_info r;
	int x;
	int y;

	r.num_rays = MAX_MAP_WIDTH;
	r.angle_step = (M_PI / 3) / r.num_rays;
	r.ray = 0;
	while (r.ray < r.num_rays)
	{
		r.ray_angle = game->player_angle - (M_PI / 6) + (r.ray * r.angle_step);
		r.distance = cast_single_ray(game, r.ray_angle);
		r.corrected_dist = r.distance * cos(r.ray_angle - game->player_angle);

		r.col_height = (int)(MAX_MAP_HEIGHT / (r.corrected_dist + 0.0001f));
		r.col_top = (MAX_MAP_HEIGHT / 2) - (r.col_height / 2);
		if (r.col_top < 0)
			r.col_top = 0;

		x = r.ray;
		y = 0;
		while (y < r.col_height)
		{
			r.screen_y = r.col_top + y;
			if (r.screen_y >= 0 && r.screen_y < MAX_MAP_HEIGHT)
				mlx_put_pixel(game->mlx_image, x, r.screen_y, 0xAAAAAAFF);
			y++;
		}
		r.ray++;
	}
}
