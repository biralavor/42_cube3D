/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:44:24 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/25 19:49:09 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// Corrige o ângulo para sempre estar entre 0 e 2*PI
// static float normalize_angle(float angle)
// {
// 	while (angle < 0)
// 		angle += 2 * M_PI;
// 	while (angle >= 2 * M_PI)
// 		angle -= 2 * M_PI;
// 	return (angle);
// }

// float cast_single_ray(t_game *game, float ray_angle)
// {
// 	t_ray_info	r;
// 	int			map_x;
// 	int			map_y;

// 	ray_angle = normalize_angle(ray_angle);

// 	r.x = game->player_x;
// 	r.y = game->player_y;
// 	r.step_size = 0.05f;
// 	r.steps = 1000;
// 	r.dx = cos(ray_angle) * r.step_size;
// 	r.dy = sin(ray_angle) * r.step_size;

// 	while (r.steps--)
// 	{
// 		r.x += r.dx;
// 		r.y += r.dy;

// 		map_x = (int)r.x;
// 		map_y = (int)r.y;

// 		if (map_x < 0 || map_x >= MAX_MAP_WIDTH || map_y < 0 || map_y >= MAX_MAP_HEIGHT)
// 			break;
// 		if (game->map.gamemap[map_y] && game->map.gamemap[map_y][map_x] == '1')
// 			break;
// 	}
// 	// distância Euclidiana do jogador até o ponto de impacto
// 	return sqrtf((r.x - game->player_x) * (r.x - game->player_x)
// 			   + (r.y - game->player_y) * (r.y - game->player_y));
// }


//-----------------------------------------

static int	set_direction(float dir)
{
	return (dir < 0 ? -1 : 1);
}

static void	calculate_delta_dist(t_ray *ray)
{
	ray->delta_dist.x = ray->dir.x == 0 ? INFINITY : fabsf(1.0f / ray->dir.x);
	ray->delta_dist.y = ray->dir.y == 0 ? INFINITY : fabsf(1.0f / ray->dir.y);
}

static void	calculate_dist_side(t_ray *ray, t_game *g)
{
	ray->map.x = (int)g->player_x;
	ray->map.y = (int)g->player_y;

	if (ray->dir.x < 0)
		ray->dist_side.x = (g->player_x - ray->map.x) * ray->delta_dist.x;
	else
		ray->dist_side.x = (ray->map.x + 1.0 - g->player_x) * ray->delta_dist.x;
	if (ray->dir.y < 0)
		ray->dist_side.y = (g->player_y - ray->map.y) * ray->delta_dist.y;
	else
		ray->dist_side.y = (ray->map.y + 1.0 - g->player_y) * ray->delta_dist.y;
}

float	cast_single_ray_dda(t_game *g, float ray_angle)
{
	t_ray	r;

	r.dir.x = cos(ray_angle);
	r.dir.y = sin(ray_angle);

	r.step.x = set_direction(r.dir.x);
	r.step.y = set_direction(r.dir.y);

	calculate_delta_dist(&r);
	calculate_dist_side(&r, g);

	while (1)
	{
		if (r.dist_side.x < r.dist_side.y)
		{
			r.dist_side.x += r.delta_dist.x;
			r.map.x += r.step.x;
			r.hit_side = 0;
		}
		else
		{
			r.dist_side.y += r.delta_dist.y;
			r.map.y += r.step.y;
			r.hit_side = 1;
		}
		if (g->map.gamemap[(int)r.map.y][(int)r.map.x] == '1')
			break;
	}

	if (r.hit_side == 0)
		r.perp_dist = r.dist_side.x - r.delta_dist.x;
	else
		r.perp_dist = r.dist_side.y - r.delta_dist.y;

	return (r.perp_dist);
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
		r.distance = cast_single_ray_dda(game, r.ray_angle);
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
