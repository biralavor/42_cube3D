/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:22:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/29 10:57:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	str_lenght;

	str_lenght = ft_strlen(s);
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (write(fd, s, str_lenght));
}
