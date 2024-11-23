/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:10:46 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 17:10:15 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spawn_asteroid(int **map, t_asteroid *list_asteroid)
{
	size_t	nb_asteroid;
	size_t	random_x;
	size_t	random_y;
	size_t	max_asteroid;
	
	max_asteroid = 42;
	nb_asteroid = 0;
	
// Add a condition before to add an asteroid if this case is free also add it else random again

// Two case firts at launch when asteroid can spaw where he want and the seconde case when asteroid
// respawn after been deleted also it must spawn in the top but anywhere he want in y

	while (nb_asteroid < max_asteroid)
	{
		random_y = rand()%COLS;
		random_x = rand()%LINES;
		list_asteroid[nb_asteroid].x = random_x;
		list_asteroid[nb_asteroid].y = random_y;
		map[random_x][random_y] = 1;
		nb_asteroid++;
	}
}

void	move_asteroid(t_asteroid *list_asteroid)
{
	size_t i;

	i = 0;
	while (i < 42)
	{

		// Lines is not defined 
		if (list_asteroid[i].x < LINES - 1)
			list_asteroid[i].x++;
		else
		{
			destroy_entities(list_asteroid, i);
		}
		i++;
	}
}