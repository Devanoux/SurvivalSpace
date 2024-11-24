/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:14:05 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 09:15:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

void	display_map(t_game *game)
{
	WINDOW *win = newwin(MAP_HEIGHT + 2, MAP_WIDTH + 2, (game->height / 2) - (MAP_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2));
	int	i;

	box(win, 0, 0);
	wrefresh(win);
	i = 0;
	while (i < MAP_HEIGHT)
	{
		mvwaddnstr(win, i + 1, 1, game->map[i], MAP_WIDTH);
		i++;
	}
	wrefresh(win);
}

void	display_statistics(t_game *game)
{
	WINDOW *win = newwin(STAT_HEIGHT + 2, STAT_WIDTH + 2, (game->height / 2) - (STAT_HEIGHT / 2), (game->width / 2) - (MAP_WIDTH / 2) - STAT_MARGIN - (STAT_WIDTH + 2));

	box(win, 0, 0);
	mvwaddnstr(win, 1, max(((STAT_WIDTH + 2) / 2) - (strlen(game->user->username) / 2), 1), game->user->username, min(strlen(game->user->username), STAT_WIDTH)); // (STAT_WIDTH / 2) - 3 is to center the string "PLAYER"
	mvwprintw(win, 3, STAT_PADDING + 1, "Score : %d", game->user->score);
	wrefresh(win);
}

void	display_health(t_game *game)
{
	WINDOW *win = newwin(HEART_HEIGHT * game->player->life, HEALTH_WIDTH, (game->height / 2) - ((HEART_HEIGHT * game->player->life) / 2), (game->width / 2) + ((MAP_WIDTH + 2) / 2) + HEALTH_MARGIN);
	int	i;

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
	wrefresh(win);
}

void	display_game(t_game *game)
{
	clear();
	if (STAT_WIDTH < (game->width / 2) - (MAP_WIDTH / 2) - 2 - (STAT_MARGIN * 2))
	{
		display_statistics(game);
		display_health(game);
	}
	display_map(game);
}
