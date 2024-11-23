/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:28:21 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 20:56:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// MUST CHECK Collision to asteroid or ennemy / bullet set all in the defintiion
// function but if we want just verify only one set other to NULL
void	check_collision(t_asteroid *asteroid_list, t_player *player)
{
	int	i;

	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (asteroid_list[i].x == player->x && asteroid_list[i].y == player->y)
		{
			asteroid_list[i].alive = FALSE;
			player->life--;
		}
		i++;
	}
}