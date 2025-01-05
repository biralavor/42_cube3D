/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreversing_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:51:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/25 18:51:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreversing_order(char *string)
{
	int		index;
	int		char_position;
	char	temp;

	index = 0;
	char_position = ft_strlen(string);
	while (index < char_position / 2)
	{
		temp = string[index];
		string[index] = string[char_position - index - 1];
		string[char_position - index -1] = temp;
		index++;
	}
	return (string);
}
