/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_join_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:12:57 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 11:21:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_join_line(t_file_container *file)
{
	t_char	*next;
	char	*line;
	int		index;

	line = (char *)ft_calloc((file->len + 1), sizeof(char));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	index = 0;
	next = NULL;
	while (file->str)
	{
		next = file->str->next;
		line[index] = file->str->c;
		free(file->str);
		file->str = next;
		index++;
	}
	line[index] = '\0';
	return (line);
}
