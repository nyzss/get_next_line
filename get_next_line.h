/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:41 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 20:41:36 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

//REMOVE
// # define BUFFER_SIZE 1000000
# include <stdio.h>
//REMOVE

char	*get_next_line(int fd);

char	*handle_read(int fd, char *buf);

char	*handle_next_line(char *buf, int *start);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *buf, char *tmp);

void	*ft_calloc(size_t n, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		get_nl(char *buf);

#endif
