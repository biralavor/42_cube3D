/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/01/22 17:44:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	color_digits_quantity_checker(int *color_digits)
{
	int	id;
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
	ft_putstr_fd(RED"Invalid number of digits at Color Map", STDERR_FILENO);
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

bool	color_values_into_array(char **arr, int *color_digits, int *rgbrgb)
{
	int		y;
	int		x;
	int		id;
	char	*one_value;

	y = -1;
	id = 0;
	one_value = NULL;
	while (arr[++y][0])
	{
		x = 1;
		while (color_digits[id] && x++)
		{
			if (arr[y][x] || arr[y][x] != ',' || arr[y][x] != '\n')
				one_value = ft_substr(arr[y], x++, 1);
			while (color_digits[id]-- > 0 && arr[y][x] != ',')
				one_value = ft_strjoin(one_value, ft_substr(arr[y], x++, 1));
			convert_color_digits_id_to_int(arr[y][x], rgbrgb, &id, one_value);
			if (arr[y][x] == '\n' || !arr[y][x])
				break ;
		}
	}
	if (!arr[y][0])
		return (true);
	ft_putstr_fd(RED"Couldn't convert values of Color Map", STDERR_FILENO);
	return (false);
}

void	convert_color_digits_id_to_int(char actual_char, int *rgbrgb, int *id,
		 char *one_value)
{
	if (actual_char == ',' || actual_char == '\n' || !actual_char)
	{
		rgbrgb[*id] = ft_atoi(one_value);
		free(one_value);
		one_value = NULL;
		*id = *id + 1;
	}
}

bool	colors_with_min_max_values(int *rgbrgb)
{
	int			id;
	static int	color_approved[6];

	id = -1;
	while (rgbrgb[++id])
	{
		if (rgbrgb[id] >= 0 && rgbrgb[id] <= 255)
		{
			color_approved[id]++;
			if (id == 5 && color_approved[0] == 1 && color_approved[1] == 1
				&& color_approved[2] == 1 && color_approved[3] == 1
				&& color_approved[4] == 1 && color_approved[5] == 1)
				return (true);
		}
	}
	ft_putstr_fd(RED"Color value in ColorMap out of range", STDERR_FILENO);
	return (false);
}
