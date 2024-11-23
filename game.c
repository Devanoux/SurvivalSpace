/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:52:51 by ebini             #+#    #+#             */
/*   Updated: 2024/11/23 22:12:57 by ebini            ###   ########lyon.fr   */
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
	i = 0;
	
	// PLAYER PART
	check_collision(asteroid_list, game->player);
	update_map(game);
}