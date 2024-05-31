/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:13:24 by okoca             #+#    #+#             */
/*   Updated: 2024/05/31 20:29:15 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include "string.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*buf;
	char	*file_name;

	file_name = "text.txt";
	if (argc == 2)
		file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	buf = get_next_line(fd);
	printf("\n####BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	while (buf)
	{
		if (buf[0] == '\n')
			printf("line: '$NEWLINE'\n\n");
		else
			printf("line: %s\n", buf);
		free(buf);
		buf = get_next_line(fd);
	}
	printf("line: %s\n", buf);
	close(fd);
}
