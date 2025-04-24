/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:14:30 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/24 17:26:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	inside_array_content_printer(char **array, int y_id);

void	map_array_printer(char **array, char *array_name)
{
	int	y_id;

	y_id = 0;
	ft_printf(YEL"\\ Printing Array from: "CYA"   %s\n", array_name);
	while (array[y_id])
	{
		ft_printf(YEL"\\ "CYA"[ %p ] %d "RESET" = ", *array, y_id);
		if (array[y_id][0] == '\0' && array[y_id + 1][0] == '\0')
		{
			ft_printf(PUR"\\0\n");
			break ;
		}
		inside_array_content_printer(array, y_id);
		ft_printf(RESET"\n");
		y_id++;
	}
	ft_printf(YEL"\\ End of Array Printing_______________________\n");
}

static void	inside_array_content_printer(char **array, int y_id)
{
	int	x_id;
	int	max_len;

	x_id = 0;
	if (array[y_id][x_id])
		max_len = (int)ft_strlen(array[y_id]);
	else
		return ;
	while (x_id < max_len)
	{
		if (array[y_id][x_id] == '\0')
			ft_printf(PUR"\\0");
		else if (array[y_id][x_id] == '\n')
			ft_printf(PUR"\\n");
		else
			ft_printf(BLU"%c", array[y_id][x_id]);
		x_id++;
	}
}
