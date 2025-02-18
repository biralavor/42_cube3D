/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/18 15:45:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	map_colors_manager(char **arr)
{
	static int	color_digits[6];
	static int	rgbrgb[6];
	int			digit;
	int			id;

	id = 0;
	digit = 0;
	color_digits_counter(arr, color_digits);
	if (color_digits_quantity_checker(color_digits))
	{
		if (!no_garbage_at_color_values(arr, digit, color_digits, id))
		{
			ft_putstr_fd(YEL"Garbage inside MapColors detected", STDERR_FILENO);
			return (false);
		}
		if (color_values_into_array(arr, color_digits, rgbrgb)
			&& colors_with_min_max_values(rgbrgb))
		{
			printf(GRE"✅ Color Map \t\tapproved!\n");
			return (true);
		}
	}
	return (false);
}

void	color_digits_counter(char **arr, int *color_digits)
{
	int	y;
	int	x;
	int	id;
	int	comma_counter;

	y = -1;
	id = 0;
	while (arr[++y][0])
	{
		comma_counter = 0;
		x = 1;
		while (comma_counter < 3)
		{
			while (arr[y][++x] && arr[y][x] != ','
				&& arr[y][x] != '\n')
				color_digits[id]++;
			comma_counter++;
			id++;
			if (arr[y][x + 1] == '\n')
				break ;
		}
	}
}

bool	color_digits_quantity_checker(int *color_digits)
{
	int			id;
	static int	quant_approved[6];

	id = -1;
	while (++id < 6)
	{
		if (color_digits[id] >= 1 && color_digits[id] <= 3)
		{
			quant_approved[id]++;
			if (quant_approved[0] == 1 && quant_approved[1] == 1
				&& quant_approved[2] == 1 && quant_approved[3] == 1
				&& quant_approved[4] == 1 && quant_approved[5] == 1)
				return (true);
		}
	}
	ft_putstr_fd(YEL"Invalid number of digits at Color Map", STDERR_FILENO);
	return (false);
}

bool	no_garbage_at_color_values(char **arr, int digit,
	int *color_digits, int id)
{
	int	y;
	int	x;

	y = -1;
	while (arr[++y][0])
	{
		x = 1;
		while (digit++ <= color_digits[id] && ++x)
		{
			if (ft_isdigit(arr[y][x]) && id == 5 && (arr[y][x + 1] == '\n'
				|| !arr[y][x + 1]))
				return (true);
			if (arr[y][x] == ',' || arr[y][x] == '\n' || !arr[y][x])
			{
				id++;
				digit = 0;
				if (arr[y][x] == '\n' || !arr[y][x])
					break ;
			}
			else if (!ft_isdigit(arr[y][x]))
				return (false);
		}
	}
	return (false);
}
