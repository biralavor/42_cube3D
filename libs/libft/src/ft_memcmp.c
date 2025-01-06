/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:06:10 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/31 15:58:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*newstr1;
	unsigned char	*newstr2;

	if (n == 0)
		return (0);
	newstr1 = (unsigned char *)str1;
	newstr2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*newstr1 != *newstr2)
			return (*newstr1 - *newstr2);
		newstr1++;
		newstr2++;
		n--;
	}
	return (0);
}
