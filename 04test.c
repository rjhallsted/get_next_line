/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 12:33:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/21 12:39:54 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	int		p[2];
	int		out;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	i = 0;
	get_next_line(fd, &line);
	printf("Line %d: ", ++i);
	printf("%s", line);
	printf("-->%d\n", strcmp(line, "abc") == 0);
	free(line);
	return (1);
}
