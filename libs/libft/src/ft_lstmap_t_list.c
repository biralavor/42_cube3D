/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_t_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:58:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 10:56:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_t_list(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew_t_list(f(lst->content));
		if (!new_node)
		{
			ft_lstclear_void(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back_void(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
