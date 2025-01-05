/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:45:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/05/17 17:56:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstend_void(t_list *list, void *value)
{
	t_list	*new_end_node;
	t_list	*current_node;

	if (list == NULL)
		return (NULL);
	new_end_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_end_node == NULL)
		ft_error_msg("Memory allocation failed\n");
	new_end_node->content = value;
	new_end_node->next = NULL;
	current_node = list;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_end_node;
	list = current_node;
	return (list);
}
