/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:28:21 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 08:54:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// MUST CHECK Collision to asteroid or ennemy / bullet set all in the defintiion
// function but if we want just verify only one set other to NULL
void	check_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (game->asteroid_list[i].x == game->player->x && game->asteroid_list[i].y == game->player->y && game->asteroid_list[i].alive)
		{
			game->asteroid_list[i].alive = FALSE;
			game->player->life--;
			game->user->score -= 1000;
		}
		i++;
	}
}

void	check_life(t_game *game)
{
	if (game->player->life == 0)
		game->state = GAME_OVER;
}

void	piou_piou(t_player *player)
{
	int	i;

	i = 0;
	if (!player->cooldown)
	{
		while (i < 500)
		{
			if (player->missiles[i].alive == FALSE)
			{
				player->missiles[i].alive = TRUE;
				player->missiles[i].x = player->x;
				player->missiles[i].y = player->y - 1;
				break ;
			}
				i++;
		}
		player->cooldown = PLAYER_COOLDOWN;
	}
}

void	move_missile(t_missile *missiles)
{
	int i;

	i = 0;
	while(i < 500)
	{
		if (!missiles[i].cooldown)
		{
			if (missiles[i].y > 0)
			{
				missiles[i].y--;
				missiles[i].cooldown = MISSILE_SPEED;
			}
			else
				missiles[i].alive = FALSE;
		}
		else
			missiles[i].cooldown--;
		i++;
	}
}

int	move_player(t_player *player, int input)
{
	switch (input)
	{
	case KEY_UP:
		player->y -= player->y > 0;
		break ;
	case KEY_DOWN:
		player->y += player->y < MAP_HEIGHT - 1;
		break ;
	case KEY_LEFT:
		player->x -= player->x > 0;
		break ;
	case KEY_RIGHT:
		player->x += player->x < MAP_WIDTH - 1;
		break ;
	case 'w':
		player->y -= player->y > 0;
		break ;
	case 's':
		player->y += player->y < MAP_HEIGHT - 1;
		break ;
	case 'a':
		player->x -= player->x > 0;
		break ;
	case 'd':
		player->x += player->x < MAP_HEIGHT - 1;
		break ;
	case ' ':
		piou_piou(player);
		break ;
	case KEY_BACKSPACE:
		return (-1);
		break ;
	default:
		break;
	}
	return (0);
}

int	update_player(t_player *player, int input)
{
	if (player->cooldown)
		player->cooldown--;
	return (move_player(player, input));
}
