/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:09:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/24 19:24:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_items, size_t size)
{
	void	*result;
	size_t	safety_arg;
	size_t	int_min;

	int_min = -2147483648;
	if (n_items == 0 && size == 0)
		return (malloc(0));
	if (n_items == int_min || size == int_min)
		return (NULL);
	safety_arg = n_items * size;
	if (safety_arg != 0 && ((safety_arg / n_items) != size))
		return (NULL);
	result = malloc(safety_arg);
	if (!result)
		return (NULL);
	ft_bzero(result, safety_arg);
	return (result);
}
