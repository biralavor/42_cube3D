/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:06:01 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/30 17:24:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;

	ptr = (char *)ft_calloc((ft_strlen(src) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, src, ft_strlen(src));
	ptr[ft_strlen(src)] = '\0';
	return (ptr);
}
