/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:48:29 by okoca             #+#    #+#             */
/*   Updated: 2024/05/31 21:09:29 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*move_buf_nl(char *buffer, char **next_line);

void	*ft_calloc(size_t n, size_t size);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *old, char *tmp);

char	*ft_substr(char *s, unsigned int start, size_t len);

void	remove_beginning(char *buffer);

int		get_nl(char *buf);

#endif
