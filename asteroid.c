/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:10:46 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 20:58:58 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	summon_asteroid(t_map map, t_asteroid *asteroid_list)
{
	size_t	nb_asteroid;
	size_t	random_x;
	size_t	random_y;

	nb_asteroid = 0;
	while (nb_asteroid < MAX_ASTEROIDS)
	{
		random_y = rand()%GAME_WIDTH;
		random_x = rand()%GAME_HEIGHT;
		asteroid_list[nb_asteroid].x = random_x;
		asteroid_list[nb_asteroid].y = random_y;
		map[random_x][random_y] = 1;
		nb_asteroid++;
	}
}

void	move_asteroid(t_asteroid *asteroid_list)
{
	size_t i;

	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (asteroid_list[i].x < GAME_HEIGHT - 1)
			asteroid_list[i].x++;
		else
			asteroid_list[i].alive = FALSE;
		i++;
	}
}