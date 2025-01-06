/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:37:39 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/16 13:49:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;
	int				index;

	if (!dest && !src)
		return (dest);
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	index = 0;
	while (n > 0)
	{
		newdest[index] = newsrc[index];
		index++;
		n--;
	}
	return (newdest);
}
