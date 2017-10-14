/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/14 14:13:56 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

static void	buff_to_line(char **line, char *buff, size_t line_size, int copy_size)
{
	*line = ft_realloc(*line, line_size);
	ft_strncat(*line, buff, copy_size);
	ft_bzero(buff, BUFF_SIZE);
}

int	get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		rv;	
	int		line_length;
	char	*char_pos;

	line_length = 0;
	rv = 1;
	if (line)
		ft_strclr(*line);
	ft_bzero(buff, BUFF_SIZE);
	while (rv)
	{
		if ((rv = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rv == 0)
			return (0);
		buff[BUFF_SIZE] = '\0';
		char_pos = ft_strchr(buff, '\n');
		if (char_pos)
		{
			line_length += char_pos - buff;
			buff_to_line(line, buff, line_length, char_pos - buff);
			return (1);
		}
		else
		{
			line_length += rv;
			buff_to_line(line, buff, line_length, rv);
		}
	}
	return (-1);
}
