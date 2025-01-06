/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_placeholder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:52:19 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 18:52:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_placeholder(char format, va_list ptr)
{
	int	len;

	len = 0;
	if ('c' == format)
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if ('s' == format)
		len += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (('i' == format) || ('d' == format))
		len += ft_putnbrbase(va_arg(ptr, int), DEC);
	else if ('u' == format)
		len += ft_putnbr_fd(va_arg(ptr, unsigned int), 1);
	else if ('%' == format)
		len += ft_putchar_fd(37, 1);
	else if ('x' == format)
		len += ft_putnbrbase((long long)va_arg(ptr, unsigned int), HEXL);
	else if ('X' == format)
		len += ft_putnbrbase((long long)va_arg(ptr, unsigned int), HEXU);
	else if ('p' == format)
		len += ft_putptr((long long)va_arg(ptr, long long), HEXL);
	return (len);
}
