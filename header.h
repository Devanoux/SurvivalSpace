#ifndef HEADER_H
# define HEADER_H

//CONTINUE THE GAME OVER SCREEN MUST RETURN A ERROR AND ALSO BREAK THE WHILE (1)

# include <ncurses.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_asteroid
{
	int x;
	int y;
}	t_asteroid;

typedef struct s_player
{
	int	x;
	int	y;
	int life;
}	t_player;

//game.c
void	game_over();

//player.c
void	spawn_player(int **map, t_player *player);
void	check_collision(t_asteroid *list_asteroid, t_player *player);

//asteroid.c
void	spawn_asteroid(int **map, t_asteroid *list_asteroid);
void	move_asteroid(t_asteroid *list_asteroid);

//utils.c
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

//map.c

	// NULL = 0
	// ASTEROID = 1
	// PLAYER = 2
	// ENNEMY = 3

void	display_map(int **map);
void	destroy_entities(t_asteroid *asteroid, int i);
void	update_map(int **map, t_asteroid *list_asteroid, t_player *player);

















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