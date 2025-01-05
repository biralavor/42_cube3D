/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_get_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:19 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 22:16:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_get_line(t_file_container *file)
{
	file->len = 0;
	while (file->read > 0)
	{
		ft_gnl_join_let(&file->str,
			ft_gnl_get_let(*(file->buffer + file->index)));
		if (*(file->buffer + file->index) == '\n'
			|| *(file->buffer + file->index) == '\0')
			break ;
		file->index++;
		file->len++;
		if (file->index >= file->read)
		{
			file->index = 0;
			file->read = read(file->fd, file->buffer, BUFFER_SIZE);
		}
	}
	if (file->read == -1)
		return (ft_gnl_clear_nodes(file->str));
	file->index++;
	file->len++;
	return (ft_gnl_join_line(file));
}
