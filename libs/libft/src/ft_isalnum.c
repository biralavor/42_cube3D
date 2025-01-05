/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:10:22 by bira              #+#    #+#             */
/*   Updated: 2024/06/28 14:32:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int content)
{
	if ((content >= '0' && content <= '9') || \
			(content >= 'a' && content <= 'z') || \
			(content >= 'A' && content <= 'Z'))
		return (true);
	return (false);
}
