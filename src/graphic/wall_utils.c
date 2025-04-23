/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:22:42 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 00:23:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_texture_t	*get_texture_for_ray(t_game *game, t_ray *ray)
{
	if (ray->hit_side == 0)
	{
		if (ray->step.x > 0)
			return (game->tex_west);
		else
			return (game->tex_east);
	}
	else
	{
		if (ray->step.y > 0)
			return (game->tex_north);
		else
			return (game->tex_south);
	}
}

int	get_tex_x(t_game *g, t_ray *r, mlx_texture_t *t)
{
	float	wall_x;
	float	raw;
	int		tex_x;

	if (r->hit_side == 0)
		raw = g->player_y + r->perp_dist * r->dir.y;
	else
		raw = g->player_x + r->perp_dist * r->dir.x;
	wall_x = raw - floorf(raw);
	tex_x = (int)(wall_x * (float)t->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= (int)t->width)
		tex_x = t->width - 1;
	if (r->hit_side == 0 && r->dir.x > 0)
		tex_x = t->width - tex_x - 1;
	if (r->hit_side == 1 && r->dir.y < 0)
		tex_x = t->width - tex_x - 1;
	return (tex_x);
}

void	draw_texture_line(t_game *g, mlx_texture_t *t,
    t_ray *r, int col, int tex_x)
{
int		h;
int		y;
float	corrected;
int		draw_end;

corrected = r->perp_dist * cos(r->angle - g->player_angle);
h = g->mlx_image->height / (corrected + 0.0001f);
y = -h / 2 + g->mlx_image->height / 2;
if (y < 0)
y = 0;
draw_end = h / 2 + g->mlx_image->height / 2;
if (draw_end > (int)g->mlx_image->height)
draw_end = g->mlx_image->height;
while (y < draw_end)
{
draw_texture_pixel(g, t, col, tex_x, y, h);
y++;
}
}