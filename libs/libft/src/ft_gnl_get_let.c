/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_get_let.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:13:42 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 11:24:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char	*ft_gnl_get_let(char let)
{
	t_char	*def_char;

	def_char = (t_char *)ft_calloc(1, sizeof(t_char));
	if (!def_char)
		return (NULL);
	def_char->c = let;
	def_char->next = NULL;
	return (def_char);
}
