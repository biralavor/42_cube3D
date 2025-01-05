/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:52:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/10 10:20:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_binary(int number)
{
	int		char_pos;
	char	*binary;

	char_pos = 0;
	binary = ft_calloc((32 + 1), sizeof(char));
	if (binary == NULL)
		ft_error_msg("Memory alllocation failed\n");
	while (number != 0)
	{
		binary[char_pos] = (number % 2) + '0';
		number = number / 2;
		char_pos++;
	}
	binary = ft_strreversing_order(binary);
	binary[char_pos] = '\0';
	return (binary);
}
