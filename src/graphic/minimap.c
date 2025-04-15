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

static void draw_player_direction_line(t_game *game, int px, int py);

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
	int px;
	int py;
	int dy;

	px = MINIMAP_OFFSET_X + (int)(game->player_x * TILE_SIZE);
	py = MINIMAP_OFFSET_Y + (int)(game->player_y * TILE_SIZE);
	dy = -2;
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
	draw_player_direction_line(game, px, py);
}

static void draw_player_direction_line(t_game *game, int px, int py)
{
	// Draw a line representing the player's direction
	float line_length = 20.0f; // Length of the direction line
	float line_x = px + cos(game->player_angle) * line_length;
	float line_y = py + sin(game->player_angle) * line_length;

	// Bresenham's line algorithm for drawing the direction line
	int x0 = px;
	int y0 = py;
	int x1 = (int)line_x;
	int y1 = (int)line_y;
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (x0 != x1 || y0 != y1)
	{
		if (x0 >= 0 && y0 >= 0)
			mlx_put_pixel(game->mlx_image, x0, y0, 0xFFFF00FF);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void draw_minimap(t_game *game)
{
	int y;
	uint32_t color;

	y = 0;
	while (game->map.gamemap[y])
	{
		int x = 0;
		while (game->map.gamemap[y][x])
		{
			color = 0x000000FF;
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
