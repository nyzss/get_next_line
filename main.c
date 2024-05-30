/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:10:03 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 13:35:18 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void	call(char *buf, int fd)
{
	buf = get_next_line(fd);
	printf("line: %s", buf);
	free(buf);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*buf;
	char	*file_name = "text.txt";

	if (argc == 2)
		file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	buf = NULL;

	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	call(buf, fd);
	close(fd);
}
