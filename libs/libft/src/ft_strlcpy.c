/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:35:59 by bira              #+#    #+#             */
/*   Updated: 2023/08/21 13:37:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	length;
	size_t	src_len;

	if (dest_size == 0)
		return (ft_strlen(src));
	length = 0;
	while ((length < dest_size - 1) && src[length] != '\0')
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}
