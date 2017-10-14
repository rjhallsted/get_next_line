/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/13 19:31:16 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

static void	buff_to_line(char **line, char *buff, size_t line_size, int start, int rv)
{
	*line = ft_realloc(*line, line_size);
	ft_strncat(*line, buff + start, rv);
}

int	get_next_line(const int fd, char **line)
{
	static int	last_pos;
	int			rv;
	int			read_line;
	size_t		line_size;
	static char	buff[BUFF_SIZE];

	line_size = 0;
	*line = NULL;
	printf("last_pos: %d\n", last_pos);
	if (last_pos && last_pos != BUFF_SIZE - 1)
		buff_to_line(line, buff, BUFF_SIZE - last_pos, last_pos, BUFF_SIZE - last_pos);
	rv = 1;
	read_line = 0;
	while (rv != 0 && !read_line)
	{
		rv = read(fd, buff, BUFF_SIZE);
		if ((rv = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		last_pos = 0;
		while (last_pos < BUFF_SIZE && buff[last_pos] != '\n')
			last_pos++;
		if (buff[last_pos] == '\n' || rv == 0)
			read_line = 1;
		line_size += last_pos;
		buff_to_line(line, buff, line_size, 0, rv);
		printf("Line is: %s\n", *line);
	}
	return ((read_line) ? !(rv == 0) : -1);
}
