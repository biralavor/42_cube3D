/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:20:07 by bira              #+#    #+#             */
/*   Updated: 2023/08/31 16:02:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == (unsigned char)c)
			return ((char *)string + index);
		index++;
	}
	if (string[index] == (unsigned char)c)
		return ((char *)string + index);
	return (NULL);
}
