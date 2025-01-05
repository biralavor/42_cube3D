/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:33:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 18:51:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase(long long int n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		len += ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base_len)
		len += ft_putnbrbase((n / base_len), base);
	len += ft_putchar_fd(base[n % base_len], 1);
	return (len);
}
