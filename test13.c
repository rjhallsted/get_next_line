/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 00:55:14 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/20 01:00:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char 	*line;
	int		fd;
	int		ret;

	fd = open("13.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s-->%d\n", line, (strcmp(line, "abcd") == 0));
	get_next_line(fd, &line);
	printf("%s-->%d\n", line, (strcmp(line, "efgh") == 0));
	ret = get_next_line(fd, &line);
	printf("%d\n", ret == 0);
	return (0);
}
