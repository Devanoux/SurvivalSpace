/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:11:37 by dernst            #+#    #+#             */
/*   Updated: 2024/11/23 16:12:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

	if (nmemb != 0)
	{
		if (nmemb / (INT_MAX) > size)
			return (NULL);
	}
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (buffer);
	buffer = ft_memset(buffer, 0, size * nmemb);
	return (buffer);
}