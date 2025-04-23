/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:43:16 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 14:51:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	handle_mouse_direction(double m_xpos, double m_ypos, void *param)
{
	t_game			*game;
	static double	last_mouse_xpos = -1;
	double			sensibility;
	double			rotation;

	game = (t_game *)param;
	sensibility = 0.015;
	(void)m_ypos;
	if (last_mouse_xpos < 0)
		last_mouse_xpos = m_xpos;
	rotation = (m_xpos - last_mouse_xpos) * sensibility;
	if (fabs(rotation) > 0.0001)
	{
		rotate_player(game, rotation);
	}
	last_mouse_xpos = m_xpos;
	render(game);
}
