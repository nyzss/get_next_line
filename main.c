/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoca <okoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:13:24 by okoca             #+#    #+#             */
/*   Updated: 2024/05/27 15:04:25 by okoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include "string.h"

// printf("\nline: %s\n", get_next_line(fd));
// printf("\nline: %s\n", get_next_line(fd));
// printf("\nline: %s\n", get_next_line(fd));
int	main(int argc, char **argv)
{
	int	fd;
	char	*buf;
	char	*file_name = "text.txt";


	if (argc == 2)
		file_name = argv[1];
	fd = open(file_name, O_RDONLY);

	buf = get_next_line(fd);
	printf("line: %s", buf);

	buf = get_next_line(fd);
	printf("line: %s", buf);

	free(buf);
	close(fd);
}
