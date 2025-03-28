/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:06:11 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/27 21:25:19 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	**populate_texture_path(t_map *map);

void load_textures(t_game *game)
{
	int		id;
	char	**texture;

	id = 0;
	texture = populate_texture_path(&game->map);
	game->tex_north = mlx_load_png(texture[++id]);
	game->tex_south = mlx_load_png(texture[++id]);
	game->tex_east  = mlx_load_png(texture[++id]);
	game->tex_west  = mlx_load_png(texture[id]);
	ft_free_array(texture);
	if (!game->tex_north || !game->tex_south || !game->tex_east
			|| !game->tex_west)
	{
		printf("Erro ao carregar texturas.\n");
		free_textures(game);
		exit(EXIT_FAILURE);
	}
}

static char	**populate_texture_path(t_map *map)
{
	int		idx;
	int		id;
	char	**texture;
	char	**temp;

	id = -1;
	idx = -1;
	texture = ft_calloc(ft_strlen(map->ggraph[0]), sizeof(char*));
	temp = ft_calloc(ft_strlen(map->ggraph[0]), sizeof(char*));
	while (++idx <= 3)
	{
		temp = ft_split(map->ggraph[idx], ' ');
		texture[++id] = ft_strdup(temp[1]);
		ft_free_array(temp);
	}
	return (texture);
}

mlx_texture_t *get_texture_for_ray(t_game *game, t_ray *ray)
{
	if (ray->hit_side == 0)
	{
		if (ray->step.x > 0)
			return game->tex_west;
		else
			return game->tex_east;
	}
	else
	{
		if (ray->step.y > 0)
			return game->tex_north;
		else
			return game->tex_south;
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

	// 🔄 Corrigir inversão de textura
	if (r->hit_side == 0 && r->dir.x > 0)
		tex_x = t->width - tex_x - 1;
	if (r->hit_side == 1 && r->dir.y < 0)
		tex_x = t->width - tex_x - 1;

	return (tex_x);
}

void	draw_texture_line(t_game *g, mlx_texture_t *t, t_ray *r, int col, int tex_x)
{
	int			h;
	int			y;
	int			d;
	int			tex_y;
	float		corrected;

	corrected = r->perp_dist * cos(r->angle - g->player_angle); 
	h = g->mlx_image->height / (corrected + 0.0001f);

	y = -h / 2 + g->mlx_image->height / 2;
	if (y < 0)
		y = 0;

	while (y < (h / 2 + (int)g->mlx_image->height / 2) && y < (int)g->mlx_image->height)
	{
		d = y * 256 - g->mlx_image->height * 128 + h * 128;
		tex_y = (d * t->height / h) / 256;
		if (tex_y >= 0 && tex_y < (int)t->height)
			mlx_put_pixel(g->mlx_image, col, y,
				((uint32_t *)t->pixels)[tex_y * t->width + tex_x]);
		y++;
	}
}


void	draw_textured_wall(t_game *g, t_ray *r, int col)
{
	mlx_texture_t	*t;
	int				tex_x;

	t = NULL;
	if (r->hit_door)
		t = g->tex_door;
	else
		t = get_texture_for_ray(g, r);

	if (!t)
		return ;

	tex_x = get_tex_x(g, r, t);
	draw_texture_line(g, t, r, col, tex_x);
}
