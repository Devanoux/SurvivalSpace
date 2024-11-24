/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:00:12 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 02:07:36 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "header.h"

void	wait_for_frame(void)
{
	struct timespec req, rem;
	req.tv_sec = 0;
	req.tv_nsec =  1000000000 / FPS;
	nanosleep(&req, &rem);
}
