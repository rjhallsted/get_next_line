/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/16 17:33:11 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

static void	shift_chars_left(char *buff, int shift_by)
{
	int i;

	i = 0;
	while (buff[i] && buff[i + shift_by])
	{
		buff[i] = buff[i + shift_by];
		i++;
	}
	ft_bzero(buff + i, BUFF_SIZE - i);
}

static void	buff_to_line(char **line, char *buff, size_t line_len, int copy_len)
{
	*line = ft_realloc(*line, line_len);
	ft_strncat(*line, buff, copy_len);
	if (copy_len < BUFF_SIZE)
	{
		shift_chars_left(buff, copy_len + 1);
		ft_bzero(buff + (BUFF_SIZE - copy_len + 1), copy_len + 1);
	}
	else
		ft_bzero(buff, BUFF_SIZE);
}

static int	prelim_checks(char **line, char *buff)
{
	char	*char_pos;
	int		line_length;

	if (line)
		ft_strclr(*line);
	char_pos = ft_strchr(buff, '\n');
	line_length = (char_pos) ? (char_pos - buff) : ft_strlen(buff);
	if (line_length)
		buff_to_line(line, buff, line_length, line_length);
	if (char_pos)
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	return (line_length);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			rv;
	int			line_length;
	int			cp_len;
	char		*char_pos;

	if ((line_length = prelim_checks(line, buff)) == -1)
		return (1);
 	if ((rv = read(fd, buff, BUFF_SIZE)) < 1)
 		return (rv);
	while (rv)
	{
		buff[BUFF_SIZE] = '\0';
		char_pos = ft_strchr(buff, '\n');
		cp_len = (char_pos) ? (char_pos - buff) : rv;
		line_length += cp_len;
		buff_to_line(line, buff, line_length, cp_len);
		if (char_pos || rv == 0)
			return (1);
		if ((rv = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rv == 0)
			return (1);
	}
	return (-1);
}
