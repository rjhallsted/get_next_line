/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:51:48 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/18 23:19:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		i = 0;
		while (get_next_line(fd, &line) > 0)
		{
			printf("Line %d: ", ++i);
			printf("%s\n", line);
		}
		free(line);
	}
	return (1);
}
