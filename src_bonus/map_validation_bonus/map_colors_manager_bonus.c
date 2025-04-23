/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors_manager_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:20:52 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/23 10:25:43 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	apply_rgb_to_map(t_map *map, int *rgb)
{
	map->floor_color = (rgb[0] << 24) | (rgb[1] << 16)
		| (rgb[2] << 8) | 0xFF;
	map->ceiling_color = (rgb[3] << 24) | (rgb[4] << 16)
		| (rgb[5] << 8) | 0xFF;
	printf(GRE"✅ Color Map \t\tapproved!\n");
	return (true);
}

bool	map_colors_manager(t_map *map)
{
	static int	color_digits[MAX_RGB_SLOTS];
	static int	rgbrgb[MAX_RGB_SLOTS];
	int			digit;
	int			id;

	id = 0;
	digit = 0;
	color_digits_counter(map->colors, color_digits);
	if (color_digits_quantity_checker(color_digits))
	{
		if (!no_garbage_at_color_values(map->colors, digit, color_digits, id))
		{
			ft_putstr_fd(YEL"Garbage inside MapColors detected", STDERR_FILENO);
			return (false);
		}
		if (color_values_into_array(map->colors, color_digits, rgbrgb)
			&& colors_with_min_max_values(rgbrgb))
			return (apply_rgb_to_map(map, rgbrgb));
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
		while (comma_counter < (MAX_RGB_SLOTS / 2))
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
	static int	quant_approved[MAX_RGB_SLOTS];

	id = -1;
	while (++id < MAX_RGB_SLOTS)
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
