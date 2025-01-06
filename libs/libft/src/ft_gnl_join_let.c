/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_join_let.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:15:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 11:23:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gnl_join_let(t_char **head, t_char *new_let)
{
	t_char	*temp;

	if (!new_let)
		return ;
	if (!*head)
	{
		*head = new_let;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_let;
}
