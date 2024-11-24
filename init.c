/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:43:36 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 14:23:35 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "header.h"

t_missile	*init_missiles(void)
{
	t_missile *new_missiles_list;
	int	i;

	new_missiles_list = malloc(MAX_PLAYER_MISSILE * sizeof(t_missile));
	if (!new_missiles_list)
		return (NULL);
	i = 0;
	while (i < MAX_PLAYER_MISSILE)
	{
		new_missiles_list[i].alive =  FALSE;
		new_missiles_list[i].x = 0;
		new_missiles_list[i].y = 0;
		i++; 
	}
	return (new_missiles_list);
}

t_player	*init_player()
{
	t_player	*new_player;

	new_player = malloc(sizeof(t_player));
	if (!new_player)
		return (NULL);
	new_player->life = 3;
	new_player->x = MAP_WIDTH / 2;
	new_player->y = MAP_HEIGHT - 3;
	new_player->cooldown = 0;
	new_player->missiles = init_missiles();
	return (new_player);
}

t_map	init_map(void)
{
	t_map	new_map;
	int		i;

	new_map = malloc(MAP_HEIGHT * sizeof(int *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < MAP_HEIGHT)
	{
		new_map[i] = calloc(MAP_WIDTH, sizeof(int));
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}

t_enemy	*init_enemys(void)
{
	t_enemy	*new_enemy_list;
	int	i;

	new_enemy_list = malloc(MAX_ENEMY * sizeof(t_enemy));
	if (!new_enemy_list)
		return (NULL);
	i = 0;
	while (i < MAX_ENEMY)
	{
		new_enemy_list[i].alive = FALSE;
		new_enemy_list[i].x = 0;
		new_enemy_list[i].y = 0;
		i++;
	}
	return (new_enemy_list);
}

t_asteroid	*init_asteroids(void)
{
	t_asteroid	*new_asteroid_list;
	int			i;

	new_asteroid_list = malloc(MAX_ASTEROIDS * sizeof(t_asteroid));
	if (!new_asteroid_list)
		return (NULL);
	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		new_asteroid_list[i].alive = FALSE;
		new_asteroid_list[i].x = 0;
		new_asteroid_list[i].x = 0;
		i++;
	}
	return (new_asteroid_list);
}

t_user	*init_user(int ac, char **av)
{
	t_user	*new_user;

	new_user = malloc(sizeof(t_user));
	if (!new_user)
		return(NULL);
	new_user->score = 0;
	new_user->start_time = time(NULL);
	if (ac > 1)
		new_user->username = av[1];
	else
		new_user->username = "Player";
	return (new_user);
}

t_game	*init_game(int ac, char **av)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	if (!new_game)
		return (NULL);
	new_game->player = init_player();
	if (!new_game->player)
	{
		free(new_game);
		return (NULL);
	}
	// !:! FREE if error
	new_game->asteroid_list = init_asteroids();
	if (!new_game->asteroid_list)
		return (NULL);
	new_game->enemy_list = init_enemys();
	if (!new_game->enemy_list)
		return (NULL);
	new_game->user = init_user(ac, av);
	if (!new_game->user)
		return (NULL);
	new_game->map = init_map();
	if (!new_game->map)
		return(NULL);
	new_game->state = PLAY;
	return (new_game);
}

void	init_scr()
{
	timeout(0);
	noecho();
	cbreak();
	curs_set(0);
	//start_color();
	srand(time(NULL));
	keypad(stdscr, TRUE);
	setlocale(LC_ALL, "");
}
