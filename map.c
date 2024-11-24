/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:48:18 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 01:21:38 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map map)
{
	int	i;
	int	j;

	j = 0;
	clear();
	while(j < GAME_HEIGHT)
	{
		i = 0;
		while (i < GAME_WIDTH)
		{
			if (map[j][i] == 0)
				printw(" ");
			else if (map[j][i] == 1)
				printw("#");
			else if (map[j][i] == 2)
				printw("A");
			else if (map[j][i] == 3)
				printw("T");
			else if (map[j][i] == 4)
				printw("'");
			else if (map[j][i] == 5)
				printw("*");
			i++;
		}
		j++;
	}
	refresh();
}

void	clean_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < GAME_HEIGHT)
	{
		j = 0;
		while (j < GAME_WIDTH)
		{
			map[i][j] = 0;
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
	while (i < MAX_ASTEROIDS)
	{
		if (game->asteroid_list[i].alive)
		{
			game->map[game->asteroid_list[i].y][game->asteroid_list[i].x] = ASTEROID;
		}
		i++;
	}
	i = 0;
	while (i < 500)
	{
		if (game->player->missiles[i].alive == TRUE)
			game->map[game->player->missiles[i].y][game->player->missiles[i].x] = PLAYER_BULLET;
		i++;
	}
	game->map[game->player->y][game->player->x] = PLAYER;
}

// YOU CAN ADD MORE PARAMETER AFTER LIKES T_MISSILES/ T_ENNEMY AND add others parameters that you don't use to null and you parameters use well set
