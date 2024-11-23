/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:49 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 23:53:03 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	GAME_WIDTH;
int	GAME_HEIGHT;

int	run_game(t_game *game)
{
	int input;
	while (game->state > 0)
	{
		input = getch();
		if (game->state == PLAY)
		{
			// Here adding all change in the map asteroids / ennemys / player / bullet
			// Update map get all this info and modify the map to get a new
			player_mouvement(game, input);
			update_game(game);
			// display the map with news
			display_map(game->map);
			usleep(10000);
		}
	}
	return (0);
}

int	start_game(void)
{
	t_game	*game;

	GAME_WIDTH = COLS;
	GAME_HEIGHT = LINES;
	game = init_game();
	if (!game)
		return (-1);
	return (run_game(game));
}

int	main(void)
{
	initscr();
	init_scr();
	start_game();
	endwin();
	return 0;
}