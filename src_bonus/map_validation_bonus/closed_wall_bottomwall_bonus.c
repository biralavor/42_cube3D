/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_wall_bottomwall_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:47 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/23 10:25:23 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	bottom_wall_finder(char **arr, char w)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (arr[y][x] && arr[y + 1][x] && arr[y + 1][x] != '\n')
		y++;
	if (arr[y][x] == w)
	{
		while (arr[y][x] && arr[y][x] == w)
		{
			if ((!arr[y][x + 1] || arr[y][x + 1] == '\n')
				&& (!arr[y + 1][0] || arr[y + 1][0] == '\n'))
			{
				if (arr[y][x + 1] == '\n' && linebreak_reader(arr, y, x))
					return (true);
				else if (!arr[y][x + 1])
					return (true);
			}
			x++;
		}
	}
	ft_putstr_fd(RED"Your MAP has a breach on the bottom wall", STDOUT_FILENO);
	return (false);
}
