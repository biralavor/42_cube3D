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

	map = NULL;
	if(map_validation(ac, av, map))
	{
		printf("I grab the file: %s\n", av[1]);
		printf("Hello, Cube3D!\n");
	}
	else
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
