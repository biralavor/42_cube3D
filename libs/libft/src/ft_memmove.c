/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:40 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/31 15:59:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*newdest;
	char	*newsrc;
	size_t	index;

	newdest = (char *)str1;
	newsrc = (char *)str2;
	if (newdest < newsrc)
		ft_memcpy(newdest, newsrc, n);
	else if (newdest > newsrc)
	{
		index = n;
		while (index > 0)
		{
			newdest[index - 1] = newsrc[index - 1];
			index--;
		}
	}
	return (newdest);
}
