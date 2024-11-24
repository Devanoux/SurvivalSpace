/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:58:26 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 15:52:57 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// MAX VALUES

# define MAX_PLAYER_MISSILE 100
# define MAX_ASTEROIDS 42
# define MAX_ENEMY 69

// SPEED VALUES

# define ASTEROID_SPEED 20
# define MISSILE_SPEED 5
# define ENEMY_SPEED 20

// MAP VALUES

# define MAP_WIDTH 60
# define MAP_HEIGHT 40

# define VOID ' '
# define ASTEROID '#'
# define PLAYER 'A'
# define ENEMY 'T'
# define PLAYER_MISSILE '\''
# define ENEMY_MISSILE '*'

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

// DIFFICULTY CONFIG
# define PLAYER_COOLDOWN 20
# define FPS 60;
# define ASTEROID_SPAWN_RATE 1 // divided by 1000
# define ENEMY_SPAWN_RATE 1 // same

#endif