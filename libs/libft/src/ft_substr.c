/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:55:19 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/31 09:30:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	if (start >= s_len || s[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
	{
		len = s_len - start + 1;
		ptr = ft_calloc(len, sizeof(char));
	}
	if (s_len - start >= len)
		ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (s + start), (len + 1));
	return (ptr);
}
