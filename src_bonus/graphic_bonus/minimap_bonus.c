/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:16:07 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:20:45 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/**
 * @brief Draws a line on the minimap at the specified coordinates,
 * that represents the player's direction, using Bresenham's line algorithm
 * @param game The game structure containing the minimap
 * @param px The x coordinate of the player
 * @param py The y coordinate of the player
 * @return `void`
 */
static void	player_line_direction_manager(t_game *game, int px, int py);

static void	player_line_direction_designer(t_game *game, int px, int py);

void	minimap_tile_render(t_game *game, int x, int y, uint32_t color)
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

void	minimap_player_render(t_game *game)
{
	int	px;
	int	py;
	int	dy;
	int	dx;

	px = MINIMAP_OFFSET_X + (int)(game->player_x * TILE_SIZE);
	py = MINIMAP_OFFSET_Y + (int)(game->player_y * TILE_SIZE);
	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			if ((px + dx) >= 0 && (py + dy) >= 0)
			{
				mlx_put_pixel(game->mlx_image,
					(px + dx), (py + dy), PLAYER_POS_COLOR);
			}
			dx++;
		}
		dy++;
	}
	player_line_direction_manager(game, px, py);
}

static void	player_line_direction_manager(t_game *game, int px, int py)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		px += cos(game->player_angle) * 5.0f;
		py += sin(game->player_angle) * 5.0f;
		player_line_direction_designer(game, px, py);
		idx++;
	}
}

// Draw a 2x2 yellow box at this position
static void	player_line_direction_designer(t_game *game, int px, int py)
{
	int	draw_x;
	int	draw_y;
	int	box_x;
	int	box_y;

	box_y = -1;
	while (box_y <= 0)
	{
		box_x = -1;
		while (box_x <= 0)
		{
			draw_x = px + box_x;
			draw_y = py + box_y;
			if (draw_x >= 0 && draw_y >= 0
				&& draw_x < MAX_MAP_WIDTH && draw_y < MAX_MAP_HEIGHT)
			{
				mlx_put_pixel(game->mlx_image, draw_x, draw_y,
					PLAYER_DIR_COLOR);
			}
			box_x++;
		}
		box_y++;
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
			minimap_tile_render(game, x, y, color);
			x++;
		}
		y++;
	}
	minimap_player_render(game);
}
