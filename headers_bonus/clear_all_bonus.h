/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigardin <gigardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:37:03 by gigardin          #+#    #+#             */
/*   Updated: 2025/04/23 10:37:06 by gigardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_ALL_BONUS_H
# define CLEAR_ALL_BONUS_H

/**
 * @brief Free the memory allocated for the entire struct (map->gamemap,
 * 			map->ggraph, map->colors) and others game data.
 * @param  game struct with all game data
 * @return `void`
 */
void	clear_all_exit_smoothly(t_game *game);

void	free_textures(t_game *g);
void	cleanup(t_game *game);

#endif
