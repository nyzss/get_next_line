/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:41 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 14:44:02 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
// 42
// 10000000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *buf, char *tmp);

void	*ft_calloc(size_t n, size_t size);

void	remove_prev_line(char *buffer);

int		get_nl(char *buf);

char	*ft_strdup(char *str);

#endif
