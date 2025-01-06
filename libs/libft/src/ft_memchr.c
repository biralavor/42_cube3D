/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:04:20 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/31 15:57:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			index;
	unsigned char	*newstr;

	index = 0;
	newstr = (unsigned char *)str;
	while (index < n)
	{
		if (newstr[index] == (unsigned char)c)
			return ((void *)newstr + index);
		index++;
	}
	return (NULL);
}
