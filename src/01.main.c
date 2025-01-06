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
	if (ac != 2)
	{
		printf("Cube3D needs a map file to starts the game session.\n");
		exit(EXIT_FAILURE);
	}

	printf("I grab the file: %s\n", av[1]);
	
	printf("Hello, Cube3D!\n");
	return (0);
}
