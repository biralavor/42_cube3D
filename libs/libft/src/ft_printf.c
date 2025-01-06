/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:33:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 18:52:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;
	int		index;

	if (!format)
		return (-1);
	len = 0;
	index = 0;
	va_start(ptr, format);
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] != '\0')
			len += ft_printf_placeholder(format[++index], ptr);
		else
			len += ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(ptr);
	return (len);
}
