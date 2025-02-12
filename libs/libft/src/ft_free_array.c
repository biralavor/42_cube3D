/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:40:12 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/11 16:24:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **array)
{
	char	**tmp;
	int		idx;

	if (!array)
		return ;
	idx = 0;
	tmp = array;
	while (tmp && tmp[idx] != NULL)
	{
		free(tmp[idx]);
		tmp[idx] = NULL;
		idx++;
	}
	free(array);
	array = NULL;
}
