/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:49 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 22:36:41 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	run_game(t_game *game)
{
	int input;
	int exit;
	int frames;

	frames = 0;
	while (game->state > 0)
	{
		handle_resize(game);
		input = getch();
		if (game->state == PLAY)
		{
			exit = update_player(game->player, input);
			if (exit == -1)
				game->state = 0;
			update_game(game);
			display_game(game);
		}
		if (game->state == GAME_OVER)
		{
			if (input == ' ')
				game->state = PLAY;
			display_game_over(game, frames);
		}
		wait_for_frame();
		frames++;
		frames %= 100000;
	}
	return (0);
}

int	start_game(int ac, char **av)
{
	t_game	*game;
	int		return_state;

	game = init_game(ac, av);
	if (!game)
		return (-1);
	game->width = COLS;
	game->height = LINES;
	return_state = run_game(game);
	free_game(game);
	return (return_state);
}

int	main(int ac, char **av)
{
	initscr();
	init_scr();
	start_game(ac, av);
	endwin();
	return 0;
}