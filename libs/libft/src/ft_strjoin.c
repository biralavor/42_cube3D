/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:11:43 by bira              #+#    #+#             */
/*   Updated: 2024/01/10 14:26:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (s1_len + 1));
	ft_strlcat(result, s2, (s1_len + s2_len + 1));
	result[s1_len + s2_len] = '\0';
	return (result);
}
