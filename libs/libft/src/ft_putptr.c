/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:40 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/06 17:48:22 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(long long int n, char *base)
{
	int					len;
	char				*hexalower;

	hexalower = HEXL;
	len = 0;
	if (n == 0)
		len += ft_putstr_fd("(nil)", 1);
	else if (base == hexalower)
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_put_unsigned_nbr(n, HEXL);
	}
	else
	{
		len += ft_putstr_fd("0x", 1);
		len += ft_putnbrbase(n, HEXU);
	}
	return (len);
}
