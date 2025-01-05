/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:03:37 by bira              #+#    #+#             */
/*   Updated: 2023/09/03 16:51:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_index(char const *s, char c)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			words++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (words);
}

static size_t	ft_substr_len(char const *s, char c, size_t start)
{
	size_t	sub_len;

	sub_len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		sub_len++;
	}
	return (sub_len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;
	size_t	start;
	size_t	words;
	size_t	sub_len;

	if (!s)
		return (NULL);
	index = 0;
	start = 0;
	words = ft_word_index(s, c);
	result = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (index < words)
	{
		while (s[start] && s[start] == c)
			start++;
		sub_len = ft_substr_len(s, c, start);
		result[index] = ft_substr(s, start, sub_len);
		start = start + sub_len + 1;
		index++;
	}
	result[words] = NULL;
	return (result);
}
