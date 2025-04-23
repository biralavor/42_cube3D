/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:23:03 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 09:23:41 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	setup_ray(t_game *g, float angle, t_ray *r, t_vec *pos)
{
	pos->x = g->player_x;
	pos->y = g->player_y;
	r->dir.x = cos(angle);
	r->dir.y = sin(angle);
	r->map.x = (int)pos->x;
	r->map.y = (int)pos->y;
	setup_step_and_delta(r);
}
