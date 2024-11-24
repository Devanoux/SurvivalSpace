/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:49 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 01:54:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>unistd
#include "header.h"

int	GAME_WIDTH;
int	GAME_HEIGHT;

int	run_game(t_game *game)
{
	int input;
	int exit;
	while (game->state > 0)
	{
		input = getch();
		if (game->state == PLAY)
		{
			exit = player_mouvement(game, input);
			if (exit == -1)
				game->state = 0;
			update_game(game);
			display_map(game->map);
			usleep(10000);
		}
		if (game->state == GAME_OVER)
		{
			game->state = 0;
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