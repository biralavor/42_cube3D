/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:10:22 by bira              #+#    #+#             */
/*   Updated: 2025/04/23 10:13:16 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalnum(int content)
{
	if ((content >= '0' && content <= '9')
		|| (content >= 'a' && content <= 'z')
		|| (content >= 'A' && content <= 'Z'))
		return (true);
	return (false);
}
