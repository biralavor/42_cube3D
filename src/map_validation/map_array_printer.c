/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/12 15:28:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_array_printer(char **array)
{
	int	y_id;
	int	x_id;

	y_id = 0;
	fprintf(stderr, YELLOW"\\ Printing Array Content__________________________\n");
	while (array[y_id])
	{
		fprintf(stderr, YELLOW"\\ ");
		fprintf(stderr, CYAN"[ %p ] ", *array);
		fprintf(stderr, YELLOW"%2d ", y_id);
		fprintf(stderr, RESET" = ");
		if (array[y_id][0] == '\0' && array[y_id + 1][0] == '\0')
		{
			fprintf(stderr, PURPLE"\\0\n");
			break ;
		}
		x_id = 0;
		while (array[y_id][x_id])
		{	
			if (array[y_id][x_id] == '\0')
				fprintf(stderr, PURPLE"\\0");
			else if (array[y_id][x_id] == '\n')
			{
				fprintf(stderr, PURPLE"\\n");
				// continue ;
			}
			else
				fprintf(stderr, BLUE"%c", array[y_id][x_id]);
			x_id++;
		}
		fprintf(stderr, RESET"\n");
		y_id++;
	}
	fprintf(stderr, YELLOW"\\ End of Array Printing___________________________\n"RESET);
}
