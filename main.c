/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:49 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 21:22:22 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	GAME_WIDTH;
int	GAME_HEIGHT;

int	run_game(t_game *game)
{
	while (game->state > 0)
	{
		if (game->state == PLAY)
		{
			// Here adding all change in the map asteroids / ennemys / player / bullet
			// Update map get all this info and modify the map to get a new
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

// void run_game(int scr_width, int scr_height)
// {
// 	char tab[scr_height][scr_width];
// 	int	running;
// 	int input;
// 	int is_space;
// 	int posX;
// 	int posY;

// 	running = TRUE;
// 	posX = scr_width / 2;
// 	posY = scr_height / 2;
// 	is_space = 0;
// 	while (running)
// 	{
// 		input = getch();
// 		if (input == ' ')
// 			is_space = TRUE;
// 		else
// 			is_space = FALSE;
// 		switch (input)
// 		{
// 		case 27:
// 			running = FALSE;
// 			break ;
// 		case 'w':
// 			posY -= posY > 0;
// 			break ;
// 		case 's':
// 			posY += posY < GAME_HEIGHT - 1;
// 			break ;
// 		case 'a':
// 			posX -= posX > 0;
// 			break ;
// 		case 'd':
// 			posX += posX < GAME_WIDTH - 1;
// 			break ;
// 		default:
// 			break ;
// 		}
// 		clear();
// 		printw(",d88b.d88b,\n");
// 		printw("88888888888\n");
// 		printw("`Y8888888Y'\n");
// 		printw("  `Y888Y'  \n");
// 		printw("    `Y'    \n");
// 		printw(",d88b.d88b,\n");
// 		printw("88888888888\n");
// 		printw("`Y8888888Y'\n");
// 		printw("  `Y888Y'  \n");
// 		printw("    `Y'    \n");
// 		move(posY, posX);
// 		printw("A");
// 		refresh();
// 		wait_for_frame();
// 	}
// }

// int	main(void)
// {
// 	initscr();
// 	run_game(GAME_WIDTH, GAME_HEIGHT);
// 	endwin();
// 	return (0);
// }
