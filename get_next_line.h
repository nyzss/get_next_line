/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:41 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 08:55:44 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*handle_read(int fd, char *old_string);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *buf, char *tmp);

void	*ft_calloc(size_t n, size_t size);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*free_prev(char *buffer);

int		get_nl(char *buf, char *tmp, int error);

void	destroy_buffer(void)
		__attribute__((destructor));

#endif
