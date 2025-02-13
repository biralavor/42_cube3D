/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_topwall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/13 17:11:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	top_wall_finder(char **arr, char w)
{
	int		x;

	x = 0;
	if (arr[0][x] == w)
	{
		while (arr[0][++x] && arr[0][x] == w)
		{
			if (!arr[0][x + 1])
				return (true);
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the top wall", STDOUT_FILENO);
	return (false);
}
