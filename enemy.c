/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:31:39 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 15:38:12 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	summon_ennemy(t_enemy *enemy_list, t_asteroid *asteroid_list)
{
	int	i;
	int pos_x;
	int	pos_y;

	i = 0;
	if (rand()%1000 < ENEMY_SPAWN_RATE)
	{
		pos_x = rand()% MAP_HEIGHT;
		pos_y = 0;
		while (i < MAX_ENEMY)
		{
			if (enemy_list[i].x == pos_x && enemy_list[i].y == pos_y)
			{
				pos_x = rand()% MAP_HEIGHT;
				i = -1;
			}
			i++;
		}
		i = 0;
		while (i < MAX_ASTEROIDS)
		{
			if (asteroid_list[i].alive)
			{
				if(asteroid_list[i].x == pos_x && asteroid_list[i].y == pos_y)
				{
					pos_x = rand()% MAP_HEIGHT;
					i = -1;
				}
			}
			i++;
		}
		enemy_list->x = pos_x;
		enemy_list->y = pos_y;
		enemy_list->alive = TRUE;
	}	
}
// CHECK IF AN ASTEROID IS IN THE NEXT CASE
void	move_enemy(t_enemy *enemy)
{
	if (!enemy->cooldown)
	{
		if (enemy->y < MAP_HEIGHT - 1)
		{
			enemy->y++;
			enemy->cooldown = ENEMY_SPEED;
		}
		else
			enemy->alive = FALSE;
	}
	else
		enemy->cooldown--;
}

void	update_enemy(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < MAX_ENEMY)
	{
		if (game->enemy_list[i].alive)
			move_enemy(&game->enemy_list[i]);
		else
			summon_ennemy(&game->enemy_list[i], game->asteroid_list);
		i++;
	}
}
