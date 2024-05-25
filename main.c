/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:13:24 by okoca             #+#    #+#             */
/*   Updated: 2024/05/25 19:27:04 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include "stdio.h"

int main()
{
	int	fd = open("t.txt", O_RDONLY);

	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	// printf("\nline: %s\n", get_next_line(fd));
	// printf("\nline: %s\n", get_next_line(fd));
	// printf("\nline: %s\n", get_next_line(fd));
}
