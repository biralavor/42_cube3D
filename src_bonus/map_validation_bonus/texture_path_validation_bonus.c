/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_path_validation_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:42:13 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 20:55:13 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

bool	texture_path_manager(t_map *map)
{
	char		*path;
	int			idx;
	static int	approved_texture[MAX_TEXTURE_FILES];
	static char	cwd[MAX_TEXTURE_PATH];

	idx = -1;
	getcwd(cwd, MAX_TEXTURE_PATH);
	while (map->ggraph[++idx])
	{
		path = map->ggraph[idx];
		if (texture_path_tester(path, cwd))
		{
			approved_texture[idx]++;
			if (idx == 3
				&& approved_texture[0] == 1 && approved_texture[1] == 1
				&& approved_texture[2] == 1 && approved_texture[3] == 1)
			{
				printf(GRE"\n✅ Texture Paths Map \tapproved!\n");
				return (true);
			}
		}
	}
	ft_putstr_fd(YEL"Texture path not valid", STDERR_FILENO);
	return (false);
}

bool	texture_path_tester(char *path, char *cwd)
{
	int		path_fd;
	char	*updated_cwd;
	char	*redux_path;
	char	*new_path;

	redux_path = (char *)ft_calloc(ft_strlen(path), sizeof(char *));
	ft_memmove(redux_path, path + 3, ft_strlen(path));
	updated_cwd = ft_strjoin(cwd, "/");
	new_path = ft_strjoin(updated_cwd, redux_path);
	free(updated_cwd);
	path_fd = open(new_path, O_RDONLY);
	free(redux_path);
	free(new_path);
	if (path_fd != -1)
	{
		close(path_fd);
		return (true);
	}
	close(path_fd);
	return (false);
}
