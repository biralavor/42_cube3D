/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:00:57 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 19:37:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	clear_all_exit_smoothly(t_game *game)
{
	cleanup(game);
	ft_free_array(game->map->colors);
	ft_free_array(game->map->ggraph);
	ft_free_array(game->map->gamemap);
	free(game->map->buffer);
	free(game->map);
	free(game);
}

void	free_textures(t_game *g)
{
	if (g->tex_north)
		mlx_delete_texture(g->tex_north);
	if (g->tex_south)
		mlx_delete_texture(g->tex_south);
	if (g->tex_east)
		mlx_delete_texture(g->tex_east);
	if (g->tex_west)
		mlx_delete_texture(g->tex_west);
	g->tex_north = NULL;
	g->tex_south = NULL;
	g->tex_east = NULL;
	g->tex_west = NULL;
}

void	cleanup(t_game *game)
{
	free_textures(game);
	if (game->mlx_image)
		mlx_delete_image(game->mlx, game->mlx_image);
	if (game->mlx)
		mlx_terminate(game->mlx);
	printf("\nLeaving the game...\n");
}

void	alloc_error_msg(char **matrix, char *str)
{
	ft_free_array(matrix);
	matrix = NULL;
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("\n<< Error >> ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
}
