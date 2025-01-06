/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:05:46 by umeneses          #+#    #+#             */
/*   Updated: 2023/08/31 15:46:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	begin_index;
	size_t	end_index;

	if (!s1 || !set)
		return (0);
	if (*s1 == '\0' && *set == '\0')
		return (ft_strdup(""));
	begin_index = 0;
	while (ft_strchr(set, s1[begin_index]) && s1[begin_index])
		begin_index++;
	end_index = ft_strlen(s1);
	while (ft_strchr(set, s1[end_index - 1]) && end_index)
		end_index--;
	result = ft_substr(s1, begin_index, end_index - begin_index);
	return (result);
}
