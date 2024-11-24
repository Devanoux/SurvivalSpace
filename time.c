/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:00:12 by ebini             #+#    #+#             */
/*   Updated: 2024/11/24 23:16:17 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

void    wait_for_frame(const struct timespec *start, int frame_duration_ms) {
	struct timespec	end;
	struct timespec	sleep_time;
	long elapsed_ms;

	clock_gettime(CLOCK_MONOTONIC, &end);
	elapsed_ms = (end.tv_sec - start->tv_sec) * 1000 + (end.tv_nsec - start->tv_nsec) / 1000000;
	if (elapsed_ms < frame_duration_ms) {
		sleep_time.tv_sec = 0;
		sleep_time.tv_nsec = (frame_duration_ms - elapsed_ms) * 1000000;
		nanosleep(&sleep_time, NULL);
	}
}
