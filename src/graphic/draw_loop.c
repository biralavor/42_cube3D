/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:39:37 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/22 18:56:04 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_pixel(t_game *game, int x, int y, uint32_t color)
{
    if (x >= 0 && x < MAX_MAP_WIDTH && y >= 0 && y < MAX_MAP_HEIGHT)
        mlx_put_pixel(game->mlx_image, x, y, color);
}

void draw_background(mlx_image_t *image)
{
	uint32_t x;
	uint32_t y;
	uint32_t sky_color;
	uint32_t ground_color;

	if (!image)
		return;

	sky_color = 0x87CEEBFF;    // Azul claro (céu)
	ground_color = 0x228B22FF; // Verde (chão)
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			if (y < image->height / 2)
				mlx_put_pixel(image, x, y, sky_color);
			else
				mlx_put_pixel(image, x, y, ground_color);
			x++;
		}
		y++;
	}
}

void draw_player(t_game *game)
{
    int size = 15; // Tamanho do jogador
    int px = game->player_x;
    int py = game->player_y;
    int x, y;

    // Verifica se a imagem foi criada corretamente antes de desenhar
    if (!game->mlx_image)
        return;

    printf("Desenhando jogador na posição X=%d, Y=%d\n", px, py);

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


void game_loop(t_game *game)
{
    mlx_key_hook(game->mlx, handle_keypress, game);
    mlx_close_hook(game->mlx, handle_close, game);
    
    while (1)
    {
        // Aqui você pode adicionar sua lógica de atualização do jogo
        draw_background(game->mlx_image);
        mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
        
        printf("Entrando no loop da MLX...\n");
        mlx_loop(game->mlx);
        printf("Saindo do loop da MLX...\n"); // Se este print nunca aparecer, significa que o jogo foi encerrado abruptamente.
    }
}
void render(void *param)
{
	t_game *game;

	game = (t_game *)param;

	if (!game->mlx_image)
		return;

	// Limpa tela
	memset(game->mlx_image->pixels, 0,
		game->mlx_image->width * game->mlx_image->height * sizeof(int));

	// Desenha fundo e jogador
	draw_background(game->mlx_image);
	draw_player(game);

	// NOVO: Raycasting render
	cast_rays(game);
}
