/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:39:37 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/24 20:52:14 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	draw_background(t_game *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	sky_color;
	uint32_t	ground_color;

	if (!game->mlx_image)
		return ;
	sky_color = game->map->ceiling_color;
	ground_color = game->map->floor_color;
	y = 0;
	while (y < game->mlx_image->height)
	{
		x = 0;
		while (x < game->mlx_image->width)
		{
			if (y < game->mlx_image->height / 2)
				mlx_put_pixel(game->mlx_image, x, y, sky_color);
			else
				mlx_put_pixel(game->mlx_image, x, y, ground_color);
			x++;
		}
		y++;
	}
}

void	render(t_game *game)
{
	if (!game->mlx_image)
		return ;
	memset(game->mlx_image->pixels, 0,
		game->mlx_image->width * game->mlx_image->height * sizeof(int));
	draw_background(game);
	cast_rays(game);
	minimap_manager(game);
}

void	render_init(t_game *game)
{
	if (!game->mlx_image)
		return ;
	memset(game->mlx_image->pixels, 0,
		game->mlx_image->width * game->mlx_image->height * sizeof(int));
	draw_background(game);
	load_textures(game);
	cast_rays(game);
	minimap_manager(game);
}
