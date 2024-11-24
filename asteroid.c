/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:10:46 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 13:59:09 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	summon_asteroid(t_asteroid *asteroid)
{
	if ((rand() % 100) < ASTEROID_SPAWN_RATE)
	{
		asteroid->x = rand() % MAP_WIDTH;
		asteroid->y = 0;
		asteroid->alive = TRUE;
	}
}

void	move_asteroid(t_asteroid *asteroid)
{
	if (!asteroid->cooldown)
	{
		if (asteroid->y < MAP_HEIGHT - 1)
		{
			asteroid->y++;
			asteroid->cooldown = ASTEROID_SPEED;
		}
		else
			asteroid->alive = FALSE;
	}
	else
		asteroid->cooldown--;
}

void	update_asteroids(t_asteroid *asteroid_list)
{
	size_t	i;
	// int		dead_asteroids;

	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (asteroid_list[i].alive)
			move_asteroid(&asteroid_list[i]);
		else
			summon_asteroid(&asteroid_list[i]);
		i++;
	}
}
