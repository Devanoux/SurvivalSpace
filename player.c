/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:28:21 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 23:14:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "header.h"

void	check_collision(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAX_ENEMY)
	{
		while(j < MAX_PLAYER_MISSILE)
		{
			if (game->enemy_list[i].alive && game->player->missiles[j].alive && game->player->missiles[j].x == game->enemy_list[i].x && game->player->missiles[j].y == game->enemy_list[i].y)
			{
				game->enemy_list[i].alive = FALSE;
				game->player->missiles[j].alive = FALSE;
				game->user->score += 100;
			}
			if (game->enemy_list[i].alive && game->enemy_list[i].x == game->player->x && game->enemy_list[i].y ==  game->player->y)
			{
				game->enemy_list[i].alive = FALSE;
				game->player->life--;
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < MAX_ENEMY_MISSILE)
	{
		if (game->missiles[i].alive && game->player->x == game->missiles[i].x && game->player->y == game->missiles[i].y)
		{
			game->player->life--;
			game->missiles[i].alive = FALSE;
		}		
		i++;
	}
	
	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (game->asteroid_list[i].x == game->player->x && game->asteroid_list[i].y == game->player->y && game->asteroid_list[i].alive)
		{
			game->asteroid_list[i].alive = FALSE;
			game->player->life--;
			game->user->score -= 500;
		}
		i++;
	}
}

void	check_life(t_game *game)
{
	if (game->player->life <= 0)
	{
		game->state = GAME_OVER;
		game->user->end_time = time(NULL);
	}
}

void	piou_piou_player(t_player *player)
{
	int	i;

	i = 0;
	if (!player->cooldown && player->y > 0)
	{
		while (i < MAX_PLAYER_MISSILE)
		{
			if (player->missiles[i].alive == FALSE)
			{
				player->missiles[i].alive = TRUE;
				player->missiles[i].x = player->x;
				player->missiles[i].y = player->y - 1;
				player->missiles[i].cooldown = MISSILE_SPEED;
				break ;
			}
				i++;
		}
		player->cooldown = PLAYER_COOLDOWN;
	}
}

void	move_missile_player(t_missile *missiles)
{
	int i;

	i = 0;
	while(i < MAX_PLAYER_MISSILE)
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
		piou_piou_player(player);
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
