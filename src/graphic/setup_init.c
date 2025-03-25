/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:22:42 by gigardin          #+#    #+#             */
/*   Updated: 2025/03/25 19:07:59 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// int	close_window(t_game *game)
// {
// 	mlx_terminate(game->mlx);
// 	exit(0);
// }

void cleanup(t_game *game)
{
    if (game->mlx_image)
        mlx_delete_image(game->mlx, game->mlx_image);
    
    if (game->mlx)
        mlx_terminate(game->mlx);
}
void setup_hooks(t_game *game)
{
    if (!game->mlx)
    {
        printf("Erro: MLX não inicializado corretamente!\n");
        return;
    }

    // DEBUG: Verificar se a função está sendo chamada
    printf("Registrando eventos de teclado...\n");

    // Registra a função de teclado
    mlx_key_hook(game->mlx, handle_keypress, game);
}

void set_player_position(t_game *game)
{
	int x;
	int y;
	char dir;

	x = game->map.player_pos_x;
	y = game->map.player_pos_y;

	// Pegamos a direção do mapa (N, S, E, W)
	dir = game->map.gamemap[y][x];

	game->player_x = (float)x;
	game->player_y = (float)y;

	// Define o ângulo inicial com base na direção
	if (dir == 'N')
		game->player_angle = 3 * M_PI / 2; // olhando para cima
	else if (dir == 'S')
		game->player_angle = M_PI / 2;     // olhando para baixo
	else if (dir == 'E')
		game->player_angle = 0;            // olhando para a direita
	else if (dir == 'W')
		game->player_angle = M_PI;         // olhando para a esquerda
	else
	{
		printf("Direção inválida no mapa! Usando E por padrão.\n");
		game->player_angle = 0;
	}

	// Calcula os vetores de direção
	game->dir_x = cos(game->player_angle);
	game->dir_y = sin(game->player_angle);

	printf("Jogador inicializado em: X=%.2f, Y=%.2f, Ângulo=%.2f (direção: %c)\n",
		(float)game->player_x, (float)game->player_y, game->player_angle, dir);
}

int setup_init(t_game *game)
{
    game->mlx = mlx_init(MAX_MAP_WIDTH, MAX_MAP_HEIGHT, "Cub3D", false);
    if (!game->mlx)
        return (-1);
    
    game->mlx_image = mlx_new_image(game->mlx, MAX_MAP_WIDTH, MAX_MAP_HEIGHT);
    if (!game->mlx_image)
	{
		printf("Erro ao criar a imagem MLX!\n");
		exit(EXIT_FAILURE);
	}
	printf("Imagem MLX criada com sucesso!\n");
    // 📌 Define a posição inicial do jogador
    set_player_position(game);

    // Adiciona a imagem à janela
    mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	render_init(game);
    // Registra a função de renderização contínua
    //mlx_loop_hook(game->mlx, render, game);

    // Registra os hooks de teclado
    setup_hooks(game);

    // 📌 Aqui é onde a janela permanece aberta
    mlx_loop(game->mlx);
    return (EXIT_SUCCESS);
}
