/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/18 16:11:03 by rhallste         ###   ########.fr       */
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
	int shift_by;

	*line = ft_realloc(*line, line_len + 1);
	ft_strncat(*line, buff, copy_len);
	shift_by = (copy_len < BUFF_SIZE) ? copy_len + 1 : 0;
	shift_chars_left(buff, shift_by);
}

static int	prelim_checks(char **line, char *buff)
{
	char	*char_pos;
	int		line_length;

	if (line)
		ft_strclr(*line);
	char_pos = ft_strchr(buff, '\n');
	line_length = (char_pos) ? (char_pos - buff) : ft_strlen(buff);
	buff_to_line(line, buff, line_length, line_length);
	if (char_pos)
		return (-1);
	return (line_length);
}

/*
** run_copy normally returns the new line_length
** If done reading line, return (-1);
** ^^Done because the normal return value needs to be
** ^^positive, so we can't use normal success codes
*/

static int	run_copy(char **line, char *buff, int line_len, int rv)
{
	char	*char_pos;
	int		copy_len;

	char_pos = ft_strchr(buff, '\n');
	copy_len = (char_pos) ? (char_pos - buff) : rv;
	line_len += copy_len;
	buff_to_line(line, buff, line_len, copy_len);
	if (char_pos)
		return (-1);
	return (line_len);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			rv;
	int			line_len;

	if ((line_len = prelim_checks(line, buff)) == -1)
		return (1);
	if (((rv = read(fd, buff, BUFF_SIZE)) == 0 && ft_strlen(*line) == 0)
			|| rv == -1)
		return (rv);
	if (rv == 0 && ft_strlen(*line) > 0)
		return (1);
	while (rv)
	{
		if ((line_len = run_copy(line, buff, line_len, rv)) == -1
				|| rv == 0)
			return (1);
		if ((rv = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rv == 0)
			return (1);
	}
	return (-1);
}
