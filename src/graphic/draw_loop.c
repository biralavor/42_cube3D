/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:39:37 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/27 20:29:34 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_pixel(t_game *game, int x, int y, uint32_t color)
{
    if (x >= 0 && x < MAX_MAP_WIDTH && y >= 0 && y < MAX_MAP_HEIGHT)
        mlx_put_pixel(game->mlx_image, x, y, color);
}

void draw_background(t_game *game)
{
	uint32_t x;
	uint32_t y;
	uint32_t sky_color;
	uint32_t ground_color;

	if (!game->mlx_image)
		return;

	sky_color = game->ceiling_color;
	ground_color = game->floor_color;
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

// void    print_matrix(char **m)
// {
//     while (*m)
//     {
//         printf("%s\n", *m++);
//     }
// }

void draw_player(t_game *game)
{
    int size = 15; // Tamanho do jogador
    int px = game->player_x;
    int py = game->player_y;
    int x, y;

    // Verifica se a imagem foi criada corretamente antes de desenhar
    if (!game->mlx_image)
        return;
    // static bool maps;
    // if (!maps)
    //     print_matrix(game->map.gamemap), maps++;
    //printf("Desenhando jogador na posição X=%d, Y=%d\n", px, py);

    y = -size / 2;
    while (y < size / 2)
    {
        x = -size / 2;
        while (x < size / 2)
        {
            if (px + x >= 0 && px + x < (int)game->mlx_image->width &&
                py + y >= 0 && py + y < (int)game->mlx_image->height)
            {
                mlx_put_pixel(game->mlx_image, px + x, py + y, 0xFF0000FF); // Vermelho
            }
            x++;
        }
        y++;
    }
}


void render(t_game *game)
{

	if (!game->mlx_image)
		return;

	// Limpa tela
	memset(game->mlx_image->pixels, 0,
		game->mlx_image->width * game->mlx_image->height * sizeof(int));

	// Desenha fundo e jogador
	draw_background(game);
	draw_player(game);

	// NOVO: Raycasting render
	cast_rays(game);
	draw_minimap(game);
}
void render_init(t_game *game)
{

	if (!game->mlx_image)
		return;

	// Limpa tela
	memset(game->mlx_image->pixels, 0,
		game->mlx_image->width * game->mlx_image->height * sizeof(int));

	// Desenha fundo e jogador
	draw_background(game);
	load_textures(game);
	draw_player(game);

	// NOVO: Raycasting render
	cast_rays(game);
	draw_minimap(game);
}
