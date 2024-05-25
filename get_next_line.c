/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 17:05:42 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_next_line(int fd, char *buf, int *start)
{
	char	*result;

	printf("start: %d\n", *start);
	if (*start == 0)
	{
		if (!read(fd, buf, BUFFER_SIZE))
			return (NULL);
	}
	result = ft_substr(buf, *start, get_nl(buf));
	*start += get_nl(buf) + 1;
	return (result);
}


char	*get_next_line(int fd)
{
	static char	*buf;
	static int	start;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return (handle_next_line(fd, buf, &start));
}
