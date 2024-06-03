/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:46:17 by okoca             #+#    #+#             */
/*   Updated: 2024/06/03 09:20:18 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read_handle(char *next_line)
{
	if (get_nl(next_line))
		next_line = ft_substr(next_line, 0, get_nl(next_line));
	else if (!ft_strlen(next_line))
	{
		if (next_line)
			free(next_line);
		return (NULL);
	}
	return (next_line);
}

char	*handle_read(int fd, char *buffer, char *next_line)
{
	int		b_read;

	b_read = 1;
	while (b_read > 0 && !get_nl(next_line))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		if (b_read < 0)
		{
			free(next_line);
			return (NULL);
		}
		next_line = ft_strjoin(next_line, buffer);
		if (!next_line || ft_strlen(next_line) == 0)
		{
			if (next_line)
				free(next_line);
			return (NULL);
		}
	}
	return (handle_read_handle(next_line));
}

void	remove_begin(char *buffer)
{
	int		i;
	int		first_nl;

	i = 0;
	first_nl = get_nl(buffer);
	while (i + first_nl < (int)ft_strlen(buffer))
	{
		buffer[i] = buffer[i + first_nl];
		i++;
	}
	buffer[i] = '\0';
}

char	*move_buf_nl(char *buffer, char **next_line)
{
	int		i;

	i = 0;
	*next_line = ft_calloc(sizeof(char), ft_strlen(buffer) + 1);
	while (i < (int)ft_strlen(buffer))
	{
		(*next_line)[i] = buffer[i];
		i++;
	}
	(*next_line)[i] = '\0';
	return (*next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	next_line = move_buf_nl(buffer[fd], &next_line);
	next_line = handle_read(fd, buffer[fd], next_line);
	if (!next_line)
	{
		while (i < BUFFER_SIZE)
		{
			buffer[fd][i] = '\0';
			i++;
		}
		buffer[fd][i] = '\0';
		return (NULL);
	}
	remove_begin(buffer[fd]);
	return (next_line);
}

// sa rentre dans le function handle_read meme si c'est deja a la fin