/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:43:36 by ebini             #+#    #+#             */
/*   Updated: 2024/11/23 23:19:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

static t_player	*init_player(void)
{
	t_player	*new_player;

	new_player = malloc(sizeof(t_player));
	if (!new_player)
		return (NULL);
	new_player->life = 3;
	new_player->x = GAME_WIDTH / 2;
	new_player->y = GAME_HEIGHT - 3;
	return (new_player);
}

static t_map	init_map(void)
{
	t_map	new_map;
	int		i;

	new_map = malloc(GAME_HEIGHT * sizeof(int *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < GAME_HEIGHT)
	{
		new_map[i] = calloc(GAME_WIDTH, sizeof(int));
		i++;
	}
	return (new_map);
}

static t_asteroid	*init_asteroids(void)
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

t_game	*init_game(void)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	if (!new_game)
		return (NULL);
	new_game->player = init_player();
	if (!new_game->player)
		return (NULL);
	// !:! FREE if error
	new_game->asteroid_list = init_asteroids();
	if (!new_game->asteroid_list)
		return (NULL);
	new_game->map = init_map();
	new_game->state = PLAY;
	return (new_game);
}

void	init_scr()
{
	timeout(0);
	noecho();
	cbreak();
	curs_set(0);
	start_color();
	keypad(stdscr, TRUE);
}
