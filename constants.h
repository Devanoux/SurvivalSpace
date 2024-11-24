/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:58:26 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 22:39:07 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// MAX VALUES

# define MAX_PLAYER_MISSILE 100
# define MAX_ENEMY_MISSILE 500
# define MAX_ASTEROIDS 42
# define MAX_ENEMY 69

// SPEED VALUES

# define ASTEROID_SPEED 20
# define MISSILE_SPEED 15
# define ENEMY_SPEED 40

// MAP VALUES

# define MAP_WIDTH 60
# define MAP_HEIGHT 40

# define VOID ' '
# define ASTEROID '#'			// LIGHT GRAY
# define PLAYER 'A' 			// YELLOW
# define ENEMY 'T'				// RED
# define PLAYER_MISSILE '\''	// WHITE
# define ENEMY_MISSILE '*'		// ORANGE

// GAME STATES

# define ERROR -1
# define END 0
# define MENU 1
# define PLAY 2
# define GAME_OVER 3

// STATS CONFIGS

# define STAT_WIDTH 18
# define STAT_HEIGHT 3
# define STAT_MARGIN 3
# define STAT_PADDING 1

// HEALTH CONFIGS

# define HEALTH_WIDTH 11
# define HEALTH_MARGIN 3
# define HEALTH_PADDING 1
# define HEART_HEIGHT 7

// GAMEOVER CONFIGS

# define GAME_OVER_IMAGE_WIDTH 42
# define GAME_OVER_IMAGE_HEIGHT 21

// DIFFICULTY CONFIG
# define PLAYER_COOLDOWN 5
# define ENEMY_COOLDOWN 100
# define FPS 60
# define ASTEROID_SPAWN_RATE 1 // divided by 1000
# define ENEMY_SPAWN_RATE 1 // same

#endif