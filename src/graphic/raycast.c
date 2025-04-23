/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:44:24 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 09:44:29 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * @brief This function prepares the ste[ direction and delta distance values
 * for the ray.
 * @param r The ray struct
 * @return `void`
 * @note Lets go a little deeper:
 * If the ray direction is left (dir.x < 0), the step will be backwards
 * in the step.x (-1).
 * If the ray direction is right (dir.x > 0), the step will be forwards
 * in the step.x (1).
 * The delta distance is the distance between the player and the next grid line
 * in the direction of the ray. So:
 * If the ray direction is up (dir.y < 0), the delta will be the distance
 * between the player and the next horizontal grid line (delta.y), and the step
 * will be backwards (step.y = -1).
 * If the ray direction is down (dir.y > 0), the delta will be the distance
 * between the player and the next horizontal grid line (delta.y), and the step
 * will be forwards (step.y = 1).
 */
void	setup_step_and_delta(t_ray *r)
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
	while (g->map->gamemap[(int)r->map.y]
		&& g->map->gamemap[(int)r->map.y][(int)r->map.x] != '1')
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
	fov = M_PI / 3;
	r.num_rays = screen_width;
	r.angle_step = fov / r.num_rays;
	r.ray = 0;
	while (r.ray < r.num_rays)
	{
		r.ray_angle = game->player_angle - (fov / 2.0f)
			+ (r.ray * r.angle_step);
		cast_ray_dda(game, r.ray_angle, &ray);
		ray.angle = r.ray_angle;
		draw_textured_wall(game, &ray, r.ray);
		r.ray++;
	}
}
