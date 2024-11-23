/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:28:21 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 17:21:31 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spawn_player(int **map, t_player *player)
{
	player->life = 3;
	player->x = LINES - 3;
	player->y = COLS / 2;
		
	map[player->x][player->y] = 2;
}


// MUST CHECK Collision to asteroid or ennemy / bullet set all in the defintiion
// function but if we want just verify only one set other to NULL
void	check_collision(t_asteroid *list_asteroid, t_player *player)
{
	int	i;
	// Change 42 for nb_max of asteroid
	i = 0;
	while (i < 42)
	{
		if (list_asteroid[i].x == player->x && list_asteroid[i].y == player->y)
		{
			destroy_entities(list_asteroid, i);
			player->life--;
		}
		i++;
	}
	if (player->life == 0)
		game_over()	;
}