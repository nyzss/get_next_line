/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 08:57:53 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_read(int fd, char *old_string)
{
	char	*new_str;
	int		b_read;

	b_read = 1;
	if (!old_string)
		old_string = (char *)ft_calloc(1, 1);
	new_str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new_str || !old_string)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, new_str, BUFFER_SIZE);
		if (b_read < 0 && get_nl(old_string, new_str, 1) == -1)
			return (NULL);
		new_str[b_read] = '\0';
		old_string = ft_strjoin(old_string, new_str);
		if (!old_string)
			return (NULL);
		if (get_nl(old_string, NULL, 0))
			break ;
	}
	free(new_str);
	return (old_string);
}

char	*free_prev(char *buffer)
{
	char	*new_buf;
	int		i;
	int		len;
	int		start;

	if (!buffer)
		return (NULL);
	i = 0;
	start = get_nl(buffer, NULL, 0);
	if (start == 0)
		start = ft_strlen(buffer);
	len = ft_strlen(&buffer[start]);
	new_buf = (char *)ft_calloc(sizeof(char), len + 1);
	if (!new_buf)
		return (NULL);
	while (i < len)
	{
		new_buf[i] = buffer[start + i];
		i++;
	}
	free(buffer);
	new_buf[i] = '\0';
	return (new_buf);
}

static char	**get_buffer(void)
{
	static char	*buffer;

	return (&buffer);
}

void	destroy_buffer(void)
{
	char	**buffer;

	buffer = get_buffer();
	if (*buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	char	*next_line;
	char	**old_string;
	int		nl_index;

	old_string = get_buffer();
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	*old_string = handle_read(fd, *old_string);
	if (!*old_string || ft_strlen(*old_string) == 0)
		return (NULL);
	nl_index = get_nl(*old_string, NULL, 0);
	if (nl_index == 0)
		nl_index = ft_strlen(*old_string);
	next_line = ft_substr(*old_string, 0, nl_index);
	*old_string = free_prev(*old_string);
	if (!next_line)
		return (NULL);
	return (next_line);
}
