/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:51:48 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/21 15:13:36 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd[argc];
	int		a;
	int		i;
	char	*line;

	if (argc > 1)
	{
		a = 0;
		while (a < argc)
		{
			if ((fd[a] = open(argv[a + 1], O_RDONLY)) == -1)
				return (0);
			i = 0;
			while (get_next_line(fd[a], &line) > 0)
			{
				printf("Line %d: ", ++i);
				printf("%s\n", line);
				free(line);
			}
			a++;
		}
		a --;
		while (a >= 0)
		{
			close(fd[a]);
			a--;
		}
	}
	return (1);
}
