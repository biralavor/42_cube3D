/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:09 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/18 15:37:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	*copy_digits_to_str(char **arr, int y, int *x, int *color_digits);

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

bool	color_values_into_array(char **arr, int *color_digits, int *rgbrgb)
{
	int		y;
	int		x;
	int		id;
	char	*str_digit;

	y = -1;
	id = 0;
	while (arr[++y][0])
	{
		x = 1;
		while (color_digits[id] && arr[y][1] == ' ' && x++)
		{
			if (!arr[y][x] || arr[y][x] == '\n')
				break ;
			str_digit = copy_digits_to_str(arr, y, &x, &color_digits[id]);
			convert_str_digit_to_int(rgbrgb, &id, str_digit);
		}
	}
	if (!arr[y][0])
		return (true);
	ft_putstr_fd(YEL"Couldn't convert values of Color Map", STDERR_FILENO);
	return (false);
}

static char	*copy_digits_to_str(char **arr, int y, int *x, int *color_digits)
{
	char	*str_digit;
	char	*first_digit;
	char	*another_digit;
	char	*old_digit;

	str_digit = NULL;
	first_digit = NULL;
	another_digit = NULL;
	old_digit = NULL;
	if (arr[y][*x] == ',' || arr[y][*x] == '\n')
		(*x)++;
	first_digit = ft_substr(arr[y], *x, 1);
	if (!str_digit)
		str_digit = first_digit;
	while (--(*color_digits) > 0 && arr[y][*x] != ',')
	{
		another_digit = ft_substr(arr[y], (*x)++, 1);
		old_digit = str_digit;
		str_digit = ft_strjoin(old_digit, another_digit);
		free(old_digit);
		free(another_digit);
	}
	free(first_digit);
	return (str_digit);
}

void	convert_str_digit_to_int(int *rgbrgb, int *id,
			char *str_digit)
{
	rgbrgb[*id] = ft_atoi(str_digit);
	*id = *id + 1;
	free(str_digit);
	str_digit = NULL;
}

bool	colors_with_min_max_values(int *rgbrgb)
{
	int			id;
	static int	approved_color[6];

	id = 0;
	while (rgbrgb)
	{
		if (rgbrgb[id] >= 0 && rgbrgb[id] <= 255)
		{
			approved_color[id]++;
			if (id == 5 && approved_color[0] == 1 && approved_color[1] == 1
				&& approved_color[2] == 1 && approved_color[3] == 1
				&& approved_color[4] == 1 && approved_color[5] == 1)
				return (true);
			id++;
		}
		else
			break ;
	}
	ft_putstr_fd(YEL"Color value in ColorMap out of range", STDERR_FILENO);
	return (false);
}
