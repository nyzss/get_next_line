/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:20:42 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 14:45:58 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read(int fd, char *buffer, char *next_line)
{
	int		b_read;

	b_read = 1;
	next_line = ft_strjoin(next_line, buffer);
	if (!next_line)
		return (NULL);
	while (b_read > 0 && !get_nl(next_line))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		if (next_line && get_nl(next_line) == 0 && b_read == 0)
			break ;
		next_line = ft_strjoin(next_line, buffer);
		if (!next_line)
			return (NULL);
		if (get_nl(next_line))
			break ;
	}
	return (next_line);
}

char	*insert_left(char *buffer)
{
	int		i;
	int		len;
	int		next_ln;
	char	*new_str;

	i = 0;
	next_ln = get_nl(buffer);
	if (next_ln == 0)
		len = ft_strlen(buffer);
	else
		len = next_ln;
	new_str = ft_calloc(sizeof(char), len + 1);
	while (i < len)
	{
		new_str[i] = buffer[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	remove_prev_line(char *buffer)
{
	int		i;
	int		len;
	int		next_nl;

	i = 0;
	next_nl = get_nl(buffer);
	if (next_nl == 0)
		len = ft_strlen(buffer);
	else
		len = next_nl;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = buffer[i + len];
		i++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = handle_read(fd, buffer, next_line);
	if (ft_strlen(next_line) == 0)
	{
		free(next_line);
		next_line = NULL;
	}
	remove_prev_line(buffer);
	return (next_line);
}
