/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:48:18 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 20:01:48 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			map[i][j] = VOID;
			j++;
		}
		i++;
	}
} 

void	update_map(t_game *game)
{
	int i;

	clean_map(game->map);
	i = 0;
	while (i < MAX_PLAYER_MISSILE)
	{
		if (game->player->missiles[i].alive == TRUE)
			game->map[game->player->missiles[i].y][game->player->missiles[i].x] = PLAYER_MISSILE;
		i++;
	}
	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (game->asteroid_list[i].alive)
			game->map[game->asteroid_list[i].y][game->asteroid_list[i].x] = ASTEROID;
		i++;
	}
	i = 0;
    while (i < MAX_ENEMY)
	{
		if (game->enemy_list[i].alive)
			game->map[game->enemy_list[i].y][game->enemy_list[i].x] = ENEMY;
		i++;
	}
	i = 0;
	while (i < MAX_ENEMY_MISSILE)
	{
		if (game->missiles[i].alive == TRUE)
			game->map[game->missiles[i].y][game->missiles[i].x] = ENEMY_MISSILE;
		i++;
	}
	game->map[game->player->y][game->player->x] = PLAYER;
}
