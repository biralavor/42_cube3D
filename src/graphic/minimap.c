/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:16:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/21 19:50:13 by umeneses         ###   ########.fr       */
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
				mlx_put_pixel(game->mlx_image, draw_x, draw_y, PLAYER_POSITION_COLOR);
			dx++;
		}
		dy++;
	}
	draw_player_direction_line(game, px, py);
}

static void	draw_player_direction_line(t_game *game, int px, int py)
{
	float	dx;
	float	dy;
	float	x;
	float	y;

	dx = cos(game->player_angle) * 5.0f; // Direction vector x
	dy = sin(game->player_angle) * 5.0f; // Direction vector y
	x = px;
	y = py;
	// Draw 4 small boxes in player's direction
	for (int i = 0; i < 4; i++)
	{
		// Move to next position
		x += dx;
		y += dy;
		// Draw a 2x2 yellow box at this position
		for (int box_y = -1; box_y <= 0; box_y++)
		{
			for (int box_x = -1; box_x <= 0; box_x++)
			{
				int draw_x = (int)x + box_x;
				int draw_y = (int)y + box_y;
				if (draw_x >= 0 && draw_y >= 0 && 
					draw_x < MAX_MAP_WIDTH && draw_y < MAX_MAP_HEIGHT)
				{
					mlx_put_pixel(game->mlx_image, draw_x, draw_y, PLAYER_DIRECTION_COLOR);
				}
			}
		}
	}
}

void	minimap_manager(t_game *game)
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
			color = BACKGROUND_COLOR;
			if (game->map->gamemap[y][x] == '1')
				color = WALLS_COLOR;
			else if (game->map->gamemap[y][x] == '0')
				color = EMPTY_SPACE_COLOR;
			draw_minimap_tile(game, x, y, color);
			x++;
		}
		y++;
	}
	draw_minimap_player(game);
}
