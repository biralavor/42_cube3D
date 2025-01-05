/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:44:14 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/23 14:29:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_msg(char *string)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("\n<< Error >> ", STDERR_FILENO);
	ft_putstr_fd(string, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
