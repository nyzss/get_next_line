/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 18:24:00 by okoca            ###   ########.fr       */
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
char	*handle_read(int fd, char *buf)
{
	char	*tmp;
	int		b_read;

	b_read = 1;
	while (b_read > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return (NULL);
		b_read = read(fd, tmp, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[b_read] = '\0';
		buf = ft_strjoin(buf, tmp);
		free(tmp);
	}
	return (buf);
}

char	*handle_next_line(char *buf, int *start)
{
	char	*nl;
	int		nl_index;

	nl_index = get_nl(buf, *start);
	nl = ft_substr(buf, *start, nl_index);
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
	if (!buf)
		return (NULL);
	next_line = handle_next_line(buf, &start);
	return (next_line);
}
