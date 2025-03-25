/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:16:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/25 20:20:47 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_minimap_tile(t_game *game, int x, int y, uint32_t color)
{
	int dy = 0;
	while (dy < TILE_SIZE)
	{
		int dx = 0;
		while (dx < TILE_SIZE)
		{
			int draw_x = MINIMAP_OFFSET_X + x * TILE_SIZE + dx;
			int draw_y = MINIMAP_OFFSET_Y + y * TILE_SIZE + dy;
			mlx_put_pixel(game->mlx_image, draw_x, draw_y, color);
			dx++;
		}
		dy++;
	}
}

void draw_minimap_player(t_game *game)
{
	int px = MINIMAP_OFFSET_X + (int)(game->player_x * TILE_SIZE);
	int py = MINIMAP_OFFSET_Y + (int)(game->player_y * TILE_SIZE);

	int dy = -2;
	while (dy <= 2)
	{
		int dx = -2;
		while (dx <= 2)
		{
			int draw_x = px + dx;
			int draw_y = py + dy;
			if (draw_x >= 0 && draw_y >= 0)
				mlx_put_pixel(game->mlx_image, draw_x, draw_y, 0xFF0000FF);
			dx++;
		}
		dy++;
	}
}

void draw_minimap(t_game *game)
{
	int y = 0;
	while (game->map.gamemap[y])
	{
		int x = 0;
		while (game->map.gamemap[y][x])
		{
			uint32_t color = 0x000000FF;
			if (game->map.gamemap[y][x] == '1')
				color = 0xFFFFFFFF;
			else if (game->map.gamemap[y][x] == '0')
				color = 0x555555FF;

			draw_minimap_tile(game, x, y, color);
			x++;
		}
		y++;
	}
	draw_minimap_player(game);
}
