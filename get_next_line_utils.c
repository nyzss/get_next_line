/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:46 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 12:46:49 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start >= i)
		len = 0;
	else if (start + len >= i)
		len = i - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (len && s[start + i] && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	get_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (i);
}

char	*handle_next_line(int fd)
{
	static char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	return (ft_substr(buf, 0, get_nl(buf)));
}
