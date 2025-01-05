/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:01:58 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/30 17:29:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	if (num == 0)
		return (0);
	while (num > 0)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
		num--;
		if ((*str1 || *str2) == '\0')
			break ;
	}
	return (0);
}
