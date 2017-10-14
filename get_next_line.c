/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/13 18:36:50 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int		index;
	int		rv;
	int		read_line;
	size_t	line_size;
	char	buff[BUFF_SIZE];

	line_size = 0;
	index = 0;
	*line = NULL;
	ft_bzero(buff, BUFF_SIZE);
	rv = 1;
	read_line = 0;
	while (rv != 0 && !read_line)
	{
		while (index < BUFF_SIZE && (rv = read(fd, buff + index, 1) > 0)
				&& buff[index] != '\n')
			index++;
		if (buff[index] == '\n' || rv == 0)
		{
			if (buff[index] == '\n')
				buff[index] = '\0';
			read_line = 1;
		}
		line_size += index;
		*line = ft_realloc(*line, line_size);
		ft_strncat(*line, buff,	MIN(index, BUFF_SIZE));
		ft_bzero(buff, BUFF_SIZE);
		index = 0;
	}
	return ((read_line) ? !(rv == 0) : -1);
}
