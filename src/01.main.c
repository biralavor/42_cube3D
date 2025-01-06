/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:28 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/06 13:13:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"




int main(int ac, char **av)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));

	if(map_validation(ac, av, map))
	{
		printf(GREEN"\n\nHello, Cube3D!\n"RESET);
	}
	else
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
