#ifndef HEADER_H
# define HEADER_H

//CONTINUE THE GAME OVER SCREEN MUST RETURN A ERROR AND ALSO BREAK THE WHILE (1)

# include <ncurses.h>
# include <stdlib.h>
# include <limits.h>

# include "contants.h"

typedef struct	s_asteroid
{
	bool	alive;
	int		cooldown;
	int 	x;
	int 	y;
}	t_asteroid;

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

//asteroid.c
void	update_asteroids(t_asteroid *asteroid_list);

//utils.c
void	for_each(void *array, size_t n, size_t (*f)(void *));
int		min(int a, int b);
int		max(int a, int b);

//map.c
void	update_map(t_game *game);

//time.c
void	wait_for_frame(void);

//display.c
void	display_game(t_game *game);

//screen.c
void	handle_resize(t_game *game);




//typedef struct	s_enemy 
//{
//	int		type;
//	char	skin;
//	int		health;
//	char	*pattern;
//	int		pattern_state;
//}		t_enemy;

//typedef struct	s_entity 
//{
//	int		type;
//	int		x;
//	int		y;
//	void	*value;

//}		t_entity;

//typedef struct	s_map 
//{
//	int			width;
//	int			height;
//	t_entity	**content;
//}		t_map;

//typedef struct s_player
//{
//	int	health;
//	int	x;
//	int	y;
//}		t_player;


//typedef struct s_game
//{
//	t_map		*map;
//	t_player	*player;
//}		t_game;

#endif