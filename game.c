/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:52:51 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 01:31:43 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_game(t_game *game)
{
	t_asteroid	*asteroid_list;
	t_map		map;
	size_t	i;


	asteroid_list = game->asteroid_list;
	map = game->map;
	i = 0;
	// ASTEROID PART
	update_asteroids(asteroid_list);
	move_missile(game);
	i = 0;
	
	// PLAYER PART
	check_collision(game);
	check_life(game);
	update_map(game);
}