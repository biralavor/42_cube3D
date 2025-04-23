/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:06:11 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:21:13 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	**populate_texture_path(t_map *map);

void	load_textures(t_game *game)
{
	int		id;
	char	**textures;

	id = -1;
	textures = populate_texture_path(game->map);
	game->tex_north = mlx_load_png(textures[++id]);
	game->tex_south = mlx_load_png(textures[++id]);
	game->tex_east = mlx_load_png(textures[++id]);
	game->tex_west = mlx_load_png(textures[++id]);
	if (!game->tex_north || !game->tex_south
		|| !game->tex_east || !game->tex_west)
	{
		clear_all_exit_smoothly(game);
		ft_error_msg("Error loading textures.\n");
	}
	ft_free_array(textures);
}

static char	**populate_texture_path(t_map *map)
{
	int		idx;
	int		id;
	char	**textures;
	char	**temp;

	id = 0;
	idx = -1;
	textures = (char **)ft_calloc(ft_strlen(map->ggraph[0]), sizeof(char *));
	temp = NULL;
	while (++idx < MAX_INSIDE_ALLOC)
	{
		temp = ft_split(map->ggraph[idx], ' ');
		textures[id] = ft_strdup(temp[1]);
		ft_free_array(temp);
		temp = NULL;
		id++;
	}
	return (textures);
}

int	calculate_tex_y(t_game *g, int y, int h, int tex_height)
{
	int	d;
	int	tex_y;

	d = y * 256 - g->mlx_image->height * 128 + h * 128;
	tex_y = (d * tex_height / h) / 256;
	return (tex_y);
}

void	draw_texture_pixel(t_game *g, mlx_texture_t *t, t_drawinfo *info)
{
	int			tex_y;
	uint32_t	color;

	tex_y = calculate_tex_y(g, info->y, info->h, t->height);
	if (tex_y < 0 || tex_y >= (int)t->height)
		return ;
	color = ((uint32_t *)t->pixels)[tex_y * t->width + info->tex_x];
	mlx_put_pixel(g->mlx_image, info->col, info->y, color);
}

void	draw_textured_wall(t_game *g, t_ray *r, int col)
{
	mlx_texture_t	*t;
	t_drawinfo		info;

	t = get_texture_for_ray(g, r);
	if (!t)
		return ;
	info.tex_x = get_tex_x(g, r, t);
	info.col = col;
	draw_texture_line(g, t, r, &info);
}
