/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:21:21 by umeneses          #+#    #+#             */
/*   Updated: 2025/04/22 19:21:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_ALL_H
# define CLEAR_ALL_H

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
