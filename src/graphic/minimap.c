/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:16:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/21 14:28:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

/**
 * @brief Draws a line on the minimap at the specified coordinates,
 * that represents the player's direction, using Bresenham's line algorithm
 * @param game The game structure containing the minimap
 * @param px The x coordinate of the player
 * @param py The y coordinate of the player
 * @return `void`
 */
static void	draw_player_direction_line(t_game *game, int px, int py);

void	draw_minimap_tile(t_game *game, int x, int y, uint32_t color)
{
	int	dy;
	int	dx;
	int	draw_x;
	int	draw_y;

	dy = 0;
	while (dy < TILE_SIZE)
	{
		dx = 0;
		while (dx < TILE_SIZE)
		{
			draw_x = MINIMAP_OFFSET_X + x * TILE_SIZE + dx;
			draw_y = MINIMAP_OFFSET_Y + y * TILE_SIZE + dy;
			mlx_put_pixel(game->mlx_image, draw_x, draw_y, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap_player(t_game *game)
{
	int	px;
	int	py;
	int	dy;
	int	dx;
	int	draw_x;
	int	draw_y;

	px = MINIMAP_OFFSET_X + (int)(game->player_x * TILE_SIZE);
	py = MINIMAP_OFFSET_Y + (int)(game->player_y * TILE_SIZE);
	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			draw_x = px + dx;
			draw_y = py + dy;
			if (draw_x >= 0 && draw_y >= 0)
				mlx_put_pixel(game->mlx_image, draw_x, draw_y, 0xFF0000FF);
			dx++;
		}
		dy++;
	}
	draw_player_direction_line(game, px, py);
}

static void	draw_player_direction_line(t_game *game, int px, int py)
{
	float	line_length;
	float	line_x;
	float	line_y;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

	line_length = 20.0f;
	line_x = px + cos(game->player_angle) * line_length;
	line_y = py + sin(game->player_angle) * line_length;
	x1 = (int)line_x;
	y1 = (int)line_y;
	dx = abs(x1 - px);
	dy = abs(y1 - py);
	sx = (px < x1) ? 1 : -1;
	sy = (py < y1) ? 1 : -1;
	err = dx - dy;
	while (px != x1 || py != y1)
	{
		if (px >= 0 && py >= 0)
			mlx_put_pixel(game->mlx_image, px, py, 0xFFFF00FF);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			px += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			py += sy;
		}
	}
}

void	draw_minimap(t_game *game)
{
	int			y;
	int			x;
	uint32_t	color;

	y = 0;
	while (game->map->gamemap[y])
	{
		x = 0;
		while (game->map->gamemap[y][x])
		{
			color = 0x000000FF;
			if (game->map->gamemap[y][x] == '1')
				color = 0xFFFFFFFF;
			else if (game->map->gamemap[y][x] == '0')
				color = 0x555555FF;
			draw_minimap_tile(game, x, y, color);
			x++;
		}
		y++;
	}
	draw_minimap_player(game);
}
