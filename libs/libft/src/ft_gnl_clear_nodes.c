/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_clear_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:24:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 11:31:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_clear_nodes(t_char *str)
{
	t_char	*temp;

	temp = str;
	while (temp)
	{
		temp = temp->next;
		free (str);
		str = temp;
	}
	temp = NULL;
	return (NULL);
}
