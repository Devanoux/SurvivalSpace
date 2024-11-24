/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:31:39 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 23:08:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	summon_ennemy(t_enemy *enemy, t_enemy *enemy_list,
		t_asteroid *asteroid_list)
{
	int	i;
	int	pos_x;
	int	pos_y;

	i = 0;
	if (rand() % 100000 < ENEMY_SPAWN_RATE)
	{
		pos_x = rand() % MAP_WIDTH;
		pos_y = 0;
		while (i < MAX_ENEMY)
		{
			if (enemy_list[i].x == pos_x && enemy_list[i].y == pos_y)
			{
				pos_x = rand() % MAP_WIDTH;
				i = -1;
			}
			i++;
		}
		i = 0;
		while (i < MAX_ASTEROIDS)
		{
			if (asteroid_list[i].alive)
			{
				if (asteroid_list[i].x == pos_x && asteroid_list[i].y == pos_y)
				{
					pos_x = rand() % MAP_WIDTH;
					i = -1;
				}
			}
			i++;
		}
		enemy->x = pos_x;
		enemy->y = pos_y;
		enemy->alive = TRUE;
	}
}

void	move_missile_enemy(t_missile *missiles)
{
	int	i;

	i = 0;
	while (i < MAX_ENEMY_MISSILE)
	{
		if (missiles[i].alive)
		{
			if (!missiles[i].cooldown)
			{
				if (missiles[i].y < MAP_HEIGHT - 1)
				{
					missiles[i].y++;
					missiles[i].cooldown = MISSILE_SPEED;
				}
				else
					missiles[i].alive = FALSE;
			}
			else
				missiles[i].cooldown--;
		}
		i++;
	}
}

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

void	piou_piou_enemy(t_enemy *enemy, t_missile *missiles)
{
	int	i;

	if (enemy->missile_cooldown <= 0 && enemy->y < MAP_HEIGHT - 2)
	{
		i = 0;
		while (i < MAX_ENEMY_MISSILE)
		{
			if (missiles[i].alive == FALSE)
			{
				missiles[i].alive = TRUE;
				missiles[i].x = enemy->x;
				missiles[i].y = enemy->y + 1;
				missiles[i].cooldown = MISSILE_SPEED;
				break ;
			}
			i++;
		}
		enemy->missile_cooldown = ENEMY_COOLDOWN;
	}
	else
		enemy->missile_cooldown--;
}

void	update_enemy(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < MAX_ENEMY)
	{
		if (game->enemy_list[i].alive)
		{
			move_enemy(&game->enemy_list[i]);
			piou_piou_enemy(&game->enemy_list[i], game->missiles);
		}
		else
			summon_ennemy(&game->enemy_list[i], game->enemy_list,
				game->asteroid_list);
		i++;
	}
}
