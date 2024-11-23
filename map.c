/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:48:18 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 17:24:38 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	display_map(int **map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	clear();
	while(j < LINES)
	{
		while (i < COLS)
		{
			if (map[j][i] == 0)
				printw(" ");
			else if (map[j][i] == 1)
				printw("#");
			else if (map[j][i] == 2)
				printw("A");
			i++;
		}
		i = 0;
		j++;
	}
	refresh();
}


void	destroy_entities(t_asteroid *asteroid, int i)
{
	asteroid[i].x = 0;
	asteroid[i].y = rand()%COLS;
}

// YOU CAN ADD MORE PARAMETER AFTER LIKES T_MISSILES/ T_ENNEMY AND add others parameters that you don't use to null and you parameters use well set

void	update_map(int **map, t_asteroid *list_asteroid, t_player *player)
{
	size_t	i;

	i = 0;
	

	// ASTEROID PART
	while (i < 42)
	{
 		map[list_asteroid[i].x][list_asteroid[i].y] = 0;
		i++;
	}
	move_asteroid(list_asteroid);
	i = 0;
	while (i < 42)
	{
		map[list_asteroid[i].x][list_asteroid[i].y] = 1;
		i++;
	}
	
	check_collision(list_asteroid, player);

	

	// PLAYER PART
}


