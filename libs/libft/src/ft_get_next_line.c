/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:19:08 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 11:31:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	static t_file_container	file[MAX_FDS];

	if ((!fd || fd > MAX_FDS || fd < 0) && fd != 0)
		return (NULL);
	if (file[fd].index >= file[fd].read || file[fd].index == 0)
	{
		file[fd].index = 0;
		while (file[fd].index < BUFFER_SIZE)
			file[fd].buffer[file[fd].index++] = '\0';
		file[fd].index = 0;
		file[fd].str = NULL;
		file[fd].len = 0;
		file[fd].fd = fd;
		file[fd].read = read(fd, file[fd].buffer, BUFFER_SIZE);
	}
	if (file[fd].read <= 0 || file[fd].buffer[file[fd].index] == '\0')
		return (NULL);
	return (ft_gnl_get_line(&file[fd]));
}
