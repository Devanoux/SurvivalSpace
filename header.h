#ifndef HEADER_H
# define HEADER_H

//CONTINUE THE GAME OVER SCREEN MUST RETURN A ERROR AND ALSO BREAK THE WHILE (1)

# include <ncurses.h>
# include <stdlib.h>
# include <limits.h>

# include "contants.h"

extern int	GAME_WIDTH;
extern int	GAME_HEIGHT;

typedef struct	s_asteroid
{
	bool	alive;
	int		cooldown;
	int 	x;
	int 	y;
}	t_asteroid;

typedef struct	s_player
{
	int	x;
	int	y;
	int life;
}	t_player;

typedef	int** t_map;

typedef struct	s_game
{
	int			state;
	t_map		map;
	t_asteroid	*asteroid_list;
	t_player	*player;
}	t_game;

//game.c
void	update_game(t_game *game);

//init.c
t_game	*init_game(void);
void	init_scr(void);

//player.c
void	check_collision(t_asteroid *asteroid_list, t_player *player);

//asteroid.c
void	spawn_asteroid(t_map map, t_asteroid *asteroid_list);
void	update_asteroids(t_asteroid *asteroid_list);

//utils.c
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

//map.c
void	update_map(t_game *game);
void	display_map(t_map map);


















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