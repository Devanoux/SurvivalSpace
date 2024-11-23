/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:15:49 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 17:26:36 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	game_over()
{
	clear();
	printw("Game Over");
	refresh();
	return (1);
}

void	launch(int **map, t_asteroid *list_asteroid, t_player *player)
{
	while (1)
	{
		// Here adding all change in the map asteroids / ennemys / player / bullet
		// Update map get all this info and modify the map to get a new
		update_map(map, list_asteroid, player);
		// display the map with news
		display_map(map);
	}
}

void	setup()
{
	int **map;
	int i;
	t_player player;
	t_asteroid *list_asteroid;
	size_t max_asteroid;

	i = 0;
	max_asteroid = 42;
	map = ft_calloc(LINES, sizeof(int *));
	while (i < LINES)
	{
		map[i] = ft_calloc(COLS, sizeof(int));
		i++;
	}
	
	list_asteroid = malloc(max_asteroid * sizeof(t_asteroid));
	spawn_player(map, &player);
	spawn_asteroid(map, list_asteroid);
	display_map(map);
	launch(map, list_asteroid, &player);
}

int	main(void)
{
	initscr();
	setup();
	getch();
	endwin();
	return 0;
}