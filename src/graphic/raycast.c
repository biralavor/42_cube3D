/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:44:24 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/27 21:04:43 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	setup_step_and_delta(t_ray *r)
{
	if (r->dir.x < 0)
		r->step.x = -1;
	if (r->dir.x >= 0)
		r->step.x = 1;
	if (r->dir.y < 0)
		r->step.y = -1;
	if (r->dir.y >= 0)
		r->step.y = 1;

	if (r->dir.x == 0)
		r->delta.x = 1e30;
	if (r->dir.x != 0)
		r->delta.x = fabsf(1 / r->dir.x);
	if (r->dir.y == 0)
		r->delta.y = 1e30;
	if (r->dir.y != 0)
		r->delta.y = fabsf(1 / r->dir.y);
}

void	setup_ray(t_game *g, float angle, t_ray *r, t_vec *pos)
{
	pos->x = g->player_x;
	pos->y = g->player_y;
	r->dir.x = cos(angle);
	r->dir.y = sin(angle);
	r->map.x = (int)pos->x;
	r->map.y = (int)pos->y;
	setup_step_and_delta(r);
}

static void	calculate_initial_side(t_ray *r, t_vec pos)
{
	if (r->dir.x < 0)
		r->side.x = (pos.x - r->map.x) * r->delta.x;
	else
		r->side.x = (r->map.x + 1.0 - pos.x) * r->delta.x;

	if (r->dir.y < 0)
		r->side.y = (pos.y - r->map.y) * r->delta.y;
	else
		r->side.y = (r->map.y + 1.0 - pos.y) * r->delta.y;
}

void	perform_dda(t_game *g, t_ray *r, t_vec pos)
{
	calculate_initial_side(r, pos);
	while (1)
	{
		if (r->side.x < r->side.y)
		{
			r->side.x += r->delta.x;
			r->map.x += r->step.x;
			r->hit_side = 0;
		}
		else
		{
			r->side.y += r->delta.y;
			r->map.y += r->step.y;
			r->hit_side = 1;
		}
		if (g->map.gamemap[(int)r->map.y] &&
			g->map.gamemap[(int)r->map.y][(int)r->map.x] == '1')
			break ;
	}
}

void	cast_ray_dda(t_game *g, float angle, t_ray *r)
{
	t_vec	pos;

	r->angle = angle;
	setup_ray(g, angle, r, &pos);
	perform_dda(g, r, pos);
	if (r->hit_side == 0)
		r->perp_dist = r->side.x - r->delta.x;
	else
		r->perp_dist = r->side.y - r->delta.y;
}

void	cast_rays(t_game *game)
{
	t_render_info	r;
	t_ray			ray;
	float			fov;
	int				screen_width;

	screen_width = game->mlx_image->width;
	fov = M_PI / 3; // 60 graus, padrão de Wolfenstein

	r.num_rays = screen_width;
	r.angle_step = fov / r.num_rays;
	r.ray = 0;

	while (r.ray < r.num_rays)
	{
		r.ray_angle = game->player_angle - (fov / 2.0f)
			+ (r.ray * r.angle_step);
		cast_ray_dda(game, r.ray_angle, &ray);
		ray.angle = r.ray_angle; // para usar na correção do fish-eye
		draw_textured_wall(game, &ray, r.ray);
		r.ray++;
	}
}
