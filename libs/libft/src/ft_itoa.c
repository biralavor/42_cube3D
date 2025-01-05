/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:40:18 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/30 17:22:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (length = 1);
	if (nbr < 0)
	{
		length++;
		nbr = nbr * -1;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t			intlen;
	size_t			index;
	char			*result;
	long long int	nbr;

	intlen = ft_intlen(n);
	nbr = n;
	result = (char *)ft_calloc((intlen + 1), sizeof(char));
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		result[0] = '0';
	index = intlen - 1;
	while (nbr > 0)
	{
		result[index--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	result[intlen] = '\0';
	return (result);
}
