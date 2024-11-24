#ifndef HEADER_H
# define HEADER_H

# include <ncurses.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>

# include "constants.h"

typedef struct	s_asteroid
{
	bool	alive;
	int		cooldown;
	int 	x;
	int 	y;
}	t_asteroid;

typedef struct	s_enemy
{
	bool	alive;
	int		cooldown;
	int		x;
	int		y;
	//void*	patern;
}	t_enemy;

//typedef struct s_pattern
//{
	
//}

typedef struct	s_missile
{
	bool	alive;
	int		cooldown;
	int		x;
	int		y;
}	t_missile;

typedef struct	s_player
{
	int			x;
	int			y;
	int			life;
	int			cooldown;
	t_missile	*missiles;
}	t_player;

typedef struct	s_user
{
	int		score;
	char	*username;
	time_t	start_time;
}	t_user;

typedef	char**	t_map;

typedef struct	s_game
{
	int			state;
	int			width;
	int			height;
	t_map		map;
	t_asteroid	*asteroid_list;
	t_player	*player;
	t_user		*user;
	t_enemy		*enemy_list;
}	t_game;

//game.c
void	update_game(t_game *game);

//init.c
t_game	*init_game(int ac, char **av);
void	init_scr(void);

//player.c
void	check_collision(t_game *game);
void	move_missile(t_missile *missiles);
int		update_player(t_player *player, int input);
void	check_life(t_game *game);

//enemy.c
void	update_enemy(t_game *game);

//asteroid.c
void	update_asteroids(t_asteroid *asteroid_list);

//utils.c
void	for_each(void *array, size_t n, size_t (*f)(void *));
int		min(int a, int b);
int		max(int a, int b);

//map.c
void	update_map(t_game *game);

//time.c
void	wait_for_frame(const struct timespec *start, int frame_duration_ms);

//display.c
void	display_game(t_game *game);

//screen.c
void	handle_resize(t_game *game);

//free.c
void	free_game(t_game *game);

#endif