/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:41:46 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/16 00:55:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

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
	printf("Saindo do jogo...\n");
	exit(EXIT_SUCCESS);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
