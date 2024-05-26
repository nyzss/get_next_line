/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:13:24 by okoca             #+#    #+#             */
/*   Updated: 2024/05/26 16:15:48 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include "stdio.h"

// printf("\nline: %s\n", get_next_line(fd));
// printf("\nline: %s\n", get_next_line(fd));
// printf("\nline: %s\n", get_next_line(fd));
int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
}
