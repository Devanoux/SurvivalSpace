/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:28:21 by dernst            #+#    #+#             */
/*   Updated: 2024/11/24 00:03:38 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// MUST CHECK Collision to asteroid or ennemy / bullet set all in the defintiion
// function but if we want just verify only one set other to NULL
void	check_collision(t_asteroid *asteroid_list, t_player *player)
{
	int	i;

	i = 0;
	while (i < MAX_ASTEROIDS)
	{
		if (asteroid_list[i].x == player->x && asteroid_list[i].y == player->y)
		{
			asteroid_list[i].alive = FALSE;
			player->life--;
		}
		i++;
	}
}

void	piou_piou(t_game *game)
{
	int	i;

	i = 0;
	while (i < 500)
	{
		if (game->player->missiles[i].alive == FALSE)
		{
			game->player->missiles[i].alive = TRUE;
			game->player->missiles[i].x = game->player->x;
			game->player->missiles[i].y = (game->player->y) - 1;
			break;
		}
			i++;
	}
}

int	player_mouvement(t_game *game, int input)
{

	//adding WSAD
	if (input == KEY_UP)
		game->player->y -= game->player->y < GAME_HEIGHT - 1;
	else if (input == KEY_DOWN)
		game->player->y += game->player->y > 0;
	else if (input == KEY_LEFT)
		game->player->x -= game->player->x > 0;
	else if (input == KEY_RIGHT)
		game->player->x += game->player->x < GAME_WIDTH - 1;
	if (input == 'w')
		game->player->y -= game->player->y < GAME_HEIGHT - 1;
	else if (input == 's')
		game->player->y += game->player->y > 0;
	else if (input == 'a')
		game->player->x -= game->player->x > 0;
	else if (input == 'd')
		game->player->x += game->player->x < GAME_WIDTH - 1;
	else if (input == 'o')
		piou_piou(game);
	else if (input == KEY_BACKSPACE)
		return (-1);
	return (0);	
} 


//void	move_player_bullet(t_game *game)
//{
	
//}




































































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
