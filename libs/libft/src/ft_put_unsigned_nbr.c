/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:50:26 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 18:50:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_nbr(unsigned long long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		len += ft_putnbrbase((n / base_len), base);
	len += ft_putchar_fd(base[n % base_len], 1);
	return (len);
}
