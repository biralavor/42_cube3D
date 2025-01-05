/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:44:41 by bira              #+#    #+#             */
/*   Updated: 2023/08/31 10:09:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	s_len;
	unsigned int	iterate;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen((char *)s);
	ptr = (char *)ft_calloc((s_len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	iterate = -1;
	while (s[++iterate] != '\0')
		ptr[iterate] = (f)(iterate, s[iterate]);
	ptr[iterate] = '\0';
	return (ptr);
}
