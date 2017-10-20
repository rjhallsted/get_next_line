/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 00:55:14 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/20 01:35:22 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	char 	*line;
	int		fd;
	int		ret;

	fd = 0;
	write(fd, "abcd\n", 5);
	write(fd, "efgh\n", 5);
	close(fd);
	get_next_line(fd, &line);
	printf("%s-->%d\n", line, (strcmp(line, "abcd") == 0));
	get_next_line(fd, &line);
	printf("%s-->%d\n", line, (strcmp(line, "efgh") == 0));
	ret = get_next_line(fd, &line);
	printf("%d\n", ret == 0);
	return (0);
}
