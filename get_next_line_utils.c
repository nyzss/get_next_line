/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:46 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 13:27:25 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	void			*allocated;
	size_t			i;
	unsigned char	*location;

	i = 0;
	if (n == 0 || size == 0)
	{
		allocated = malloc(0);
		if (!allocated)
			return (NULL);
		return (allocated);
	}
	else if (n * size < size || n * size < n)
		return (NULL);
	allocated = (void *)malloc(n * size);
	if (!allocated)
		return (NULL);
	location = (unsigned char *)allocated;
	while (i < (n * size))
	{
		location[i] = 0;
		i++;
	}
	return (allocated);
}

char	*ft_strjoin(char *old, char *tmp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(sizeof(char), (ft_strlen(old) + ft_strlen(tmp) + 1));
	if (!new)
		return (NULL);
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	while (tmp && tmp[j])
	{
		new[i + j] = tmp[j];
		j++;
		if (new[i + (j - 1)] == '\n')
			break ;
	}
	new[i + j] = '\0';
	if (old)
		free(old);
	return (new);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
