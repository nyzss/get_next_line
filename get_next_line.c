/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 19:00:57y okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*handle_next_line_old(int fd, char *buf, int *start)
// {
// 	char	*result;

// 	if (*start == 0)
// 	{
// 		if (!read(fd, buf, BUFFER_SIZE))
// 			return (NULL);
// 	}
// 	result = ft_substr(buf, *start, get_nl(buf));
// 	*start += get_nl(buf) + 1;
// 	return (result);
// }


// tmp = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
int	handle_read_fail(char* tmp, int b_read)
{
	if (b_read < 0)
	{
		free(tmp);
		return (1);
	}
	return (0);
}

char	*handle_read(int fd, char *buf)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	if (!buf)
	{
		buf = (char *)malloc(1);
		buf[0] = 0;
	}
	while (b_read > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return (NULL);
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (handle_read_fail(tmp, b_read))
			return (NULL);
		tmp[b_read] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (NULL);
		if (get_nl(buf))
			break ;
	}
	return (buf);
}

char	*handle_next_line(char *buf, int *start)
{
	char	*nl;
	int		nl_index;

	nl_index = get_nl(&buf[*start]);
	nl = ft_substr(buf, *start, nl_index);
	if (!nl)
		return (NULL);
	*start += nl_index;
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*next_line;
	static int	start;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = handle_read(fd, buf);
	if (!buf || ft_strlen(buf) == 0)
		return (NULL);
	next_line = handle_next_line(buf, &start);
	if (!next_line)
		return (NULL);
	return (next_line);
}
