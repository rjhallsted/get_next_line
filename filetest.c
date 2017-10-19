/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 23:26:16 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/18 23:30:20 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	if ((fd = open("simple1", O_RDONLY)) == -1)
		return (0);
	get_next_line(fd, &line);
	printf("%s : %d\n", line, strcmp(line, "aaa"));
	get_next_line(fd, &line);
	printf("%s : %d\n", line, strcmp(line, "bbb"));
	get_next_line(fd, &line);
	printf("%s : %d\n", line, strcmp(line, "ccc"));
	get_next_line(fd, &line);
	printf("%s : %d\n", line, strcmp(line, "ddd"));
	free(line);
	return (1);
}
