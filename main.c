/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 08:56:35 by okoca             #+#    #+#             */
/*   Updated: 2024/05/30 08:56:47 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

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
	printf("line: %s", buf);
	free(buf);
	close(fd);
}
