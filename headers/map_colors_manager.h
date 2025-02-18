/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors_manager.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:41:51 by umeneses          #+#    #+#             */
/*   Updated: 2025/02/18 15:56:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_COLORS_MANAGER_H
# define MAP_COLORS_MANAGER_H

/**
 * @brief Check if the color values are valid, by calling the functions
 * 			`color_digits_counter`, `color_digits_quantity_checker`,
 * 			`no_garbage_at_color_values`, `color_values_into_array`,
 * 			and `colors_with_min_max_values`.
 * @param  arr map array
 * @return true if the color values are valid, false otherwise
 */
bool	map_colors_manager(char **arr);

/**
 * @brief Count the number of digits in the color values.
 * @param  arr map array
 * @param  color_digits array with the number of digits in each color value
 * @return `void`
 */
void	color_digits_counter(char **arr, int *color_digits);

/**
 * @brief Check if the number of digits in the color values is valid,
 * 			for each color_digit position.
 * @param  color_digits array with the number of digits in each color value
 * @return true if the number of digits is valid, false otherwise
 */
bool	color_digits_quantity_checker(int *color_digits);

/**
 * @brief Check if there is no garbage inside the color values. In other words,
 * 				check if the color values are only numbers.
 * @param  arr map array
 * @param  digit current digit position
 * @param  color_digits array with the number of digits in each color value
 * @param  id current color value position
 * @return true if there is no garbage inside the color values, false otherwise
 */
bool	no_garbage_at_color_values(char **arr, int digit,
			int *color_digits, int id);

/**
 * @brief Copy the color values into an array of integers, to be stored in the
 * 			struct `t_map`.
 * @param  arr map array
 * @param  color_values array with the number of digits in each color value
 * @param  rgbrgb array with the color values
 * @return true if the color values were copied successfully, false otherwise
 */
bool	color_values_into_array(char **arr, int *color_values, int *rgbrgb);

/**
 * @brief Convert the color values from char, stored at `arr`, to int,
 * 			by calling `ft_atoi` function
 * @param  rgbrgb array with the color values
 * @param  id current color value position
 * @param  str_digit string to store the color value
 */
void	convert_str_digit_to_int(int *rgbrgb, int *id, char *str_digit);

/**
* @brief Check if the color values are within the range of 0 to 255.
* @param  rgbrgb array with the color values
* @return true if the color values are within the range, false otherwise
*/
bool	colors_with_min_max_values(int *rgbrgb);

#endif