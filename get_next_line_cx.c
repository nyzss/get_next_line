/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:44 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 17:20:21 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	// printf("\n\niteration: %d\n\n, line: %s\n\n", iteration, line);
char	*get_next_line(int fd)
{
	char		buf[1];
	static char	*line;
	static int	iteration;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (iteration)
		free(line);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	iteration = 1;
	i = 0;
	buf[0] = 0;
	while (read(fd, buf, 1))
	{
		line[i] = buf[0];
		i++;
		if (buf[0] == '\n')
			break ;
	}
	return (line);
}
