/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/27 16:02:52 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	handle_read_fail(char *old_string, char *new_str, int b_read)
{
	if (b_read < 0 && old_string && new_str)
	{
		free(new_str);
		free(old_string);
		return (1);
	}
	return (0);
}

char	*handle_read(int fd, char *old_string, int start)
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
		if (handle_read_fail(old_string, new_str, b_read))
			return (NULL);
		new_str[b_read] = '\0';
		old_string = ft_strjoin(old_string, new_str);
		if (!old_string)
			return (NULL);
		if (get_nl(&old_string[start]))
			break ;
	}
	free(new_str);
	return (old_string);
}

char	*handle_next_line(char *old_string, int *start)
{
	char	*nl;
	int		nl_index;

	nl_index = get_nl(&old_string[*start]);
	nl = ft_substr(old_string, *start, nl_index);
	if (!nl || (*start + nl_index == *start))
	{
		return (NULL);
	}
	*start += nl_index;
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*old_string;
	static char	*next_line;
	static int	start;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_string = handle_read(fd, old_string, start);
	if (!old_string || ft_strlen(old_string) == 0)
		return (NULL);
	if (next_line)
		free(next_line);
	next_line = handle_next_line(old_string, &start);
	if (!next_line)
		return (NULL);
	return (next_line);
}
