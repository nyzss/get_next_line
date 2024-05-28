/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:16:07 by okoca             #+#    #+#             */
/*   Updated: 2024/05/28 11:55:42 by okoca            ###   ########.fr       */
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
		if (handle_read_fail(old_string, new_str, b_read))
			return (NULL);
		new_str[b_read] = '\0';
		old_string = ft_strjoin(old_string, new_str);
		if (!old_string)
			return (NULL);
		if (get_nl(old_string))
			break ;
	}
	free(new_str);
	return (old_string);
}

char	*handle_next_line(char *old_string)
{
	char	*nl;
	int		nl_index;

	nl_index = get_nl(old_string);
	if (nl_index == 0)
		nl_index = ft_strlen(old_string);
	nl = ft_substr(old_string, 0, nl_index);
	if (!nl)
		return (NULL);
	return (nl);
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
	start = get_nl(buffer);
	if (start == 0)
		start = ft_strlen(buffer);
	len = ft_strlen(&buffer[start]);
	new_buf = (char *)calloc(sizeof(char), len + 1);
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

char	*get_next_line(int fd)
{
	static char	*old_string;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_string = handle_read(fd, old_string);
	if (!old_string || ft_strlen(old_string) == 0)
		return (NULL);
	next_line = handle_next_line(old_string);
	old_string = free_prev(old_string);
	return (next_line);
}

// #include "fcntl.h"
// #include "string.h"

// // printf("\nline: %s\n", get_next_line(fd));
// int	main(int argc, char **argv)
// {
// 	int	fd;
// 	char	*buf;
// 	char	*file_name = "text.txt";

// 	if (argc == 2)
// 		file_name = argv[1];
// 	fd = open(file_name, O_RDONLY);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	buf = get_next_line(fd);
// 	printf("line: %s", buf);
// 	free(buf);

// 	close(fd);
// }
