/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:52:51 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 19:35:05 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_game(t_game *game)
{
	check_collision(game);
	update_asteroids(game->asteroid_list);
	update_enemy(game);
	move_missile_player(game->player->missiles);
	move_missile_enemy(game->missiles);
	check_life(game);
	update_map(game);
}