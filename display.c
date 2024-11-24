/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:14:05 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 18:26:45 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <time.h>
#include "header.h"

WINDOW	*display_map(t_game *game)
{
	WINDOW *win;
	int	i;

	win = newwin(MAP_HEIGHT + 2, MAP_WIDTH + 2, (game->height / 2) - (MAP_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2));
	box(win, 0, 0);
	wrefresh(win);
	i = 0;
	while (i < MAP_HEIGHT)
	{
		mvwaddnstr(win, i + 1, 1, game->map[i], MAP_WIDTH);
		i++;
	}
	return (win);
}

WINDOW	*display_statistics(t_game *game)
{
	WINDOW *win;
	
	win = newwin(STAT_HEIGHT + 2, STAT_WIDTH + 2, (game->height / 2) - (STAT_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2) - STAT_MARGIN - (STAT_WIDTH + 2));
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

	init_pair(1, COLOR_RED, COLOR_BLACK);
	win = newwin(HEART_HEIGHT * game->player->life, HEALTH_WIDTH, (game->height / 2) - ((HEART_HEIGHT * game->player->life) / 2), 1 + (game->width / 2) + ((MAP_WIDTH + 2) / 2) + HEALTH_MARGIN);
	i = 0;
	wattron(win, COLOR_PAIR(1));
	while (i < game->player->life)
	{
		mvwprintw(win, i * HEART_HEIGHT, 0,      ",d88b.d88b,");
		mvwprintw(win, i * HEART_HEIGHT + 1, 0,  "88888888888");
		mvwprintw(win, i * HEART_HEIGHT + 2, 0,  "`Y8888888Y'");
		mvwprintw(win, i * HEART_HEIGHT + 3, 0,  "  `Y888Y'  ");
		mvwprintw(win, i * HEART_HEIGHT + 4, 0,  "    `Y'    ");
		i++;
	}
	wattroff(win, COLOR_PAIR(1));
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
