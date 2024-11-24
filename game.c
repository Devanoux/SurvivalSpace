/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:52:51 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 14:11:09 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_game(t_game *game)
{
	update_asteroids(game->asteroid_list);
	update_enemy(game);
	move_missile(game->player->missiles);
	check_collision(game);
	check_life(game);
	update_map(game);
}