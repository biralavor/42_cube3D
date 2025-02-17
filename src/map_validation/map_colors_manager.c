/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:07 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/17 19:35:29 by umeneses         ###   ########.fr       */
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
