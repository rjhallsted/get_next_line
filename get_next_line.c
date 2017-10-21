/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/21 13:58:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Current things to change:
** 1) run_copy shouldn't be necessary if data.buff is empty. Or it should fail,
** **or somtthinig like that. The code should check for the 'fullness' of buff
** **and handle correctly if it's empty
** 2) add support for multiple file descriptors
*/

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "get_next_line.h"

#include <stdio.h>

/*
** shift_chars_left assumes shift_by < BUFF_SIZE
*/

static void	shift_chars_left(t_data *data, int shift_by)
{
	int i;

	i = 0;
	while (data->buff[i] && data->buff[i + shift_by])
	{
		data->buff[i] = data->buff[i + shift_by];
		i++;
	}
	ft_bzero(data->buff + i, BUFF_SIZE - i);
}

static int	run_copy(char **line, t_data *data, int rv)
{
	char	*char_pos;
	int		copy_len;

	char_pos = ft_strchr(data->buff, '\n');
	copy_len = (char_pos) ? (char_pos - data->buff) : rv;
	data->line_len += copy_len;
	*line = ft_memrealloc(*line, data->line_len + 1);
	ft_strncat(*line, data->buff, copy_len);
	shift_chars_left(data, copy_len + 1);
	return ((char_pos != NULL));
}

int			get_next_line(const int fd, char **line)
{
	static t_data	data;
	int				rv;

	if (!(line))
		return (-1);
	*line = NULL;
	if (run_copy(line, &data, ft_strlen(data.buff)))
		return (1);
	if ((rv = read(fd, data.buff, BUFF_SIZE)) == -1
		|| (rv == 0 && ft_strlen(*line) == 0))
		return (rv);
	if (rv == 0 && ft_strlen(*line) > 0)
		return (1);
	while (rv)
	{
		if (run_copy(line, &data, rv))
			return (1);
		if ((rv = read(fd, data.buff, BUFF_SIZE)) == -1)
			return (-1);
		if (rv == 0)
			return (1);
	}
	return (0);
}
