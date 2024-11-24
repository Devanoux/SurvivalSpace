/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:14:05 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 22:39:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <time.h>
#include "header.h"


void usleep(long seconds, long nanoseconds) {
    struct timespec req = {0};
    req.tv_sec = seconds;
    req.tv_nsec = nanoseconds;

    nanosleep(&req, NULL);
}

void	display_game_over(t_game *game, int frames)
{
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2), (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "      NO!                          MNO!   ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 1, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "     MNO!!                        MNNOO!  ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 2, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "   MMNO!                           MNNOO!!");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 3, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), " MNOONNOO!   MMMMMMMMMMPPPOII!   MNNO!!!! ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 4, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), " !O! NNO! MMMMMMMMMMMMMPPPOOOII!! NO!     ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 5, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "       ! MMMMMMMMMMMMMPPPPOOOOIII! !      ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 6, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "        MMMMMMMMMMMMPPPPPOOOOOOII!!       ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 7, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "        MMMMMOOOOOOPPPPPPPPOOOOMII!       ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 8, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "        MMMMM..    OPPMMP    .,OMI!       ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 9, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "        MMMM::   o.,OPMP,.o   ::I!!       ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 10, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "          NNM:::.,,OOPM!P,.::::!!         ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 11, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "         MMNNNNNOOOOPMO!!IIPPO!!O!        ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 12, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "         MMMMMNNNNOO:!!:!!IPPPPOO!        ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 13, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "          MMMMMNNOOMMNNIIIPPPOO!!         ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 14, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "             MMMONNMMNNNIIIOO!            ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 15, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "           MN MOMMMNNNIIIIIO! OO          ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 16, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "          MNO! IiiiiiiiiiiiI OOOO         ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 17, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "     NNN.MNO!   O!!!!!!!!!O   OONO NO!    ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 18, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "    MNNNNNO!    OOOOOOOOOOO    MMNNON!    ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 19, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "      MNNNNO!    PPPPPPPPP    MMNON!      ");
	mvprintw((game->height / 2) - (GAME_OVER_IMAGE_HEIGHT / 2) + 20, (game->width / 2) - (GAME_OVER_IMAGE_WIDTH / 2), "         OO!                   ON!        ");

	if (frames % 100 >= 50)
	{
		mvprintw(game->height / 2 + 15, game->width / 2 - 13, "                       ");
		refresh();
	}
	else
	{
		mvprintw(game->height / 2 + 15, game->width / 2 - 13 , "Press Space to continue");
		refresh();
	}
}

void	add_n_str_colored(char *s, int n, WINDOW *win, int y, int x)
{
	int	i;

	init_color(8, 750, 750, 750);	// LIGHT GREY
	init_color(9, 1000, 500, 0);	// ORANGE
	init_pair(1, 8, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, 9, COLOR_BLACK);
	i = 0;
	while (i < n)
	{
		switch (s[i])
		{
			case ASTEROID:
				wattron(win, COLOR_PAIR(1));
				break;
			case PLAYER:
				wattron(win, COLOR_PAIR(2));
				break;
			case ENEMY:
				wattron(win, COLOR_PAIR(3));
				break;
			case ENEMY_MISSILE:
				wattron(win, COLOR_PAIR(4));
				break;
			default:
				break;
		}
		mvwaddch(win, y, x + i, s[i]);
		wattroff(win, COLOR_PAIR(1));
		wattroff(win, COLOR_PAIR(2));
		wattroff(win, COLOR_PAIR(3));
		wattroff(win, COLOR_PAIR(4));
		i++;
	}
}

WINDOW	*display_map(t_game *game)
{
	WINDOW *win;
	int	i;

	win = newwin(MAP_HEIGHT + 2, MAP_WIDTH + 2, (game->height / 2) - (MAP_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2));
	if (!win)
		return (NULL);
	box(win, 0, 0);
	wrefresh(win);
	i = 0;
	while (i < MAP_HEIGHT)
	{
		add_n_str_colored(game->map[i], MAP_WIDTH, win, i + 1, 1);
		i++;
	}
	return (win);
}


WINDOW	*display_statistics(t_game *game)
{
	WINDOW *win;
	
	win = newwin(STAT_HEIGHT + 2, STAT_WIDTH + 2, (game->height / 2) - (STAT_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2) - STAT_MARGIN - (STAT_WIDTH + 2));
	if (!win)
		return (NULL);
	box(win, 0, 0);
	mvwaddnstr(win, 1, max(((STAT_WIDTH + 2) / 2) - (strlen(game->user->username) / 2), 1), game->user->username, min(strlen(game->user->username), STAT_WIDTH)); // (STAT_WIDTH / 2) - 3 is to center the string "PLAYER"
	mvwprintw(win, 2, STAT_PADDING + 1, "Score : %d", game->user->score);
	mvwprintw(win, 3, STAT_PADDING + 1, "Timer : %ld", time(NULL) - game->user->start_time);
	return (win);
}

WINDOW	*display_health(t_game *game)
{
	WINDOW *win;
	int	i;

	win = newwin(HEART_HEIGHT * game->player->life, HEALTH_WIDTH, (game->height / 2) - ((HEART_HEIGHT * game->player->life) / 2), 1 + (game->width / 2) + ((MAP_WIDTH + 2) / 2) + HEALTH_MARGIN);
	if (!win)
		return (NULL);
	i = 0;
	while (i < game->player->life)
	{
		mvwprintw(win, i * HEART_HEIGHT, 0,      ",d88b.d88b,");
		mvwprintw(win, i * HEART_HEIGHT + 1, 0,  "88888888888");
		mvwprintw(win, i * HEART_HEIGHT + 2, 0,  "`Y8888888Y'");
		mvwprintw(win, i * HEART_HEIGHT + 3, 0,  "  `Y888Y'  ");
		mvwprintw(win, i * HEART_HEIGHT + 4, 0,  "    `Y'    ");
		i++;
	}
	return (win);
}

void	display_game(t_game *game)
{
	WINDOW	*stat_window;
	WINDOW	*health_window;
	WINDOW	*map_window;

	stat_window = NULL;
	health_window = NULL;
	clear();
	if (STAT_WIDTH < (game->width / 2) - (MAP_WIDTH / 2) - 2 - (STAT_MARGIN * 2))
	{
		stat_window = display_statistics(game);
		health_window = display_health(game);
	}
	map_window = display_map(game);
	if (health_window) wrefresh(health_window);
	if (stat_window) wrefresh(stat_window);
	if (map_window) wrefresh(map_window);
	if (health_window) delwin(health_window);
	if (stat_window) delwin(stat_window);
	if (map_window) delwin(map_window);
}
