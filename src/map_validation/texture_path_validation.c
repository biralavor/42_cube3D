/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:42:13 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/10 16:23:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	texture_path_manager(t_map *map)
{
	char		*path;
	int			idx;
	static int	approved_texture[4];

	idx = -1;
	while (map->ggraph[++idx])
	{
		path = map->ggraph[idx];
		if (texture_path_tester(path))
		{
			approved_texture[idx]++;
			if (idx == 3
				&& approved_texture[0] == 1 && approved_texture[1] == 1
				&& approved_texture[2] == 1 && approved_texture[3] == 1)
			{
				printf(GREEN"\nTexture paths approved!\n");
				return (true);
			}
		}
	}
	ft_putstr_fd(RED"Texture path not valid", STDERR_FILENO);
	return (false);
}

bool	texture_path_tester(char *path)
{
	int		path_fd;
	char	*cwd;
	char	*redux_path;

	path += 3;
	redux_path = ft_strdup(path);
	path -= 3;
	cwd = getcwd(NULL, 0);
	cwd = ft_strjoin(cwd, "/");
	redux_path = ft_strjoin(cwd, redux_path);
	free(cwd);
	path_fd = open(redux_path, O_RDONLY);
	if (path_fd != -1)
	{
		close(path_fd);
		return (true);
	}
	close(path_fd);
	return (false);
}
