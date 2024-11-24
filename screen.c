/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:02:29 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 04:55:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_resize(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->width = COLS;
	game->height = LINES;
	screen_width = max(game->width, MAP_WIDTH + 2);
	screen_height = max(game->height, MAP_HEIGHT + 2);
	resize_term(screen_height, screen_width);
}