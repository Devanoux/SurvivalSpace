/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:05:48 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 13:13:22 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_game(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->map)
		{
			i = 0;
			while (i < MAP_HEIGHT)
				free(game->map[i++]);
			free(game->map);
		}
		if (game->asteroid_list)
			free(game->asteroid_list);
		if (game->player)
		{
			free(game->player->missiles);
			free(game->player);
		}
		if (game->user)
			free(game->user);
		free(game);
	}
}