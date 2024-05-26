/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/26 16:26:42 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	handle_read_fail(char *buf, char *tmp, int b_read)
{
	if (b_read < 0)
	{
		free(tmp);
		free(buf);
		return (1);
	}
	return (0);
}

char	*handle_read(int fd, char *buf, int start)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	if (!buf)
		buf = (char *)calloc(1, 1);
	tmp = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmp || !buf)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (handle_read_fail(buf, tmp, b_read))
			return (NULL);
		tmp[b_read] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (NULL);
		if (get_nl(&buf[start]))
			break ;
	}
	free(tmp);
	return (buf);
}

char	*handle_next_line(char *buf, int *start)
{
	char	*nl;
	int		nl_index;

	nl_index = get_nl(&buf[*start]);
	nl = ft_substr(buf, *start, nl_index);
	if (!nl || (*start + nl_index == *start))
	{
		return (NULL);
	}
	*start += nl_index;
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static char	*next_line;
	static int	start;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = handle_read(fd, buf, start);
	if (!buf || ft_strlen(buf) == 0)
		return (NULL);
	if (next_line)
		free(next_line);
	next_line = handle_next_line(buf, &start);
	if (!next_line)
		return (NULL);
	return (next_line);
}
